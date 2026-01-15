#include "databasemanager.h"

DataBaseManager* DataBaseManager::instance = nullptr;

DataBaseManager* DataBaseManager::getInstance() {
    if (!instance) {
        instance = new DataBaseManager();
    }
    return instance;
}

DataBaseManager::DataBaseManager() {
    // 初始化SQLite数据库
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./bin/bookLendingSystem.db");  // 数据库放在bin目录（与可执行文件同目录）
}

DataBaseManager::~DataBaseManager() {
    if (db.isOpen()) {
        db.close();
    }
    delete instance;
    instance = nullptr;
}

bool DataBaseManager::initDataBase() {
    if (!db.open()) {
        qDebug() << "数据库打开失败：" << db.lastError().text();
        QMessageBox::critical(nullptr, "错误", "数据库打开失败：" + db.lastError().text());
        return false;
    }

    QSqlQuery query;
    // 1. 创建管理员表
    QString createAdminTable = R"(
        CREATE TABLE IF NOT EXISTS user_Admin (
            adminId TEXT PRIMARY KEY,
            username TEXT UNIQUE NOT NULL,
            pwd TEXT NOT NULL
        )
    )";
    if (!query.exec(createAdminTable)) {
        qDebug() << "创建管理员表失败：" << query.lastError().text();
        return false;
    }

    // 2. 创建读者表
    QString createReaderTable = R"(
        CREATE TABLE IF NOT EXISTS user_Reader (
            readerId TEXT PRIMARY KEY,
            username TEXT UNIQUE NOT NULL,
            pwd TEXT NOT NULL,
            name TEXT NOT NULL,
            gender TEXT NOT NULL,
            phone TEXT NOT NULL,
            registerTime TEXT NOT NULL
        )
    )";
    if (!query.exec(createReaderTable)) {
        qDebug() << "创建读者表失败：" << query.lastError().text();
        return false;
    }

    // 3. 创建图书表
    QString createBookTable = R"(
        CREATE TABLE IF NOT EXISTS book (
            bookId TEXT PRIMARY KEY,
            name TEXT NOT NULL,
            author TEXT NOT NULL,
            publisher TEXT,
            publishDate TEXT,
            category TEXT,
            stock INT NOT NULL DEFAULT 0
        )
    )";
    if (!query.exec(createBookTable)) {
        qDebug() << "创建图书表失败：" << query.lastError().text();
        return false;
    }

    // 4. 创建借阅表
    QString createBorrowTable = R"(
        CREATE TABLE IF NOT EXISTS borrow (
            borrowId INTEGER PRIMARY KEY AUTOINCREMENT,
            bookId TEXT NOT NULL,
            readerId TEXT NOT NULL,
            borrowDate TEXT NOT NULL,
            returnDate TEXT,
            borrowDays INT NOT NULL,
            status TEXT NOT NULL DEFAULT '未还',
            FOREIGN KEY(bookId) REFERENCES book(bookId),
            FOREIGN KEY(readerId) REFERENCES user_Reader(readerId)
        )
    )";
    if (!query.exec(createBorrowTable)) {
        qDebug() << "创建借阅表失败：" << query.lastError().text();
        return false;
    }

    // 插入默认管理员（admin/123）
    query.exec("SELECT * FROM user_Admin WHERE username='admin'");
    if (!query.next()) {
        QString insertAdmin = "INSERT INTO user_Admin (adminId, username, pwd) VALUES ('AD001', 'admin', '123')";
        if (!query.exec(insertAdmin)) {
            qDebug() << "插入管理员失败：" << query.lastError().text();
        }
    }

    // 插入3个测试读者
    query.exec("SELECT COUNT(*) FROM user_Reader");
    if (query.next() && query.value(0).toInt() < 3) {
        QString readers[] = {
            "('" + generateReaderId() + "', 'reader1', '123', '张三', '男', '13800138001', '" + QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + "')",
            "('" + generateReaderId() + "', 'reader2', '123', '李四', '女', '13900139002', '" + QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + "')",
            "('" + generateReaderId() + "', 'reader3', '123', '王五', '男', '13700137003', '" + QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") + "')"
        };
        for (auto& reader : readers) {
            QString sql = "INSERT INTO user_Reader (readerId, username, pwd, name, gender, phone, registerTime) VALUES " + reader;
            query.exec(sql);
        }
    }

    // 插入20本测试图书
    query.exec("SELECT COUNT(*) FROM book");
    if (query.next() && query.value(0).toInt() < 20) {
        QString books[] = {
            "('BK" + generateBookId() + "', 'C++ Primer', 'Stanley B. Lippman', '人民邮电出版社', '2021-01-15', '编程', 10)",
            "('BK" + generateBookId() + "', 'Qt 5.15 开发实战', '霍亚飞', '机械工业出版社', '2022-03-20', '编程', 8)",
            "('BK" + generateBookId() + "', '数据结构与算法分析', 'Mark Allen Weiss', '清华大学出版社', '2020-11-05', '计算机', 5)",
            "('BK" + generateBookId() + "', '深入理解计算机系统', 'Randal E. Bryant', '机械工业出版社', '2019-08-10', '计算机', 7)",
            "('BK" + generateBookId() + "', 'Python编程：从入门到实践', 'Eric Matthes', '人民邮电出版社', '2021-05-18', '编程', 12)",
            "('BK" + generateBookId() + "', '机器学习实战', 'Peter Harrington', '人民邮电出版社', '2020-07-22', '人工智能', 6)",
            "('BK" + generateBookId() + "', '深度学习', 'Ian Goodfellow', '人民邮电出版社', '2018-01-30', '人工智能', 4)",
            "('BK" + generateBookId() + "', '数据库系统概念', 'Abraham Silberschatz', '机械工业出版社', '2019-03-15', '数据库', 9)",
            "('BK" + generateBookId() + "', '操作系统导论', 'Remzi H. Arpaci-Dusseau', '人民邮电出版社', '2021-09-01', '计算机', 3)",
            "('BK" + generateBookId() + "', '网络编程实战', '游双', '机械工业出版社', '2022-01-10', '编程', 8)",
            "('BK" + generateBookId() + "', '算法图解', 'Aditya Bhargava', '人民邮电出版社', '2019-06-25', '算法', 11)",
            "('BK" + generateBookId() + "', '设计模式：可复用面向对象软件的基础', 'Erich Gamma', '机械工业出版社', '2020-02-18', '编程', 5)",
            "('BK" + generateBookId() + "', '计算机网络', 'Andrew S. Tanenbaum', '清华大学出版社', '2018-11-08', '计算机', 6)",
            "('BK" + generateBookId() + "', 'Java编程思想', 'Bruce Eckel', '机械工业出版社', '2019-05-20', '编程', 4)",
            "('BK" + generateBookId() + "', '机器学习基石', 'Hastie Trevor', '清华大学出版社', '2021-03-12', '人工智能', 7)",
            "('BK" + generateBookId() + "', '数据分析实战', 'Peter Bruce', '人民邮电出版社', '2020-08-30', '数据处理', 9)",
            "('BK" + generateBookId() + "', 'Python数据分析', 'Wes McKinney', '人民邮电出版社', '2019-07-15', '数据处理', 10)",
            "('BK" + generateBookId() + "', 'Web开发实战', 'Matt Frisbie', '机械工业出版社', '2022-04-05', '编程', 6)",
            "('BK" + generateBookId() + "', '移动应用开发', 'Y. Daniel Liang', '清华大学出版社', '2021-01-22', '编程', 3)",
            "('BK" + generateBookId() + "', '云计算导论', 'Michael Miller', '人民邮电出版社', '2020-09-18', '计算机', 8)"
        };
        for (auto& book : books) {
            QString sql = "INSERT INTO book (bookId, name, author, publisher, publishDate, category, stock) VALUES " + book;
            query.exec(sql);
        }
    }

    qDebug() << "数据库初始化成功";
    return true;
}

