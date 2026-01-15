#include "readerview.h"
#include "ui_readerview.h"
#include <QMessageBox>
#include <QGridLayout>
#include <QInputDialog>
#include <QIntValidator>
#include <QLabel>

ReaderView::ReaderView(const QString& readerId, QWidget *parent) : QWidget(parent), ui(new Ui::ReaderView), readerId(readerId) {
    ui->setupUi(this);

    // 初始化数据模型
    bookBorrowModel = new QSqlQueryModel();
    borrowQueryModel = new QSqlQueryModel();

    // 使用正确的控件名称
    ui->tableViewBookBorrow->setModel(bookBorrowModel);
    ui->tableViewReaderBorrow->setModel(borrowQueryModel);

    // 表格自适应
    ui->tableViewBookBorrow->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewReaderBorrow->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 设置搜索框占位文本
    ui->leBookSearchReader->setPlaceholderText("请输入图书ID/名称");

    // 初始化借阅状态下拉框
    ui->cbxStatus->clear();
    ui->cbxStatus->addItems({"全部记录", "已还记录", "未还记录"});
    ui->cbxStatus->setCurrentIndex(0);
    connect(ui->cbxStatus, &QComboBox::currentTextChanged, this, &ReaderView::on_cbxStatus_currentTextChanged);

    // 初始化默认页面（个人信息）
    updatePersonalInfo();
    initBookBorrowModel();
    ui->stackedWidget->setCurrentWidget(ui->pagePersonalInfo);

    // 初始化对话框
    initPwdDialog();
    initInfoDialog();

    // 检查逾期
    QString overdue = DataBaseManager::getInstance()->checkOverdue(readerId);
    if (!overdue.isEmpty()) {
        ui->lblOverdueTips->setText("⚠️ 逾期未还图书：\n" + overdue);
        ui->lblOverdueTips->setStyleSheet("color: red; font-weight: bold;");
    } else {
        ui->lblOverdueTips->setText("");
    }
}

ReaderView::~ReaderView() {
    delete ui;
    delete bookBorrowModel;
    delete borrowQueryModel;
    delete pwdDialog;
    delete infoDialog;
}

void ReaderView::updatePersonalInfo() {
    QSqlQuery query = DataBaseManager::getInstance()->getPersonalInfo(readerId);
    if (query.next()) {
        ui->lblReaderID->setText("读者ID：" + readerId);
        ui->lblReaderName->setText("姓名：" + query.value("name").toString());
        ui->lblReaderGender->setText("性别：" + query.value("gender").toString());
        ui->lblReaderPhone->setText("联系电话：" + query.value("phone").toString());
        ui->lblRegisterTime->setText("注册时间：" + query.value("registerTime").toString());

        // 填充信息对话框默认值
        if (leInfoName) leInfoName->setText(query.value("name").toString());
        if (leInfoGender) leInfoGender->setText(query.value("gender").toString());
        if (leInfoPhone) leInfoPhone->setText(query.value("phone").toString());
    }
}

void ReaderView::initBookBorrowModel(const QString& searchKey) {
    delete bookBorrowModel;
    bookBorrowModel = DataBaseManager::getInstance()->getBookList(searchKey);
    ui->tableViewBookBorrow->setModel(bookBorrowModel);
}

void ReaderView::initBorrowQueryModel(const QString& type) {
    delete borrowQueryModel;
    borrowQueryModel = DataBaseManager::getInstance()->getBorrowList(type, readerId);
    ui->tableViewReaderBorrow->setModel(borrowQueryModel);

    // 更新逾期提醒
    QString overdue = DataBaseManager::getInstance()->checkOverdue(readerId);
    if (!overdue.isEmpty()) {
        ui->lblOverdueTips->setText("⚠️ 逾期未还图书：\n" + overdue);
        ui->lblOverdueTips->setStyleSheet("color: red; font-weight: bold;");
    } else {
        ui->lblOverdueTips->setText("");
    }
}

