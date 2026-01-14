#include "Headers/LoginView.h"
#include "ui_LoginView.h"
#include <QMessageBox>
#include <QGridLayout>

LoginView::LoginView(QWidget *parent) : QWidget(parent), ui(new Ui::LoginView) {
    ui->setupUi(this);
    // 初始化角色下拉框
    ui->cbRole->addItem("读者");
    ui->cbRole->addItem("管理员");
    // 管理员模式下禁用注册按钮
    connect(ui->cbRole, &QComboBox::currentTextChanged, this, [=](const QString& text) {
        ui->btnRegister->setEnabled(text == "读者");
    });
    ui->btnRegister->setEnabled(false); // 默认管理员选中，禁用注册

    // 初始化注册对话框
    registerDialog = new QDialog(this);
    registerDialog->setWindowTitle("读者注册");
    registerDialog->setMinimumSize(350, 250);
    QGridLayout* regLayout = new QGridLayout(registerDialog);

    // 注册对话框控件
    regLayout->addWidget(new QLabel("用户名:"), 0, 0);
    leRegUser = new QLineEdit();
    regLayout->addWidget(leRegUser, 0, 1);

    regLayout->addWidget(new QLabel("密码:"), 1, 0);
    leRegPwd = new QLineEdit();
    leRegPwd->setEchoMode(QLineEdit::Password);
    regLayout->addWidget(leRegPwd, 1, 1);

    regLayout->addWidget(new QLabel("姓名:"), 2, 0);
    leRegName = new QLineEdit();
    regLayout->addWidget(leRegName, 2, 1);

    regLayout->addWidget(new QLabel("性别:"), 3, 0);
    leRegGender = new QLineEdit();
    regLayout->addWidget(leRegGender, 3, 1);

    regLayout->addWidget(new QLabel("联系电话:"), 4, 0);
    leRegPhone = new QLineEdit();
    regLayout->addWidget(leRegPhone, 4, 1);

    btnRegConfirm = new QPushButton("确认注册");
    btnRegCancel = new QPushButton("取消");
    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->addWidget(btnRegConfirm);
    btnLayout->addWidget(btnRegCancel);
    regLayout->addLayout(btnLayout, 5, 0, 1, 2);

    // 注册对话框信号槽
    connect(btnRegConfirm, &QPushButton::clicked, this, [=]() {
        QString username = leRegUser->text().trimmed();
        QString pwd = leRegPwd->text().trimmed();
        QString name = leRegName->text().trimmed();
        QString gender = leRegGender->text().trimmed();
        QString phone = leRegPhone->text().trimmed();

        if (username.isEmpty() || pwd.isEmpty() || name.isEmpty() || gender.isEmpty() || phone.isEmpty()) {
            QMessageBox::warning(registerDialog, "警告", "请填写完整信息！");
            return;
        }

        if (DataBaseManager::getInstance()->readerRegister(username, pwd, name, gender, phone)) {
            QMessageBox::information(registerDialog, "成功", "注册成功！");
            registerDialog->close();
            // 清空输入框
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

LoginView::~LoginView() {
    delete ui;
}

void LoginView::on_btnLogin_clicked() {
    QString username = ui->leUser->text().trimmed();
    QString pwd = ui->lePwd->text().trimmed();
    QString role = ui->cbRole->currentText();

    if (username.isEmpty() || pwd.isEmpty()) {
        QMessageBox::warning(this, "警告", "用户名或密码不能为空！");
        return;
    }

    QString userId;
    int userType = DataBaseManager::getInstance()->loginVerify(username, pwd, userId);

    if (userType == 0) {
        QMessageBox::warning(this, "失败", "用户名或密码有误！");
    } else if ((userType == 1 && role == "读者") || (userType == 2 && role == "管理员")) {
        QMessageBox::information(this, "成功", "登录成功！");
        emit loginSuccess(userType, userId);
        this->hide();
    } else {
        QMessageBox::warning(this, "失败", "用户类型不匹配！");
    }
}

void LoginView::on_btnRegister_clicked() {
    registerDialog->exec();
}

void LoginView::on_btnReturn_clicked() {
    emit returnToMain();
    this->hide();
}

void LoginView::on_btnLogout_clicked() {
    ui->leUser->clear();
    ui->lePwd->clear();
    ui->cbRole->setCurrentIndex(0);
}