int DataBaseManager::loginVerify(const QString& username, const QString& pwd, QString& outUserId, bool& isUserExist) {
    QSqlQuery query;
    isUserExist = false;

    // 1. 验证管理员
    query.prepare("SELECT adminId FROM user_Admin WHERE username=?");
    query.addBindValue(username);
    if (query.exec() && query.next()) {
        isUserExist = true;
        // 验证密码
        query.prepare("SELECT adminId FROM user_Admin WHERE username=? AND pwd=?");
        query.addBindValue(username);
        query.addBindValue(pwd);
        if (query.exec() && query.next()) {
            outUserId = query.value("adminId").toString();
            return 2; // 管理员登录成功
        }
        return 0; // 管理员密码错误
    }

    // 2. 验证读者
    query.prepare("SELECT readerId FROM user_Reader WHERE username=?");
    query.addBindValue(username);
    if (query.exec() && query.next()) {
        isUserExist = true;
        outUserId = query.value("readerId").toString();
        // 验证密码
        query.prepare("SELECT readerId FROM user_Reader WHERE username=? AND pwd=?");
        query.addBindValue(username);
        query.addBindValue(pwd);
        if (query.exec() && query.next()) {
            return 1; // 读者登录成功
        }
        return 0; // 读者密码错误
    }

    return 0; // 用户不存在
}

