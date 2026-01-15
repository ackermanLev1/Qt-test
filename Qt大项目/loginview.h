#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include "databasemanager.h"

namespace Ui {
class LoginView;
}

class LoginView : public QWidget {
    Q_OBJECT

public:
    explicit LoginView(QWidget *parent = nullptr);
    ~LoginView();

    void clearPasswordInput();

signals:
    // 登录成功（1-读者，2-管理员；用户ID）
    void loginSuccess(int userType, const QString& userId);
    void returnToMain();

private slots:
    void on_btnLogin_clicked();
    void on_btnRegister_clicked();

private:
    Ui::LoginView *ui;
    // 注册对话框
    QDialog* registerDialog;
    QLineEdit* leRegUser;    // 注册-用户名
    QLineEdit* leRegPwd;     // 注册-密码
    QLineEdit* leRegName;    // 注册-姓名
    QLineEdit* leRegGender;  // 注册-性别
    QLineEdit* leRegPhone;   // 注册-电话
    QPushButton* btnRegConfirm;
    QPushButton* btnRegCancel;

    // 初始化注册对话框
    void initRegisterDialog();
};

#endif // LOGINVIEW_H