void ReaderView::initPwdDialog() {
    pwdDialog = new QDialog(this);
    pwdDialog->setWindowTitle("修改密码");
    pwdDialog->setMinimumSize(350, 220);
    QGridLayout* pwdLayout = new QGridLayout(pwdDialog);

    // 密码表单
    pwdLayout->addWidget(new QLabel("旧密码:"), 0, 0, Qt::AlignRight);
    leOldPwd = new QLineEdit();
    leOldPwd->setEchoMode(QLineEdit::Password);
    pwdLayout->addWidget(leOldPwd, 0, 1);

    pwdLayout->addWidget(new QLabel("新密码:"), 1, 0, Qt::AlignRight);
    leNewPwd = new QLineEdit();
    leNewPwd->setEchoMode(QLineEdit::Password);
    pwdLayout->addWidget(leNewPwd, 1, 1);

    pwdLayout->addWidget(new QLabel("确认新密码:"), 2, 0, Qt::AlignRight);
    leConfirmPwd = new QLineEdit();
    leConfirmPwd->setEchoMode(QLineEdit::Password);
    pwdLayout->addWidget(leConfirmPwd, 2, 1);

    // 按钮
    btnPwdOk = new QPushButton("确认");
    btnPwdCancel = new QPushButton("取消");
    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->addWidget(btnPwdOk);
    btnLayout->addWidget(btnPwdCancel);
    pwdLayout->addLayout(btnLayout, 3, 0, 1, 2, Qt::AlignCenter);

    // 密码修改逻辑
    connect(btnPwdOk, &QPushButton::clicked, this, [=]() {
        QString oldPwd = leOldPwd->text().trimmed();
        QString newPwd = leNewPwd->text().trimmed();
        QString confirmPwd = leConfirmPwd->text().trimmed();

        // 校验
        if (oldPwd.isEmpty() || newPwd.isEmpty() || confirmPwd.isEmpty()) {
            QMessageBox::warning(pwdDialog, "警告", "请填写完整密码信息！");
            return;
        }
        if (newPwd != confirmPwd) {
            QMessageBox::warning(pwdDialog, "警告", "两次输入的新密码不一致！");
            return;
        }
        if (newPwd.length() < 6) {
            QMessageBox::warning(pwdDialog, "警告", "新密码长度不能小于6位！");
            return;
        }

        // 修改密码
        if (DataBaseManager::getInstance()->modifyPwd(readerId, newPwd, false)) {
            QMessageBox::information(pwdDialog, "成功", "密码修改成功！下次登录请使用新密码。");
            pwdDialog->close();
            // 清空
            leOldPwd->clear();
            leNewPwd->clear();
            leConfirmPwd->clear();
        } else {
            QMessageBox::warning(pwdDialog, "失败", "密码修改失败！");
        }
    });

    connect(btnPwdCancel, &QPushButton::clicked, pwdDialog, &QDialog::close);
}

void ReaderView::initInfoDialog() {
    infoDialog = new QDialog(this);
    infoDialog->setWindowTitle("修改个人信息");
    infoDialog->setMinimumSize(350, 220);
    QGridLayout* infoLayout = new QGridLayout(infoDialog);

    // 信息表单
    infoLayout->addWidget(new QLabel("姓名:"), 0, 0, Qt::AlignRight);
    leInfoName = new QLineEdit();
    infoLayout->addWidget(leInfoName, 0, 1);

    infoLayout->addWidget(new QLabel("性别:"), 1, 0, Qt::AlignRight);
    leInfoGender = new QLineEdit();
    infoLayout->addWidget(leInfoGender, 1, 1);

    infoLayout->addWidget(new QLabel("联系电话:"), 2, 0, Qt::AlignRight);
    leInfoPhone = new QLineEdit();
    leInfoPhone->setValidator(new QIntValidator(this));
    infoLayout->addWidget(leInfoPhone, 2, 1);

    // 按钮
    btnInfoOk = new QPushButton("确认");
    btnInfoCancel = new QPushButton("取消");
    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->addWidget(btnInfoOk);
    btnLayout->addWidget(btnInfoCancel);
    infoLayout->addLayout(btnLayout, 3, 0, 1, 2, Qt::AlignCenter);

    // 信息修改逻辑
    connect(btnInfoOk, &QPushButton::clicked, this, [=]() {
        QString name = leInfoName->text().trimmed();
        QString gender = leInfoGender->text().trimmed();
        QString phone = leInfoPhone->text().trimmed();

        // 校验
        if (name.isEmpty() || gender.isEmpty() || phone.isEmpty()) {
            QMessageBox::warning(infoDialog, "警告", "请填写完整信息！");
            return;
        }
        if (gender != "男" && gender != "女") {
            QMessageBox::warning(infoDialog, "警告", "性别请输入「男」或「女」！");
            return;
        }
        if (phone.length() != 11) {
            QMessageBox::warning(infoDialog, "警告", "请输入11位手机号！");
            return;
        }

        // 修改信息
        if (DataBaseManager::getInstance()->modifyPersonalInfo(readerId, name, gender, phone)) {
            QMessageBox::information(infoDialog, "成功", "个人信息修改成功！");
            infoDialog->close();
            updatePersonalInfo();
        } else {
            QMessageBox::warning(infoDialog, "失败", "个人信息修改失败！");
        }
    });

    connect(btnInfoCancel, &QPushButton::clicked, infoDialog, &QDialog::close);
}

