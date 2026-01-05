#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(DatabaseManager *dbManager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_dbManager(dbManager)
{
    ui->setupUi(this);
    this->setWindowTitle("图书与借阅管理系统");
    this->resize(1200, 800); // 设置窗口大小

    // 初始化子界面（传入数据库实例）
    m_bookWidget = new BookManage(m_dbManager, this);
    m_readerWidget = new ReaderManage(m_dbManager, this);
    m_borrowWidget = new BorrowManage(m_dbManager, this);

    // 将子界面添加到堆叠窗口
    ui->stackedWidget->addWidget(m_bookWidget);
    ui->stackedWidget->addWidget(m_readerWidget);
    ui->stackedWidget->addWidget(m_borrowWidget);

    // 绑定菜单/工具栏动作（通过 Qt Designer 右键菜单绑定，或手动 connect）
    connect(ui->actionBookManage, &QAction::triggered, this, &MainWindow::onActionBookManageTriggered);
    connect(ui->actionReaderManage, &QAction::triggered, this, &MainWindow::onActionReaderManageTriggered);
    connect(ui->actionBorrowManage, &QAction::triggered, this, &MainWindow::onActionBorrowManageTriggered);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::onActionQuitTriggered);

    // 默认显示图书管理界面
    ui->stackedWidget->setCurrentWidget(m_bookWidget);
    ui->statusbar->showMessage("当前界面：图书管理");
}

// 补充析构函数：释放子界面资源（避免内存泄漏）
MainWindow::~MainWindow()
{
    delete m_bookWidget;
    delete m_readerWidget;
    delete m_borrowWidget;
    delete ui;
}

// 切换到图书管理界面
void MainWindow::onActionBookManageTriggered()
{
    ui->stackedWidget->setCurrentWidget(m_bookWidget);
    ui->statusbar->showMessage("当前界面：图书管理");
    m_bookWidget->refreshBookList(); // 切换时刷新列表
}

// 切换到读者管理界面
void MainWindow::onActionReaderManageTriggered()
{
    ui->stackedWidget->setCurrentWidget(m_readerWidget);
    ui->statusbar->showMessage("当前界面：读者管理");
    m_readerWidget->refreshReaderList();
}

// 切换到借阅管理界面
void MainWindow::onActionBorrowManageTriggered()
{
    ui->stackedWidget->setCurrentWidget(m_borrowWidget);
    ui->statusbar->showMessage("当前界面：借阅管理");
    m_borrowWidget->refreshBorrowList();
}

// 退出程序
void MainWindow::onActionQuitTriggered()
{
    qApp->quit();
}
