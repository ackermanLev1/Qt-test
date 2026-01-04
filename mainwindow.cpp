#include "mainwindow.h"

#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("图书与借阅管理系统");
    setMinimumSize(1000, 600);

    // 初始化数据库
    if (!DatabaseManager::instance()->isConnected()) {
        QMessageBox::critical(this, "错误", "数据库连接失败，程序即将退出！");
        close();
        return;
    }

    initUI();
    refreshBookModel();
    refreshBorrowModel();
}

MainWindow::~MainWindow()
{
    // 释放Model
    delete m_bookModel;
    delete m_borrowModel;
}

void MainWindow::initUI()
{
    m_tabWidget = new QTabWidget(this);
    setCentralWidget(m_tabWidget);

    // 初始化两个子界面
    initBookWidget();
    initBorrowWidget();

    m_tabWidget->addTab(m_bookWidget, "图书管理");
    m_tabWidget->addTab(m_borrowWidget, "借阅管理");
}

void MainWindow::initBookWidget()
{
    m_bookWidget = new QWidget(m_tabWidget);
    QVBoxLayout* mainLayout = new QVBoxLayout(m_bookWidget);

    // 表单布局（添加/修改图书）
    QWidget* formWidget = new QWidget();
    QGridLayout* formLayout = new QGridLayout(formWidget);

    // 表单组件
    formLayout->addWidget(new QLabel("图书名称："), 0, 0);
    m_bookNameEdit = new QLineEdit();
    formLayout->addWidget(m_bookNameEdit, 0, 1, 1, 3);

    formLayout->addWidget(new QLabel("作者："), 1, 0);
    m_authorEdit = new QLineEdit();
    formLayout->addWidget(m_authorEdit, 1, 1);

    formLayout->addWidget(new QLabel("出版社："), 1, 2);
    m_publisherEdit = new QLineEdit();
    formLayout->addWidget(m_publisherEdit, 1, 3);

    formLayout->addWidget(new QLabel("出版日期："), 2, 0);
    m_publishDateEdit = new QDateEdit(QDate::currentDate());
    m_publishDateEdit->setCalendarPopup(true);
    formLayout->addWidget(m_publishDateEdit, 2, 1);

    formLayout->addWidget(new QLabel("分类："), 2, 2);
    m_categoryEdit = new QLineEdit();
    formLayout->addWidget(m_categoryEdit, 2, 3);

    formLayout->addWidget(new QLabel("总藏书量："), 3, 0);
    m_totalCountSpin = new QSpinBox();
    m_totalCountSpin->setMinimum(1);
    m_totalCountSpin->setValue(1);
    formLayout->addWidget(m_totalCountSpin, 3, 1);

    formLayout->addWidget(new QLabel("书架位置："), 3, 2);
    m_locationEdit = new QLineEdit();
    formLayout->addWidget(m_locationEdit, 3, 3);

    // 按钮布局
    QHBoxLayout* btnLayout = new QHBoxLayout();
    QPushButton* addBtn = new QPushButton("添加图书");
    QPushButton* updateBtn = new QPushButton("修改图书");
    QPushButton* deleteBtn = new QPushButton("删除图书");
    QPushButton* refreshBtn = new QPushButton("刷新");

    btnLayout->addWidget(addBtn);
    btnLayout->addWidget(updateBtn);
    btnLayout->addWidget(deleteBtn);
    btnLayout->addStretch();
    btnLayout->addWidget(refreshBtn);

    // 图书列表（Model/View）
    m_bookTableView = new QTableView();
    m_bookTableView->setSelectionBehavior(QAbstractItemView::SelectRows); // 整行选择
    m_bookTableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // 禁止编辑
    m_bookTableView->horizontalHeader()->setStretchLastSection(true); // 最后一列拉伸

    // 布局组合
    mainLayout->addWidget(formWidget);
    mainLayout->addLayout(btnLayout);
    mainLayout->addWidget(m_bookTableView);

    // 绑定信号槽
    connect(addBtn, &QPushButton::clicked, this, &MainWindow::onAddBook);
    connect(updateBtn, &QPushButton::clicked, this, &MainWindow::onUpdateBook);
    connect(deleteBtn, &QPushButton::clicked, this, &MainWindow::onDeleteBook);
    connect(refreshBtn, &QPushButton::clicked, this, &MainWindow::refreshBookModel);

    // 选中行时填充表单
    connect(m_bookTableView->selectionModel(), &QItemSelectionModel::currentRowChanged,
            [=](const QModelIndex& current, const QModelIndex&) {
                if (current.isValid()) {
                    m_bookNameEdit->setText(m_bookModel->data(m_bookModel->index(current.row(), 1)).toString());
                    m_authorEdit->setText(m_bookModel->data(m_bookModel->index(current.row(), 2)).toString());
                    m_publisherEdit->setText(m_bookModel->data(m_bookModel->index(current.row(), 3)).toString());
                    m_publishDateEdit->setDate(QDate::fromString(m_bookModel->data(m_bookModel->index(current.row(), 4)).toString(), "yyyy-MM-dd"));
                    m_categoryEdit->setText(m_bookModel->data(m_bookModel->index(current.row(), 5)).toString());
                    m_totalCountSpin->setValue(m_bookModel->data(m_bookModel->index(current.row(), 6)).toInt());
                    m_locationEdit->setText(m_bookModel->data(m_bookModel->index(current.row(), 8)).toString());
                }
            });
}

