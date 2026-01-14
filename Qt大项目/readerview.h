#ifndef READERVIEW_H
#define READERVIEW_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class ReaderView;
}

class ReaderView : public QWidget {
    Q_OBJECT

public:
    explicit ReaderView(const QString& readerId, QWidget *parent = nullptr);
    ~ReaderView();

signals:
    void logout();

private slots:
    void on_btnPersonalInfo_clicked();
    void on_btnBookBorrow_clicked();
    void on_btnBorrowQuery_clicked();
    void on_btnReaderExit_clicked();
    void on_btnModifyPwd_clicked();
    void on_btnModifyInfo_clicked();
    void on_btnSearchBookReader_clicked();
    void on_btnBorrowBook_clicked();
    void on_btnReturnBook_clicked();
    void on_btnReaderAll_clicked();
    void on_btnReaderUnreturn_clicked();
    void on_btnReaderReturned_clicked();
    void on_btnReaderRefresh_clicked();

private:
    Ui::ReaderView *ui;
    QString readerId;
    QSqlQueryModel* bookBorrowModel;
    QSqlQueryModel* borrowQueryModel;
    // 修改密码对话框
    QDialog* pwdDialog;
    QLineEdit* leOldPwd;
    QLineEdit* leNewPwd;
    QLineEdit* leConfirmPwd;
    QPushButton* btnPwdOk;
    QPushButton* btnPwdCancel;
    // 修改个人信息对话框
    QDialog* infoDialog;
    QLineEdit* leInfoName;
    QLineEdit* leInfoGender;
    QLineEdit* leInfoPhone;
    QPushButton* btnInfoOk;
    QPushButton* btnInfoCancel;

    void initBookBorrowModel(const QString& searchKey = "");
    void initBorrowQueryModel(const QString& type = "all");
    void updatePersonalInfo();
};

#endif // READERVIEW_H
