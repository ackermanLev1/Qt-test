#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include "DataBaseManager.h"

namespace Ui {
class LoginView;
}

class LoginView : public QWidget {
    Q_OBJECT

public:
    explicit LoginView(QWidget *parent = nullptr);
    ~LoginView();

signals:
    // 登录成功信号（参数：用户类型1-读者，2-管理员；用户ID）
    void loginSuccess(int userType, const QString& userId);
    void returnToMain();

private slots:
    void on_btnLogin_clicked();
    void on_btnRegister_clicked();
    void on_btnReturn_clicked();
    void on_btnLogout_clicked();

private:
    Ui::LoginView *ui;
    // 注册对话框
    QDialog* registerDialog;
    QLineEdit* leRegUser;
    QLineEdit* leRegPwd;
    QLineEdit* leRegName;
    QLineEdit* leRegGender;
    QLineEdit* leRegPhone;
    QPushButton* btnRegConfirm;
    QPushButton* btnRegCancel;
};

#endif // LOGINVIEW_H