void MainWindow::initBorrowWidget()
{
    m_borrowWidget = new QWidget(m_tabWidget);
    QVBoxLayout* mainLayout = new QVBoxLayout(m_borrowWidget);

    // 借阅/归还表单
    QWidget* formWidget = new QWidget();
    QHBoxLayout* formLayout = new QHBoxLayout(formWidget);

    formLayout->addWidget(new QLabel("读者ID："));
    m_readerIdEdit = new QLineEdit();
    formLayout->addWidget(m_readerIdEdit);

    QPushButton* borrowBtn = new QPushButton("借阅图书");
    QPushButton* returnBtn = new QPushButton("归还图书");
    QPushButton* refreshBtn = new QPushButton("刷新");

    formLayout->addWidget(borrowBtn);
    formLayout->addWidget(returnBtn);
    formLayout->addStretch();
    formLayout->addWidget(refreshBtn);

    // 借阅记录列表
    m_borrowTableView = new QTableView();
    m_borrowTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_borrowTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_borrowTableView->horizontalHeader()->setStretchLastSection(true);

    // 布局组合
    mainLayout->addWidget(formWidget);
    mainLayout->addWidget(m_borrowTableView);

    // 信号槽绑定
    connect(borrowBtn, &QPushButton::clicked, this, &MainWindow::onBorrowBook);
    connect(returnBtn, &QPushButton::clicked, this, &MainWindow::onReturnBook);
    connect(refreshBtn, &QPushButton::clicked, this, &MainWindow::refreshBorrowModel);
}

void MainWindow::refreshBookModel()
{
    // 释放旧Model
    if (m_bookModel) {
        delete m_bookModel;
    }
    // 获取新Model
    m_bookModel = DatabaseManager::instance()->getBookListModel();
    m_bookTableView->setModel(m_bookModel);
    // 调整列宽
    m_bookTableView->resizeColumnsToContents();
}

void MainWindow::refreshBorrowModel()
{
    if (m_borrowModel) {
        delete m_borrowModel;
    }
    m_borrowModel = DatabaseManager::instance()->getBorrowListModel();
    m_borrowTableView->setModel(m_borrowModel);
    m_borrowTableView->resizeColumnsToContents();
}

int MainWindow::getSelectedBookId()
{
    QModelIndex currentIndex = m_bookTableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "警告", "请选中一本图书！");
        return -1;
    }
    return m_bookModel->data(m_bookModel->index(currentIndex.row(), 0)).toInt();
}

int MainWindow::getSelectedBorrowId()
{
    QModelIndex currentIndex = m_borrowTableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "警告", "请选中一条借阅记录！");
        return -1;
    }
    // 检查是否已归还
    QString returnDate = m_borrowModel->data(m_borrowModel->index(currentIndex.row(), 5)).toString();
    if (!returnDate.isEmpty()) {
        QMessageBox::warning(this, "警告", "该记录已归还，无需重复操作！");
        return -1;
    }
    return m_borrowModel->data(m_borrowModel->index(currentIndex.row(), 0)).toInt();
}

