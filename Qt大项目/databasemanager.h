#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QDateTime>
#include <QRandomGenerator>
#include <QMessageBox>

class DataBaseManager {
public:
    // 单例模式
    static DataBaseManager* getInstance();
    // 初始化数据库（创建表+测试数据）
    bool initDataBase();
    // 登录验证（返回：0-失败，1-读者，2-管理员；outUserId：输出用户ID）
    int loginVerify(const QString& username, const QString& pwd, QString& outUserId, bool& isUserExist);
    // 读者注册
    bool readerRegister(const QString& username, const QString& pwd, const QString& name, const QString& gender, const QString& phone, QString& outReaderId);
    // 图书管理接口
    QSqlQueryModel* getBookList(const QString& searchKey = "");
    bool addBook(const QString& bookId, const QString& name, const QString& author, const QString& publisher, const QString& publishDate, const QString& category, int stock);
    bool modifyBook(const QString& bookId, const QString& name, const QString& author, const QString& publisher, const QString& publishDate, const QString& category, int stock);
    bool deleteBook(const QString& bookId);
    // 读者管理接口
    QSqlQueryModel* getReaderList(const QString& searchKey = "");
    bool deleteReader(const QString& readerId);
    // 借阅管理接口
    QSqlQueryModel* getBorrowList(const QString& type = "all", const QString& readerId = "");
    bool borrowBook(const QString& bookId, const QString& readerId, int borrowDays);
    bool returnBook(const QString& borrowId);
    // 个人信息接口
    QSqlQuery getPersonalInfo(const QString& readerId);
    QString getReaderUsername(const QString& readerId);
    bool modifyPwd(const QString& userId, const QString& newPwd, bool isAdmin = false);
    bool modifyPersonalInfo(const QString& readerId, const QString& name, const QString& gender, const QString& phone);
    // 逾期检查
    QString checkOverdue(const QString& readerId);

private:
    DataBaseManager();
    ~DataBaseManager();
    QSqlDatabase db;
    static DataBaseManager* instance;
    // 生成随机ID
    QString generateBookId();    // 图书ID：BK+6位字母数字
    QString generateReaderId();  // 读者ID：1位数字+4位字母
};

#endif // DATABASEMANAGER_H
