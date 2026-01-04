#include "databasemanager.h"

DatabaseManager* DatabaseManager::m_instance = nullptr;

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{
    initDatabase();
}

DatabaseManager* DatabaseManager::instance()
{
    if (!m_instance) {
        m_instance = new DatabaseManager();
    }
    return m_instance;
}

DatabaseManager::~DatabaseManager()
{
    if (m_db.isOpen()) {
        m_db.close();
    }
}

bool DatabaseManager::initDatabase()
{
    // 加载SQLite驱动
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    // 数据库文件路径（与Navicat创建的路径一致！！！必须修改为你的路径）
    m_db.setDatabaseName("D:/QtProjects/LibrarySystem/library.db");

    // 打开数据库
    if (!m_db.open()) {
        qDebug() << "数据库连接失败：" << m_db.lastError().text();
        return false;
    }
    qDebug() << "数据库连接成功！";
    return true;
}

bool DatabaseManager::isConnected() const
{
    return m_db.isOpen();
}

QSqlQueryModel* DatabaseManager::getBookListModel()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString sql = "SELECT book_id, book_name, author, publisher, publish_date, category, total_count, available_count, location FROM books";
    model->setQuery(sql, m_db);

    // 设置列名（用于View显示）
    model->setHeaderData(0, Qt::Horizontal, "图书ID");
    model->setHeaderData(1, Qt::Horizontal, "图书名称");
    model->setHeaderData(2, Qt::Horizontal, "作者");
    model->setHeaderData(3, Qt::Horizontal, "出版社");
    model->setHeaderData(4, Qt::Horizontal, "出版日期");
    model->setHeaderData(5, Qt::Horizontal, "分类");
    model->setHeaderData(6, Qt::Horizontal, "总藏书量");
    model->setHeaderData(7, Qt::Horizontal, "可借数量");
    model->setHeaderData(8, Qt::Horizontal, "书架位置");

    if (model->lastError().isValid()) {
        qDebug() << "查询图书列表失败：" << model->lastError().text();
    }
    return model;
}

