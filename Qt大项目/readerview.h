#ifndef READERVIEW_H
#define READERVIEW_H
#include <QWidget>
#include <QSqlQueryModel>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QHeaderView>
#include "databasemanager.h"

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
    void on_btnSearchBookReader_clicked();
    void on_btnBorrowBook_clicked();
    void on_btnReturnBook_clicked();
    void on_cbxStatus_currentTextChanged(const QString &text);
    void on_btnModifyInfo_clicked();

private:
    Ui::ReaderView *ui;
    QString readerId;
    QSqlQueryModel* bookBorrowModel;
    QSqlQueryModel* borrowQueryModel;
    QDialog* pwdDialog;
    QDialog* infoDialog;

    // 密码对话框控件
    QLineEdit* leOldPwd;
    QLineEdit* leNewPwd;
    QLineEdit* leConfirmPwd;
    QPushButton* btnPwdOk;
    QPushButton* btnPwdCancel;

    // 信息对话框控件
    QLineEdit* leInfoName;
    QLineEdit* leInfoGender;
    QLineEdit* leInfoPhone;
    QPushButton* btnInfoOk;
    QPushButton* btnInfoCancel;

    void initBookBorrowModel(const QString& searchKey = "");
    void initBorrowQueryModel(const QString& type = "all");
    void updatePersonalInfo();
    void initPwdDialog();
    void initInfoDialog();
};

#endif // READERVIEW_H