void ReaderView::on_btnPersonalInfo_clicked() {
    updatePersonalInfo();
    ui->stackedWidget->setCurrentWidget(ui->pagePersonalInfo);
}

void ReaderView::on_btnBookBorrow_clicked() {
    initBookBorrowModel();
    ui->stackedWidget->setCurrentWidget(ui->pageBookBorrow);
}

void ReaderView::on_btnBorrowQuery_clicked() {
    initBorrowQueryModel("all");
    ui->stackedWidget->setCurrentWidget(ui->pageBorrowQuery);
}

void ReaderView::on_btnReaderExit_clicked() {
    emit logout();
}

void ReaderView::on_btnModifyPwd_clicked() {
    pwdDialog->exec();
}

void ReaderView::on_btnModifyInfo_clicked() {
    infoDialog->exec();
}

void ReaderView::on_btnSearchBookReader_clicked() {
    QString searchKey = ui->leBookSearchReader->text().trimmed();
    initBookBorrowModel(searchKey);
}

void ReaderView::on_btnBorrowBook_clicked() {
    QModelIndex index = ui->tableViewBookBorrow->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择要借阅的图书！");
        return;
    }

    // 获取图书信息
    QString bookId = bookBorrowModel->index(index.row(), 0).data().toString();
    QString bookName = bookBorrowModel->index(index.row(), 1).data().toString();
    int stock = bookBorrowModel->index(index.row(), 6).data().toInt();

    // 检查库存
    if (stock <= 0) {
        QMessageBox::warning(this, "失败", "《" + bookName + "》库存不足，无法借阅！");
        return;
    }

    // 输入借阅天数（1-30天）
    bool ok;
    int borrowDays = QInputDialog::getInt(this, "借阅天数", "请输入借阅天数（1-30天）：", 14, 1, 30, 1, &ok);
    if (!ok) {
        return;
    }

    // 调用借阅接口
    if (DataBaseManager::getInstance()->borrowBook(bookId, readerId, borrowDays)) {
        QMessageBox::information(this, "成功", "《" + bookName + "》借阅成功！\n借阅天数：" + QString::number(borrowDays) + "天");
        initBookBorrowModel();
        initBorrowQueryModel("all");
    } else {
        QMessageBox::warning(this, "失败", "借阅失败！\n可能原因：\n1. 您已借阅该图书且未归还\n2. 系统异常，请重试");
    }
}

void ReaderView::on_btnReturnBook_clicked() {
    QModelIndex index = ui->tableViewReaderBorrow->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择要归还的借阅记录！");
        return;
    }

    // 获取借阅记录信息
    QString borrowId = borrowQueryModel->index(index.row(), 0).data().toString();
    QString bookName = borrowQueryModel->index(index.row(), 1).data().toString();
    QString status = borrowQueryModel->index(index.row(), 6).data().toString();

    // 检查状态
    if (status != "未还") {
        QMessageBox::warning(this, "失败", "《" + bookName + "》已归还，无需重复操作！");
        return;
    }

    // 确认归还
    if (QMessageBox::question(this, "确认归还", "是否确认归还《" + bookName + "》？", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        if (DataBaseManager::getInstance()->returnBook(borrowId)) {
            QMessageBox::information(this, "成功", "《" + bookName + "》归还成功！");
            initBookBorrowModel();
            initBorrowQueryModel("all");
        } else {
            QMessageBox::warning(this, "失败", "归还失败！系统异常，请重试。");
        }
    }
}

void ReaderView::on_cbxStatus_currentTextChanged(const QString &text) {
    QString type = "all";
    if (text == "未还记录") type = "unreturned";
    else if (text == "已还记录") type = "returned";
    initBorrowQueryModel(type);
}
