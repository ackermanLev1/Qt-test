#include "Headers/ReaderView.h"
#include "ui_ReaderView.h"
#include <QMessageBox>
#include <QGridLayout>
#include <QInputDialog>

ReaderView::ReaderView(const QString& readerId, QWidget *parent) : QWidget(parent), ui(new Ui::ReaderView), readerId(readerId) {
    ui->setupUi(this);
    // 初始化模型
    bookBorrowModel = new QSqlQueryModel();
    borrowQueryModel = new QSqlQueryModel();
    ui->tableViewBookBorrow->setModel(bookBorrowModel);
    ui->tableViewReaderBorrow->setModel(borrowQueryModel);
    // 表格自适应列宽
    ui->tableViewBookBorrow->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewReaderBorrow->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // 初始化默认页面
    updatePersonalInfo();
    initBookBorrowModel();
    ui->stackedWidgetReader->setCurrentWidget(ui->pagePersonalInfo);

    // 检查逾期
    QString overdue = DataBaseManager::getInstance()->checkOverdue(readerId);
    if (!overdue.isEmpty()) {
        ui->lblOverdueTips->setText("⚠️ 逾期未还图书：\n" + overdue);
        ui->lblOverdueTips->setStyleSheet("color: red; font-weight: bold;");
    }

    // 初始化修改密码对话框
    pwdDialog = new QDialog(this);
    pwdDialog->setWindowTitle("修改密码");
    pwdDialog->setMinimumSize(350, 200);
    QGridLayout* pwdLayout = new QGridLayout(pwdDialog);

    pwdLayout->addWidget(new QLabel("旧密码:"), 0, 0);
    leOldPwd = new QLineEdit();
    leOldPwd->setEchoMode(QLineEdit::Password);
    pwdLayout->addWidget(leOldPwd, 0, 1);

    pwdLayout->addWidget(new QLabel("新密码:"), 1, 0);
    leNewPwd = new QLineEdit();
    leNewPwd->setEchoMode(QLineEdit::Password);
    pwdLayout->addWidget(leNewPwd, 1, 1);

    pwdLayout->addWidget(new QLabel("确认新密码:"), 2, 0);
    leConfirmPwd = new QLineEdit();
    leConfirmPwd->setEchoMode(QLineEdit::Password);
    pwdLayout->addWidget(leConfirmPwd, 2, 1);

    btnPwdOk = new QPushButton("确认");
    btnPwdCancel = new QPushButton("取消");
    QHBoxLayout* pwdBtnLayout = new QHBoxLayout();
    pwdBtnLayout->addWidget(btnPwdOk);
    pwdBtnLayout->addWidget(btnPwdCancel);
    pwdLayout->addLayout(pwdBtnLayout, 3, 0, 1, 2);

    // 修改密码信号槽
    connect(btnPwdOk, &QPushButton::clicked, this, [=]() {
        QString oldPwd = leOldPwd->text().trimmed();
        QString newPwd = leNewPwd->text().trimmed();
        QString confirmPwd = leConfirmPwd->text().trimmed();

        if (newPwd != confirmPwd) {
            QMessageBox::warning(pwdDialog, "警告", "两次输入的新密码不一致！");
            return;
        }

        // 验证旧密码（通过登录验证）
        QString userId;
        if (DataBaseManager::getInstance()->loginVerify("", oldPwd, userId) == 0) {
            QMessageBox::warning(pwdDialog, "警告", "旧密码错误！");
            return;
        }

        if (DataBaseManager::getInstance()->modifyPwd(readerId, newPwd)) {
            QMessageBox::information(pwdDialog, "成功", "密码修改成功！");
            pwdDialog->close();
            leOldPwd->clear();
            leNewPwd->clear();
            leConfirmPwd->clear();
        } else {
            QMessageBox::warning(pwdDialog, "失败", "密码修改失败！");
        }
    });

    connect(btnPwdCancel, &QPushButton::clicked, pwdDialog, &QDialog::close);

    // 初始化修改个人信息对话框
    infoDialog = new QDialog(this);
    infoDialog->setWindowTitle("修改个人信息");
    infoDialog->setMinimumSize(350, 200);
    QGridLayout* infoLayout = new QGridLayout(infoDialog);

    infoLayout->addWidget(new QLabel("姓名:"), 0, 0);
    leInfoName = new QLineEdit();
    infoLayout->addWidget(leInfoName, 0, 1);

    infoLayout->addWidget(new QLabel("性别:"), 1, 0);
    leInfoGender = new QLineEdit();
    infoLayout->addWidget(leInfoGender, 1, 1);

    infoLayout->addWidget(new QLabel("联系电话:"), 2, 0);
    leInfoPhone = new QLineEdit();
    infoLayout->addWidget(leInfoPhone, 2, 1);

    btnInfoOk = new QPushButton("确认");
    btnInfoCancel = new QPushButton("取消");
    QHBoxLayout* infoBtnLayout = new QHBoxLayout();
    infoBtnLayout->addWidget(btnInfoOk);
    infoBtnLayout->addWidget(btnInfoCancel);
    infoLayout->addLayout(infoBtnLayout, 3, 0, 1, 2);

    // 修改个人信息信号槽
    connect(btnInfoOk, &QPushButton::clicked, this, [=]() {
        QString name = leInfoName->text().trimmed();
        QString gender = leInfoGender->text().trimmed();
        QString phone = leInfoPhone->text().trimmed();

        if (name.isEmpty() || gender.isEmpty() || phone.isEmpty()) {
            QMessageBox::warning(infoDialog, "警告", "信息不能为空！");
            return;
        }

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

ReaderView::~ReaderView() {
    delete ui;
    delete bookBorrowModel;
    delete borrowQueryModel;
}

void ReaderView::updatePersonalInfo() {
    QSqlQuery query = DataBaseManager::getInstance()->getPersonalInfo(readerId);
    if (query.next()) {
        ui->lblReaderName->setText("姓名: " + query.value("name").toString());
        ui->lblReaderGender->setText("性别: " + query.value("gender").toString());
        ui->lblReaderPhone->setText("联系电话: " + query.value("phone").toString());
        ui->lblRegisterTime->setText("注册时间: " + query.value("registerTime").toString());
        ui->lblReaderId->setText("读者ID: " + readerId);

        // 填充修改信息对话框默认值
        leInfoName->setText(query.value("name").toString());
        leInfoGender->setText(query.value("gender").toString());
        leInfoPhone->setText(query.value("phone").toString());
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

void ReaderView::on_btnPersonalInfo_clicked() {
    updatePersonalInfo();
    ui->stackedWidgetReader->setCurrentWidget(ui->pagePersonalInfo);
}

void ReaderView::on_btnBookBorrow_clicked() {
    initBookBorrowModel();
    ui->stackedWidgetReader->setCurrentWidget(ui->pageBookBorrow);
}

void ReaderView::on_btnBorrowQuery_clicked() {
    initBorrowQueryModel("all");
    ui->stackedWidgetReader->setCurrentWidget(ui->pageBorrowQuery
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

    QString bookId = bookBorrowModel->index(index.row(), 0).data().toString();
    QString bookName = bookBorrowModel->index(index.row(), 1).data().toString();
    int stock = bookBorrowModel->index(index.row(), 6).data().toInt();

    if (stock <= 0) {
        QMessageBox::warning(this, "失败", "《" + bookName + "》库存不足，无法借阅！");
        return;
    }

    // 弹出借阅天数输入框（1-30天）
    bool ok;
    int borrowDays = QInputDialog::getInt(this, "借阅天数", "请输入借阅天数（1-30天）：", 14, 1, 30, 1, &ok);
    if (!ok) {
        return; // 用户取消
    }

    if (DataBaseManager::getInstance()->borrowBook(bookId, readerId, borrowDays)) {
        QMessageBox::information(this, "成功", "《" + bookName + "》借阅成功！借阅天数：" + QString::number(borrowDays) + "天");
        initBookBorrowModel(); // 刷新图书列表（库存变化）
    } else {
        QMessageBox::warning(this, "失败", "借阅失败！可能已借阅该图书且未归还。");
    }
}

void ReaderView::on_btnReturnBook_clicked() {
    QModelIndex index = ui->tableViewReaderBorrow->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择要归还的借阅记录！");
        return;
    }

    QString borrowId = borrowQueryModel->index(index.row(), 0).data().toString();
    QString bookName = borrowQueryModel->index(index.row(), 1).data().toString();
    QString status = borrowQueryModel->index(index.row(), 6).data().toString();

    if (status != "未还") {
        QMessageBox::warning(this, "失败", "《" + bookName + "》已归还，无需重复操作！");
        return;
    }

    if (DataBaseManager::getInstance()->returnBook(borrowId)) {
        QMessageBox::information(this, "成功", "《" + bookName + "》归还成功！");
        initBorrowQueryModel("all"); // 刷新借阅记录
        initBookBorrowModel(); // 刷新图书库存
    } else {
        QMessageBox::warning(this, "失败", "归还失败，请重试！");
    }
}

void ReaderView::on_btnReaderAll_clicked() {
    initBorrowQueryModel("all");
}

void ReaderView::on_btnReaderUnreturn_clicked() {
    initBorrowQueryModel("unreturned");
}

void ReaderView::on_btnReaderReturned_clicked() {
    initBorrowQueryModel("returned");
}

void ReaderView::on_btnReaderRefresh_clicked() {
    initBorrowQueryModel("all");
}

void ReaderView::on_btnReaderExit_clicked() {
    emit logout();
    this->hide();
}