bool DataBaseManager::readerRegister(const QString& username, const QString& pwd, const QString& name, const QString& gender, const QString& phone, QString& outReaderId) {
    QSqlQuery query;
    // 检查用户名是否存在
    query.prepare("SELECT * FROM user_Reader WHERE username=?");
    query.addBindValue(username);
    if (query.exec() && query.next()) {
        return false; // 用户名已存在
    }

    // 生成读者ID和注册时间
    outReaderId = generateReaderId();
    QString registerTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    // 插入读者数据
    query.prepare("INSERT INTO user_Reader (readerId, username, pwd, name, gender, phone, registerTime) VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(outReaderId);
    query.addBindValue(username);
    query.addBindValue(pwd);
    query.addBindValue(name);
    query.addBindValue(gender);
    query.addBindValue(phone);
    query.addBindValue(registerTime);

    return query.exec();
}

QSqlQueryModel* DataBaseManager::getBookList(const QString& searchKey) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString sql = "SELECT bookId, name, author, publisher, publishDate, category, stock FROM book";
    if (!searchKey.isEmpty()) {
        sql += QString(" WHERE bookId LIKE '%%1%' OR name LIKE '%%1%'").arg(searchKey);
    }
    model->setQuery(sql);
    // 设置列名
    model->setHeaderData(0, Qt::Horizontal, "图书ID");
    model->setHeaderData(1, Qt::Horizontal, "图书名称");
    model->setHeaderData(2, Qt::Horizontal, "作者");
    model->setHeaderData(3, Qt::Horizontal, "出版社");
    model->setHeaderData(4, Qt::Horizontal, "出版日期");
    model->setHeaderData(5, Qt::Horizontal, "分类");
    model->setHeaderData(6, Qt::Horizontal, "库存");
    return model;
}

bool DataBaseManager::addBook(const QString& bookId, const QString& name, const QString& author, const QString& publisher, const QString& publishDate, const QString& category, int stock) {
    QSqlQuery query;
    // 检查图书ID是否存在
    query.prepare("SELECT * FROM book WHERE bookId=?");
    query.addBindValue(bookId);
    if (query.exec() && query.next()) {
        return false; // 图书ID已存在
    }

    query.prepare("INSERT INTO book (bookId, name, author, publisher, publishDate, category, stock) VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(bookId);
    query.addBindValue(name);
    query.addBindValue(author);
    query.addBindValue(publisher);
    query.addBindValue(publishDate);
    query.addBindValue(category);
    query.addBindValue(stock);

    return query.exec();
}

bool DataBaseManager::modifyBook(const QString& bookId, const QString& name, const QString& author, const QString& publisher, const QString& publishDate, const QString& category, int stock) {
    QSqlQuery query;
    query.prepare("UPDATE book SET name=?, author=?, publisher=?, publishDate=?, category=?, stock=? WHERE bookId=?");
    query.addBindValue(name);
    query.addBindValue(author);
    query.addBindValue(publisher);
    query.addBindValue(publishDate);
    query.addBindValue(category);
    query.addBindValue(stock);
    query.addBindValue(bookId);

    return query.exec() && query.numRowsAffected() > 0;
}

bool DataBaseManager::deleteBook(const QString& bookId) {
    QSqlQuery query;
    // 检查是否有未还借阅记录
    query.prepare("SELECT * FROM borrow WHERE bookId=? AND status='未还'");
    query.addBindValue(bookId);
    if (query.exec() && query.next()) {
        return false; // 存在未还记录，无法删除
    }

    query.prepare("DELETE FROM book WHERE bookId=?");
    query.addBindValue(bookId);
    return query.exec() && query.numRowsAffected() > 0;
}

QSqlQueryModel* DataBaseManager::getReaderList(const QString& searchKey) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString sql = "SELECT readerId, name, gender, phone, registerTime FROM user_Reader";
    if (!searchKey.isEmpty()) {
        sql += QString(" WHERE readerId LIKE '%%1%' OR name LIKE '%%1%'").arg(searchKey);
    }
    model->setQuery(sql);
    model->setHeaderData(0, Qt::Horizontal, "读者ID");
    model->setHeaderData(1, Qt::Horizontal, "读者姓名");
    model->setHeaderData(2, Qt::Horizontal, "性别");
    model->setHeaderData(3, Qt::Horizontal, "联系电话");
    model->setHeaderData(4, Qt::Horizontal, "注册日期");
    return model;
}

