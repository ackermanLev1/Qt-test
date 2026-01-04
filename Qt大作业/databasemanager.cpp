#include "databasemanager.h"

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{
    // 连接 SQLite 数据库（数据库文件存放在程序运行目录下）
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("BookLendingSystem.db");

    // 打开数据库并创建表
    if (m_db.open()) {
        qDebug() << "数据库连接成功！";
        createTables();
    } else {
        qDebug() << "数据库连接失败：" << m_db.lastError().text();
    }
}

DatabaseManager::~DatabaseManager()
{
    if (m_db.isOpen()) {
        m_db.close();
    }
}

bool DatabaseManager::isConnected() const
{
    return m_db.isOpen();
}

// 创建数据表（首次运行时执行）
bool DatabaseManager::createTables()
{
    QSqlQuery query;

    // 1. 创建图书表
    QString createBookTable = R"(
        CREATE TABLE IF NOT EXISTS books (
            book_id INTEGER PRIMARY KEY AUTOINCREMENT,
            book_name TEXT NOT NULL,
            author TEXT NOT NULL,
            publisher TEXT,
            publish_date DATE,
            category TEXT,
            stock INTEGER DEFAULT 0
        )
    )";
    if (!query.exec(createBookTable)) {
        qDebug() << "创建图书表失败：" << query.lastError().text();
        return false;
    }

    // 2. 创建读者表
    QString createReaderTable = R"(
        CREATE TABLE IF NOT EXISTS readers (
            reader_id INTEGER PRIMARY KEY AUTOINCREMENT,
            reader_name TEXT NOT NULL,
            gender TEXT,
            phone TEXT,
            register_date DATE DEFAULT CURRENT_DATE
        )
    )";
    if (!query.exec(createReaderTable)) {
        qDebug() << "创建读者表失败：" << query.lastError().text();
        return false;
    }

    // 3. 创建借阅表
    QString createBorrowTable = R"(
        CREATE TABLE IF NOT EXISTS borrows (
            borrow_id INTEGER PRIMARY KEY AUTOINCREMENT,
            book_id INTEGER NOT NULL,
            reader_id INTEGER NOT NULL,
            borrow_date DATE DEFAULT CURRENT_DATE,
            return_date DATE,
            status INTEGER DEFAULT 0,
            FOREIGN KEY (book_id) REFERENCES books(book_id),
            FOREIGN KEY (reader_id) REFERENCES readers(reader_id)
        )
    )";
    if (!query.exec(createBorrowTable)) {
        qDebug() << "创建借阅表失败：" << query.lastError().text();
        return false;
    }

    return true;
}

// -------------------------- 图书表操作 --------------------------
bool DatabaseManager::addBook(const QString &name, const QString &author, const QString &publisher,
                             const QDate &publishDate, const QString &category, int stock)
{
    QSqlQuery query;
    query.prepare(R"(
        INSERT INTO books (book_name, author, publisher, publish_date, category, stock)
        VALUES (:name, :author, :publisher, :publishDate, :category, :stock)
    )");
    query.bindValue(":name", name);
    query.bindValue(":author", author);
    query.bindValue(":publisher", publisher);
    query.bindValue(":publishDate", publishDate);
    query.bindValue(":category", category);
    query.bindValue(":stock", stock);

    return query.exec();
}

bool DatabaseManager::deleteBook(int bookId)
{
    QSqlQuery query;
    query.prepare("DELETE FROM books WHERE book_id = :id");
    query.bindValue(":id", bookId);
    return query.exec();
}

bool DatabaseManager::updateBookStock(int bookId, int newStock)
{
    QSqlQuery query;
    query.prepare("UPDATE books SET stock = :stock WHERE book_id = :id");
    query.bindValue(":stock", newStock);
    query.bindValue(":id", bookId);
    return query.exec();
}

QSqlQueryModel* DatabaseManager::getBookList(const QString &keyword)
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sql = "SELECT book_id, book_name, author, publisher, publish_date, category, stock FROM books";
    if (!keyword.isEmpty()) {
        // 支持按书名、作者、分类搜索
        sql += QString(" WHERE book_name LIKE '%%1%' OR author LIKE '%%1%' OR category LIKE '%%1%'")
               .arg(keyword);
    }
    model->setQuery(sql, m_db); // 显式指定数据库连接

    // 设置列名（界面显示用）
    model->setHeaderData(0, Qt::Horizontal, "图书ID");
    model->setHeaderData(1, Qt::Horizontal, "图书名称");
    model->setHeaderData(2, Qt::Horizontal, "作者");
    model->setHeaderData(3, Qt::Horizontal, "出版社");
    model->setHeaderData(4, Qt::Horizontal, "出版日期");
    model->setHeaderData(5, Qt::Horizontal, "分类");
    model->setHeaderData(6, Qt::Horizontal, "库存");

    return model;
}

// -------------------------- 读者表操作 --------------------------
bool DatabaseManager::addReader(const QString &name, const QString &gender, const QString &phone)
{
    QSqlQuery query;
    query.prepare(R"(
        INSERT INTO readers (reader_name, gender, phone)
        VALUES (:name, :gender, :phone)
    )");
    query.bindValue(":name", name);
    query.bindValue(":gender", gender);
    query.bindValue(":phone", phone);
    return query.exec();
}

