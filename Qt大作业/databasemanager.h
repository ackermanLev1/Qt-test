#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>
#include <QDebug>
#include <QSqlQueryModel>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();

    // 数据库连接状态
    bool isConnected() const;

    // 图书表操作
    bool addBook(const QString &name, const QString &author, const QString &publisher,
                 const QDate &publishDate, const QString &category, int stock);
    bool deleteBook(int bookId);
    bool updateBookStock(int bookId, int newStock);
    QSqlQueryModel* getBookList(const QString &keyword = ""); // 支持搜索

    // 读者表操作
    bool addReader(const QString &name, const QString &gender, const QString &phone);
    bool deleteReader(int readerId); // 重载：int类型ID
    bool deleteReader(const QString &readerId); // 重载：字符串类型ID
    QSqlQueryModel* getReaderList(const QString &keyword = "");
    QString getLastError() const; // 获取最后一次错误信息

    // 借阅表操作
    bool borrowBook(int bookId, int readerId); // 借阅（库存-1，新增记录）
    bool returnBook(int borrowId); // 归还（库存+1，更新状态和归还日期）
    QSqlQueryModel* getBorrowList(int status = -1); // 按状态筛选（-1=全部）

private:
    QSqlDatabase m_db;
    QString m_lastError; // 新增：存储最后一次错误信息
    bool createTables(); // 创建数据表
};

#endif // DATABASEMANAGER_H
