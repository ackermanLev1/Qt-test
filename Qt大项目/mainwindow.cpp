#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // 窗口基础设置
    this->setWindowTitle("图书与借阅管理系统");
    this->setWindowIcon(QIcon(":/icons/book.ico")); // 可选：添加窗口图标

    // 初始化中心部件和布局
    centralWidget = new QWidget(this);
    mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    this->setCentralWidget(centralWidget);

    // 初始化数据库
    if (!DataBaseManager::getInstance()->initDataBase()) {
        QMessageBox::critical(this, "致命错误", "数据库初始化失败，程序即将退出！");
        qApp->quit();
        return;
    }

    // 初始化登录界面
    loginView = new LoginView();
    adminView = nullptr;
    readerView = nullptr;
    mainLayout->addWidget(loginView);

    // 连接信号槽
    connect(loginView, &LoginView::loginSuccess, this, &MainWindow::handleLoginSuccess);
    connect(loginView, &LoginView::returnToMain, this, &MainWindow::handleReturnToMain);
}

MainWindow::~MainWindow() {
    delete ui;
    delete loginView;
    delete adminView;
    delete readerView;
}

void MainWindow::handleLoginSuccess(int userType, const QString& userId) {
    // 隐藏并移除登录界面
    loginView->hide();
    mainLayout->removeWidget(loginView);

    // 根据用户类型创建对应界面
    if (userType == 2) { // 管理员
        adminView = new AdminView(userId);
        mainLayout->addWidget(adminView);
        connect(adminView, &AdminView::logout, this, &MainWindow::handleLogout);
    } else if (userType == 1) { // 读者
        readerView = new ReaderView(userId);
        mainLayout->addWidget(readerView);
        connect(readerView, &ReaderView::logout, this, &MainWindow::handleLogout);
    }
}

void MainWindow::handleLogout() {
    // 移除当前用户界面
    if (adminView) {
        mainLayout->removeWidget(adminView);
        delete adminView;
        adminView = nullptr;
    } else if (readerView) {
        mainLayout->removeWidget(readerView);
        delete readerView;
        readerView = nullptr;
    }

    loginView->clearPasswordInput();

    // 显示登录界面
    mainLayout->addWidget(loginView);
    loginView->show();
}

void MainWindow::handleReturnToMain() {
    // 直接显示登录界面（清空输入）
    loginView->show();

}