bool DataBaseManager::deleteReader(const QString& readerId) {
    QSqlQuery query;
    // 检查是否有未还借阅记录
    query.prepare("SELECT * FROM borrow WHERE readerId=? AND status='未还'");
    query.addBindValue(readerId);
    if (query.exec() && query.next()) {
        return false; // 存在未还记录，无法删除
    }

    query.prepare("DELETE FROM user_Reader WHERE readerId=?");
    query.addBindValue(readerId);
    return query.exec() && query.numRowsAffected() > 0;
}

QSqlQueryModel* DataBaseManager::getBorrowList(const QString& type, const QString& readerId) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString sql = R"(
        SELECT b.borrowId, bo.name, r.name, b.borrowDate, b.returnDate, b.borrowDays, b.status
        FROM borrow b
        JOIN book bo ON b.bookId=bo.bookId
        JOIN user_Reader r ON b.readerId=r.readerId
    )";

    // 筛选借阅状态
    if (type == "unreturned") {
        sql += " WHERE b.status='未还'";
    } else if (type == "returned") {
        sql += " WHERE b.status='已还'";
    }

    // 筛选读者（仅读者查询时用）
    if (!readerId.isEmpty()) {
        sql += (type == "all" ? " WHERE" : " AND") + QString(" b.readerId='%1'").arg(readerId);
    }

    model->setQuery(sql);
    model->setHeaderData(0, Qt::Horizontal, "借阅ID");
    model->setHeaderData(1, Qt::Horizontal, "图书名称");
    model->setHeaderData(2, Qt::Horizontal, "读者姓名");
    model->setHeaderData(3, Qt::Horizontal, "借阅日期");
    model->setHeaderData(4, Qt::Horizontal, "归还日期");
    model->setHeaderData(5, Qt::Horizontal, "借阅天数");
    model->setHeaderData(6, Qt::Horizontal, "状态");
    return model;
}

bool DataBaseManager::borrowBook(const QString& bookId, const QString& readerId, int borrowDays) {
    QSqlQuery query;
    // 开启事务（确保库存修改与借阅记录插入原子性）
    db.transaction();

    // 1. 检查图书库存
    query.prepare("SELECT stock FROM book WHERE bookId=?");
    query.addBindValue(bookId);
    if (!query.exec() || !query.next() || query.value("stock").toInt() <= 0) {
        db.rollback();
        return false; // 库存不足
    }

    // 2. 检查是否已借阅该图书（未还）
    query.prepare("SELECT * FROM borrow WHERE bookId=? AND readerId=? AND status='未还'");
    query.addBindValue(bookId);
    query.addBindValue(readerId);
    if (query.exec() && query.next()) {
        db.rollback();
        return false; // 已借阅未还
    }

    // 3. 插入借阅记录
    QString borrowDate = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    query.prepare("INSERT INTO borrow (bookId, readerId, borrowDate, borrowDays, status) VALUES (?, ?, ?, ?, '未还')");
    query.addBindValue(bookId);
    query.addBindValue(readerId);
    query.addBindValue(borrowDate);
    query.addBindValue(borrowDays);
    if (!query.exec()) {
        db.rollback();
        return false;
    }

    // 4. 库存减1
    query.prepare("UPDATE book SET stock=stock-1 WHERE bookId=?");
    query.addBindValue(bookId);
    if (!query.exec()) {
        db.rollback();
        return false;
    }

    // 提交事务
    db.commit();
    return true;
}