void MainWindow::onAddBook()
{
    // 获取表单数据
    QString bookName = m_bookNameEdit->text().trimmed();
    QString author = m_authorEdit->text().trimmed();
    QString publisher = m_publisherEdit->text().trimmed();
    QDate publishDate = m_publishDateEdit->date();
    QString category = m_categoryEdit->text().trimmed();
    int totalCount = m_totalCountSpin->value();
    QString location = m_locationEdit->text().trimmed();

    // 校验
    if (bookName.isEmpty() || author.isEmpty()) {
        QMessageBox::warning(this, "警告", "图书名称和作者不能为空！");
        return;
    }

    // 调用数据库接口
    bool success = DatabaseManager::instance()->addBook(bookName, author, publisher, publishDate, category, totalCount, location);
    if (success) {
        QMessageBox::information(this, "成功", "图书添加成功！");
        // 清空表单
        m_bookNameEdit->clear();
        m_authorEdit->clear();
        m_publisherEdit->clear();
        m_categoryEdit->clear();
        m_totalCountSpin->setValue(1);
        m_locationEdit->clear();
        // 刷新列表
        refreshBookModel();
    } else {
        QMessageBox::critical(this, "失败", "图书添加失败！");
    }
}

void MainWindow::onUpdateBook()
{
    int bookId = getSelectedBookId();
    if (bookId == -1) return;

    // 获取表单数据
    QString bookName = m_bookNameEdit->text().trimmed();
    QString author = m_authorEdit->text().trimmed();
    QString publisher = m_publisherEdit->text().trimmed();
    QDate publishDate = m_publishDateEdit->date();
    QString category = m_categoryEdit->text().trimmed();
    int totalCount = m_totalCountSpin->value();
    QString location = m_locationEdit->text().trimmed();

    if (bookName.isEmpty() || author.isEmpty()) {
        QMessageBox::warning(this, "警告", "图书名称和作者不能为空！");
        return;
    }

    bool success = DatabaseManager::instance()->updateBook(bookId, bookName, author, publisher, publishDate, category, totalCount, location);
    if (success) {
        QMessageBox::information(this, "成功", "图书修改成功！");
        refreshBookModel();
    } else {
        QMessageBox::critical(this, "失败", "图书修改失败！");
    }
}

void MainWindow::onDeleteBook()
{
    int bookId = getSelectedBookId();
    if (bookId == -1) return;

    QMessageBox::StandardButton btn = QMessageBox::question(this, "确认", "确定要删除该图书吗？",
                                                           QMessageBox::Yes | QMessageBox::No);
    if (btn != QMessageBox::Yes) return;

    bool success = DatabaseManager::instance()->deleteBook(bookId);
    if (success) {
        QMessageBox::information(this, "成功", "图书删除成功！");
        // 清空表单
        m_bookNameEdit->clear();
        m_authorEdit->clear();
        m_publisherEdit->clear();
        m_categoryEdit->clear();
        m_totalCountSpin->setValue(1);
        m_locationEdit->clear();
        refreshBookModel();
    } else {
        QMessageBox::critical(this, "失败", "图书删除失败！");
    }
}

void MainWindow::onBorrowBook()
{
    int bookId = getSelectedBookId();
    if (bookId == -1) return;

    QString readerId = m_readerIdEdit->text().trimmed();
    if (readerId.isEmpty()) {
        QMessageBox::warning(this, "警告", "读者ID不能为空！");
        return;
    }

    bool success = DatabaseManager::instance()->borrowBook(bookId, readerId);
    if (success) {
        QMessageBox::information(this, "成功", "图书借阅成功！");
        m_readerIdEdit->clear();
        refreshBookModel();
        refreshBorrowModel();
    } else {
        QMessageBox::critical(this, "失败", "图书借阅失败（可能已无库存）！");
    }
}

void MainWindow::onReturnBook()
{
    int borrowId = getSelectedBorrowId();
    if (borrowId == -1) return;

    bool success = DatabaseManager::instance()->returnBook(borrowId);
    if (success) {
        QMessageBox::information(this, "成功", "图书归还成功！");
        refreshBookModel();
        refreshBorrowModel();
    } else {
        QMessageBox::critical(this, "失败", "图书归还失败！");
    }
}