// 重载：int类型readerId
bool DatabaseManager::deleteReader(int readerId)
{
    QSqlQuery query;
    query.prepare("DELETE FROM readers WHERE reader_id = :readerId");
    query.bindValue(":readerId", readerId);

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}

// 重载：字符串类型readerId
bool DatabaseManager::deleteReader(const QString &readerId)
{
    return deleteReader(readerId.toInt()); // 转成int调用上面的重载
}

QString DatabaseManager::getLastError() const
{
    return m_lastError;
}

QSqlQueryModel* DatabaseManager::getReaderList(const QString &keyword)
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sql = "SELECT reader_id, reader_name, gender, phone, register_date FROM readers";
    if (!keyword.isEmpty()) {
        sql += QString(" WHERE reader_name LIKE '%%1%' OR phone LIKE '%%1%'")
               .arg(keyword);
    }
    model->setQuery(sql, m_db); // 显式指定数据库连接

    model->setHeaderData(0, Qt::Horizontal, "读者ID");
    model->setHeaderData(1, Qt::Horizontal, "读者姓名");
    model->setHeaderData(2, Qt::Horizontal, "性别");
    model->setHeaderData(3, Qt::Horizontal, "联系电话");
    model->setHeaderData(4, Qt::Horizontal, "注册日期");

    return model;
}

// -------------------------- 借阅表操作 --------------------------
bool DatabaseManager::borrowBook(int bookId, int readerId)
{
    // 1. 检查图书库存是否充足
    QSqlQuery query;
    query.prepare("SELECT stock FROM books WHERE book_id = :id");
    query.bindValue(":id", bookId);
    if (!query.exec() || !query.next()) {
        m_lastError = "图书不存在";
        qDebug() << "图书不存在：" << bookId;
        return false;
    }
    int stock = query.value(0).toInt();
    if (stock <= 0) {
        m_lastError = "图书库存不足";
        qDebug() << "图书库存不足：" << bookId;
        return false;
    }

    // 2. 新增借阅记录
    query.prepare(R"(
        INSERT INTO borrows (book_id, reader_id, borrow_date, status)
        VALUES (:bookId, :readerId, CURRENT_DATE, 0)
    )");
    query.bindValue(":bookId", bookId);
    query.bindValue(":readerId", readerId);
    if (!query.exec()) {
        m_lastError = query.lastError().text();
        qDebug() << "创建借阅记录失败：" << m_lastError;
        return false;
    }

    // 3. 库存减1
    return updateBookStock(bookId, stock - 1);
}

bool DatabaseManager::returnBook(int borrowId)
{
    // 1. 检查借阅记录是否存在且未归还
    QSqlQuery query;
    query.prepare("SELECT book_id FROM borrows WHERE borrow_id = :id AND status = 0");
    query.bindValue(":id", borrowId);
    if (!query.exec() || !query.next()) {
        m_lastError = "借阅记录不存在或已归还";
        qDebug() << m_lastError << borrowId;
        return false;
    }
    int bookId = query.value(0).toInt();

    // 2. 更新借阅记录（状态改为已还，设置归还日期）
    query.prepare(R"(
        UPDATE borrows SET status = 1, return_date = CURRENT_DATE
        WHERE borrow_id = :id
    )");
    query.bindValue(":id", borrowId);
    if (!query.exec()) {
        m_lastError = query.lastError().text();
        qDebug() << "更新借阅记录失败：" << m_lastError;
        return false;
    }

    // 3. 库存加1
    query.prepare("SELECT stock FROM books WHERE book_id = :id");
    query.bindValue(":id", bookId);
    if (!query.exec() || !query.next()) {
        m_lastError = "获取图书库存失败";
        return false;
    }
    int stock = query.value(0).toInt();
    return updateBookStock(bookId, stock + 1);
}

QSqlQueryModel* DatabaseManager::getBorrowList(int status)
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QString sql = R"(
        SELECT b.borrow_id, bk.book_name, r.reader_name, b.borrow_date, b.return_date,
               CASE b.status WHEN 0 THEN '未还' WHEN 1 THEN '已还' END AS status_text
        FROM borrows b
        JOIN books bk ON b.book_id = bk.book_id
        JOIN readers r ON b.reader_id = r.reader_id
    )";
    if (status != -1) {
        sql += QString(" WHERE b.status = %1").arg(status);
    }
    model->setQuery(sql, m_db); // 显式指定数据库连接

    model->setHeaderData(0, Qt::Horizontal, "借阅ID");
    model->setHeaderData(1, Qt::Horizontal, "图书名称");
    model->setHeaderData(2, Qt::Horizontal, "读者姓名");
    model->setHeaderData(3, Qt::Horizontal, "借阅日期");
    model->setHeaderData(4, Qt::Horizontal, "归还日期");
    model->setHeaderData(5, Qt::Horizontal, "状态");

    return model;
}
