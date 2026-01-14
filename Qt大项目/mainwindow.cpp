#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      loginView(nullptr),
      adminView(nullptr),
      readerView(nullptr) {

    ui->setupUi(this);
    this->setWindowTitle("图书借阅管理系统");
    this->setMinimumSize(800, 600);

    // 创建中心部件
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);

    // 初始化数据库
    if (!DataBaseManager::getInstance()->initDataBase()) {
        QMessageBox::critical(this, "错误", "数据库初始化失败，程序即将退出！");
        qApp->quit();
        return;
    }

    // 显示登录界面
    showLoginView();
}

MainWindow::~MainWindow() {
    cleanupUserView();
    delete loginView;
    delete ui;
}

void MainWindow::showLoginView() {
    // 清理当前视图
    cleanupUserView();

    // 创建登录视图
    if (!loginView) {
        loginView = new LoginView();
        connect(loginView, &LoginView::loginSuccess, this, &MainWindow::handleLoginSuccess);
        connect(loginView, &LoginView::returnToMain, this, &MainWindow::handleReturnToMain);
    }

    // 添加到主布局
    QLayout *layout = centralWidget()->layout();
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    layout->addWidget(loginView);
    loginView->show();
}

void MainWindow::showUserView(int userType, const QString& userId) {
    // 清理当前视图
    QLayout *layout = centralWidget()->layout();
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget() == loginView) {
            layout->removeWidget(loginView);
            loginView->hide();
        }
        delete item;
    }

    // 根据用户类型创建相应视图
    if (userType == 2) { // 管理员
        adminView = new AdminView(userId);
        connect(adminView, &AdminView::logout, this, &MainWindow::handleLogout);
        layout->addWidget(adminView);
    } else if (userType == 1) { // 读者
        readerView = new ReaderView(userId);
        connect(readerView, &ReaderView::logout, this, &MainWindow::handleLogout);
        layout->addWidget(readerView);
    }
}

void MainWindow::cleanupUserView() {
    if (adminView) {
        adminView->deleteLater();
        adminView = nullptr;
    }
    if (readerView) {
        readerView->deleteLater();
        readerView = nullptr;
    }
}

void MainWindow::handleLoginSuccess(int userType, const QString& userId) {
    showUserView(userType, userId);
}

void MainWindow::handleLogout() {
    showLoginView();
}

void MainWindow::handleReturnToMain() {
    showLoginView();
}
