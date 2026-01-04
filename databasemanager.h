#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QDebug>
#include <QDate>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    // 单例模式
    static DatabaseManager* instance();
    ~DatabaseManager();

    // 数据库连接状态
    bool isConnected() const;

    // 图书相关操作
    QSqlQueryModel* getBookListModel(); // 获取图书列表（Model/View用）
    bool addBook(const QString& bookName, const QString& author, const QString& publisher,
                 const QDate& publishDate, const QString& category, int totalCount,
                 const QString& location); // 添加图书
    bool updateBook(int bookId, const QString& bookName, const QString& author, const QString& publisher,
                    const QDate& publishDate, const QString& category, int totalCount,
                    const QString& location); // 修改图书
    bool deleteBook(int bookId); // 删除图书
    bool borrowBook(int bookId, const QString& readerId); // 借阅图书
    bool returnBook(int borrowId); // 归还图书
    QSqlQueryModel* getBorrowListModel(const QString& readerId = ""); // 获取借阅记录

private:
    explicit DatabaseManager(QObject *parent = nullptr);
    static DatabaseManager* m_instance; // 单例实例
    QSqlDatabase m_db; // 数据库连接

    // 初始化数据库
    bool initDatabase();
};

#endif // DATABASEMANAGER_H
