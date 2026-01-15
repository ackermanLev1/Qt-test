#include "loginview.h"
#include "ui_loginview.h"
#include <QMessageBox>
#include <QGridLayout>

LoginView::LoginView(QWidget *parent) : QWidget(parent), ui(new Ui::LoginView) {
    ui->setupUi(this);
    // 初始化角色下拉框
    ui->cbRole->addItem("读者");
    ui->cbRole->addItem("管理员");

    // 管理员模式禁用注册按钮
    connect(ui->cbRole, &QComboBox::currentTextChanged, this, [=](const QString& text) {
        ui->btnRegister->setEnabled(text == "读者");
    });

    // 初始化注册对话框
    initRegisterDialog();
}

LoginView::~LoginView() {
    delete ui;
    delete registerDialog;
}

void LoginView::initRegisterDialog() {
    registerDialog = new QDialog(this);
    registerDialog->setWindowTitle("读者注册");
    registerDialog->setMinimumSize(350, 280);
    QGridLayout* regLayout = new QGridLayout(registerDialog);

    // 注册表单
    regLayout->addWidget(new QLabel("用户名:"), 0, 0, Qt::AlignRight);
    leRegUser = new QLineEdit();
    leRegUser->setPlaceholderText("请输入用户名");
    regLayout->addWidget(leRegUser, 0, 1);

    regLayout->addWidget(new QLabel("密码:"), 1, 0, Qt::AlignRight);
    leRegPwd = new QLineEdit();
    leRegPwd->setEchoMode(QLineEdit::Password);
    leRegPwd->setPlaceholderText("请输入密码");
    regLayout->addWidget(leRegPwd, 1, 1);

    regLayout->addWidget(new QLabel("姓名:"), 2, 0, Qt::AlignRight);
    leRegName = new QLineEdit();
    leRegName->setPlaceholderText("请输入真实姓名");
    regLayout->addWidget(leRegName, 2, 1);

    regLayout->addWidget(new QLabel("性别:"), 3, 0, Qt::AlignRight);
    leRegGender = new QLineEdit();
    leRegGender->setPlaceholderText("男/女");
    regLayout->addWidget(leRegGender, 3, 1);

    regLayout->addWidget(new QLabel("联系电话:"), 4, 0, Qt::AlignRight);
    leRegPhone = new QLineEdit();
    leRegPhone->setPlaceholderText("请输入手机号");
    regLayout->addWidget(leRegPhone, 4, 1);

    // 按钮布局
    btnRegConfirm = new QPushButton("确认注册");
    btnRegCancel = new QPushButton("取消");
    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->addWidget(btnRegConfirm);
    btnLayout->addWidget(btnRegCancel);
    regLayout->addLayout(btnLayout, 5, 0, 1, 2, Qt::AlignCenter);

    // 注册逻辑
    connect(btnRegConfirm, &QPushButton::clicked, this, [=]() {
        QString username = leRegUser->text().trimmed();
        QString pwd = leRegPwd->text().trimmed();
        QString name = leRegName->text().trimmed();
        QString gender = leRegGender->text().trimmed();
        QString phone = leRegPhone->text().trimmed();

        // 校验输入
        if (username.isEmpty() || pwd.isEmpty() || name.isEmpty() || gender.isEmpty() || phone.isEmpty()) {
            QMessageBox::warning(registerDialog, "警告", "请填写完整注册信息！");
            return;
        }
        if (gender != "男" && gender != "女") {
            QMessageBox::warning(registerDialog, "警告", "性别请输入「男」或「女」！");
            return;
        }
        if (phone.length() != 11) {
            QMessageBox::warning(registerDialog, "警告", "请输入11位手机号！");
            return;
        }

        // 调用注册接口
        QString readerId;
        if (DataBaseManager::getInstance()->readerRegister(username, pwd, name, gender, phone, readerId)) {
            QMessageBox::information(registerDialog, "成功", "注册成功！您的读者ID：" + readerId);
            registerDialog->close();
            // 清空输入
            leRegUser->clear();
            leRegPwd->clear();
            leRegName->clear();
            leRegGender->clear();
            leRegPhone->clear();
        } else {
            QMessageBox::warning(registerDialog, "失败", "用户名已存在！");
        }
    });

    connect(btnRegCancel, &QPushButton::clicked, registerDialog, &QDialog::close);
}

void LoginView::on_btnLogin_clicked() {
    QString username = ui->leUser->text().trimmed();
    QString pwd = ui->lePwd->text().trimmed();
    QString role = ui->cbRole->currentText();

    // 校验输入
    if (username.isEmpty() || pwd.isEmpty()) {
        QMessageBox::warning(this, "警告", "用户名或密码不能为空！");
        return;
    }

    // 调用登录验证
    QString userId;
    bool isUserExist;
    int userType = DataBaseManager::getInstance()->loginVerify(username, pwd, userId, isUserExist);

    // 处理登录结果
    if (role == "管理员") {
        if (userType == 2) {
            QMessageBox::information(this, "成功", "管理员登录成功！");
            emit loginSuccess(2, userId);
            this->hide();
        } else {
            QMessageBox::warning(this, "失败", "用户名或密码有误！");
        }
    } else { // 读者角色
        if (!isUserExist) {
            QMessageBox::warning(this, "失败", "没有此用户名，请先注册！");
        } else if (userType == 1) {
            QMessageBox::information(this, "成功", "读者登录成功！");
            emit loginSuccess(1, userId);
            this->hide();
        } else {
            QMessageBox::warning(this, "失败", "密码错误！");
        }
    }
}

void LoginView::on_btnRegister_clicked() {
    registerDialog->exec();
}

void LoginView::clearPasswordInput() {
    ui->lePwd->clear();
}