bool DatabaseManager::addBook(const QString &bookName, const QString &author, const QString &publisher, const QDate &publishDate, const QString &category, int totalCount, const QString &location)
{
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO books (book_name, author, publisher, publish_date, category, total_count, available_count, location) "
                  "VALUES (:bookName, :author, :publisher, :publishDate, :category, :totalCount, :availableCount, :location)");

    // 绑定参数
    query.bindValue(":bookName", bookName);
    query.bindValue(":author", author);
    query.bindValue(":publisher", publisher);
    query.bindValue(":publishDate", publishDate);
    query.bindValue(":category", category);
    query.bindValue(":totalCount", totalCount);
    query.bindValue(":availableCount", totalCount); // 新增图书可借数量=总藏书量
    query.bindValue(":location", location);

    if (!query.exec()) {
        qDebug() << "添加图书失败：" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::updateBook(int bookId, const QString &bookName, const QString &author, const QString &publisher, const QDate &publishDate, const QString &category, int totalCount, const QString &location)
{
    QSqlQuery query(m_db);
    query.prepare("UPDATE books SET book_name=:bookName, author=:author, publisher=:publisher, "
                  "publish_date=:publishDate, category=:category, total_count=:totalCount, "
                  "available_count=:availableCount, location=:location WHERE book_id=:bookId");

    // 计算可借数量（保持原有可借数量不超过总藏书量）
    QSqlQuery tempQuery(m_db);
    tempQuery.prepare("SELECT available_count FROM books WHERE book_id=:bookId");
    tempQuery.bindValue(":bookId", bookId);
    tempQuery.exec();
    tempQuery.next();
    int currentAvailable = tempQuery.value(0).toInt();
    int newAvailable = qMin(currentAvailable, totalCount);

    // 绑定参数
    query.bindValue(":bookName", bookName);
    query.bindValue(":author", author);
    query.bindValue(":publisher", publisher);
    query.bindValue(":publishDate", publishDate);
    query.bindValue(":category", category);
    query.bindValue(":totalCount", totalCount);
    query.bindValue(":availableCount", newAvailable);
    query.bindValue(":location", location);
    query.bindValue(":bookId", bookId);

    if (!query.exec()) {
        qDebug() << "修改图书失败：" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::deleteBook(int bookId)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM books WHERE book_id=:bookId");
    query.bindValue(":bookId", bookId);

    if (!query.exec()) {
        qDebug() << "删除图书失败：" << query.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::borrowBook(int bookId, const QString &readerId)
{
    // 事务：确保借阅和可借数量更新原子性
    m_db.transaction();

    // 1. 检查图书是否可借
    QSqlQuery checkQuery(m_db);
    checkQuery.prepare("SELECT available_count FROM books WHERE book_id=:bookId");
    checkQuery.bindValue(":bookId", bookId);
    if (!checkQuery.exec() || !checkQuery.next()) {
        qDebug() << "查询图书可借数量失败：" << checkQuery.lastError().text();
        m_db.rollback();
        return false;
    }

    int availableCount = checkQuery.value(0).toInt();
    if (availableCount <= 0) {
        qDebug() << "图书已无库存，无法借阅！";
        m_db.rollback();
        return false;
    }

    // 2. 插入借阅记录
    QSqlQuery borrowQuery(m_db);
    borrowQuery.prepare("INSERT INTO borrows (book_id, reader_id) VALUES (:bookId, :readerId)");
    borrowQuery.bindValue(":bookId", bookId);
    borrowQuery.bindValue(":readerId", readerId);
    if (!borrowQuery.exec()) {
        qDebug() << "插入借阅记录失败：" << borrowQuery.lastError().text();
        m_db.rollback();
        return false;
    }

    // 3. 减少可借数量
    QSqlQuery updateQuery(m_db);
    updateQuery.prepare("UPDATE books SET available_count=available_count-1 WHERE book_id=:bookId");
    updateQuery.bindValue(":bookId", bookId);
    if (!updateQuery.exec()) {
        qDebug() << "更新可借数量失败：" << updateQuery.lastError().text();
        m_db.rollback();
        return false;
    }

    // 提交事务
    m_db.commit();
    return true;
}

bool DatabaseManager::returnBook(int borrowId)
{
    m_db.transaction();

    // 1. 获取借阅记录中的book_id
    QSqlQuery getBookIdQuery(m_db);
    getBookIdQuery.prepare("SELECT book_id FROM borrows WHERE borrow_id=:borrowId AND return_date IS NULL");
    getBookIdQuery.bindValue(":borrowId", borrowId);
    if (!getBookIdQuery.exec() || !getBookIdQuery.next()) {
        qDebug() << "查询借阅记录失败：" << getBookIdQuery.lastError().text();
        m_db.rollback();
        return false;
    }
    int bookId = getBookIdQuery.value(0).toInt();

    // 2. 更新归还日期
    QSqlQuery returnQuery(m_db);
    returnQuery.prepare("UPDATE borrows SET return_date=CURRENT_TIMESTAMP WHERE borrow_id=:borrowId");
    returnQuery.bindValue(":borrowId", borrowId);
    if (!returnQuery.exec()) {
        qDebug() << "更新归还日期失败：" << returnQuery.lastError().text();
        m_db.rollback();
        return false;
    }

    // 3. 增加可借数量
    QSqlQuery updateQuery(m_db);
    updateQuery.prepare("UPDATE books SET available_count=available_count+1 WHERE book_id=:bookId");
    updateQuery.bindValue(":bookId", bookId);
    if (!updateQuery.exec()) {
        qDebug() << "更新可借数量失败：" << updateQuery.lastError().text();
        m_db.rollback();
        return false;
    }

    m_db.commit();
    return true;
}

QSqlQueryModel* DatabaseManager::getBorrowListModel(const QString &readerId)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString sql;
    if (readerId.isEmpty()) {
        // 查询所有借阅记录（关联图书名称）
        sql = "SELECT b.borrow_id, b.book_id, bo.book_name, b.reader_id, b.borrow_date, b.return_date, b.overdue_days "
              "FROM borrows b LEFT JOIN books bo ON b.book_id=bo.book_id";
    } else {
        // 按读者ID查询
        sql = QString("SELECT b.borrow_id, b.book_id, bo.book_name, b.reader_id, b.borrow_date, b.return_date, b.overdue_days "
                      "FROM borrows b LEFT JOIN books bo ON b.book_id=bo.book_id WHERE b.reader_id='%1'").arg(readerId);
    }

    model->setQuery(sql, m_db);
    // 设置列名
    model->setHeaderData(0, Qt::Horizontal, "记录ID");
    model->setHeaderData(1, Qt::Horizontal, "图书ID");
    model->setHeaderData(2, Qt::Horizontal, "图书名称");
    model->setHeaderData(3, Qt::Horizontal, "读者ID");
    model->setHeaderData(4, Qt::Horizontal, "借阅日期");
    model->setHeaderData(5, Qt::Horizontal, "归还日期");
    model->setHeaderData(6, Qt::Horizontal, "逾期天数");

    if (model->lastError().isValid()) {
        qDebug() << "查询借阅记录失败：" << model->lastError().text();
    }
    return model;
}