bool DataBaseManager::returnBook(const QString& borrowId) {
    QSqlQuery query;
    db.transaction();

    // 1. 检查借阅记录是否存在且未还
    query.prepare("SELECT bookId FROM borrow WHERE borrowId=? AND status='未还'");
    query.addBindValue(borrowId);
    if (!query.exec() || !query.next()) {
        db.rollback();
        return false;
    }
    QString bookId = query.value("bookId").toString();

    // 2. 更新借阅状态和归还日期
    QString returnDate = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    query.prepare("UPDATE borrow SET status='已还', returnDate=? WHERE borrowId=?");
    query.addBindValue(returnDate);
    query.addBindValue(borrowId);
    if (!query.exec()) {
        db.rollback();
        return false;
    }

    // 3. 库存加1
    query.prepare("UPDATE book SET stock=stock+1 WHERE bookId=?");
    query.addBindValue(bookId);
    if (!query.exec()) {
        db.rollback();
        return false;
    }

    db.commit();
    return true;
}

QSqlQuery DataBaseManager::getPersonalInfo(const QString& readerId) {
    QSqlQuery query;
    query.prepare("SELECT name, gender, phone, registerTime FROM user_Reader WHERE readerId=?");
    query.addBindValue(readerId);
    query.exec();
    return query;
}

bool DataBaseManager::modifyPwd(const QString& userId, const QString& newPwd, bool isAdmin) {
    QSqlQuery query;
    QString table = isAdmin ? "user_Admin" : "user_Reader";
    QString idCol = isAdmin ? "adminId" : "readerId";

    query.prepare(QString("UPDATE %1 SET pwd=? WHERE %2=?").arg(table).arg(idCol));
    query.addBindValue(newPwd);
    query.addBindValue(userId);

    return query.exec() && query.numRowsAffected() > 0;
}

bool DataBaseManager::modifyPersonalInfo(const QString& readerId, const QString& name, const QString& gender, const QString& phone) {
    QSqlQuery query;
    query.prepare("UPDATE user_Reader SET name=?, gender=?, phone=? WHERE readerId=?");
    query.addBindValue(name);
    query.addBindValue(gender);
    query.addBindValue(phone);
    query.addBindValue(readerId);

    return query.exec() && query.numRowsAffected() > 0;
}

QString DataBaseManager::checkOverdue(const QString& readerId) {
    QSqlQuery query;
    QString sql = R"(
        SELECT bo.name, b.borrowDate, b.borrowDays
        FROM borrow b
        JOIN book bo ON b.bookId=bo.bookId
        WHERE b.readerId=? AND b.status='未还'
    )";
    query.prepare(sql);
    query.addBindValue(readerId);
    query.exec();

    QString overdueBooks;
    while (query.next()) {
        QString borrowDate = query.value("borrowDate").toString();
        int borrowDays = query.value("borrowDays").toInt();
        QDateTime borrowDt = QDateTime::fromString(borrowDate, "yyyy-MM-dd HH:mm:ss");
        QDateTime dueDt = borrowDt.addDays(borrowDays);

        if (QDateTime::currentDateTime() > dueDt) {
            int overdueDays = dueDt.daysTo(QDateTime::currentDateTime());
            overdueBooks += query.value("name").toString() + "（逾期" + QString::number(overdueDays) + "天）\n";
        }
    }
    return overdueBooks;
}

QString DataBaseManager::generateBookId() {
    QString chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    QString id;
    for (int i = 0; i < 6; ++i) {
        id += chars.at(QRandomGenerator::global()->bounded(chars.length()));
    }
    return id;
}

QString DataBaseManager::generateReaderId() {
    QString digits = "0123456789";
    QString letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString id;
    // 1位数字
    id += digits.at(QRandomGenerator::global()->bounded(digits.length()));
    // 4位字母
    for (int i = 0; i < 4; ++i) {
        id += letters.at(QRandomGenerator::global()->bounded(letters.length()));
    }
    return id;
}
