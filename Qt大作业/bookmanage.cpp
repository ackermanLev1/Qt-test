// bookmanage.cpp
#include "bookmanage.h"
#include "ui_bookmanage.h"
#include <QMessageBox>

BookManage::BookManage(DatabaseManager *dbManager, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookManage),
    m_dbManager(dbManager)
{
    ui->setupUi(this);

    // 初始化图书列表 Model
    m_bookModel = new QSqlQueryModel(this);
    ui->tableViewBooks->setModel(m_bookModel);
    ui->tableViewBooks->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewBooks->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewBooks->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 列宽自适应

    // 绑定按钮事件
    connect(ui->btnAddBook, &QPushButton::clicked, this, &BookManage::onBtnAddBookClicked);
    connect(ui->btnDeleteBook, &QPushButton::clicked, this, &BookManage::onBtnDeleteBookClicked);
    connect(ui->btnSearch, &QPushButton::clicked, this, &BookManage::onBtnSearchClicked);
    connect(ui->btnRefreshBook, &QPushButton::clicked, this, &BookManage::onBtnRefreshClicked);

    // 初始加载所有图书
    refreshBookList();
}

BookManage::~BookManage()
{
    delete ui;
}

// 刷新图书列表
void BookManage::refreshBookList(const QString &keyword)
{
    // 从数据库获取数据并更新 Model
    QSqlQueryModel * newModel = m_dbManager->getBookList(keyword);
    m_bookModel->setQuery(newModel->query());
    m_bookModel->setHeaderData(0, Qt::Horizontal, "图书ID");
    m_bookModel->setHeaderData(1, Qt::Horizontal, "图书名称");
    m_bookModel->setHeaderData(2, Qt::Horizontal, "作者");
    m_bookModel->setHeaderData(3, Qt::Horizontal, "出版社");
    m_bookModel->setHeaderData(4, Qt::Horizontal, "出版日期");
    m_bookModel->setHeaderData(5, Qt::Horizontal, "分类");
    m_bookModel->setHeaderData(6, Qt::Horizontal, "库存");
    delete newModel; // 释放临时 Model
}

// 添加图书
void BookManage::onBtnAddBookClicked()
{
    AddBookDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QMap<QString, QVariant> info = dialog.getBookInfo();
        // 验证必填项
        if (info["name"].toString().isEmpty() || info["author"].toString().isEmpty()) {
            QMessageBox::warning(this, "警告", "图书名称和作者不能为空！");
            return;
        }
        // 调用数据库接口添加图书
        bool success = m_dbManager->addBook(
            info["name"].toString(),
            info["author"].toString(),
            info["publisher"].toString(),
            info["publishDate"].toDate(),
            info["category"].toString(),
            info["stock"].toInt()
        );
        if (success) {
            QMessageBox::information(this, "成功", "图书添加成功！");
            refreshBookList(); // 刷新列表
        } else {
            QMessageBox::critical(this, "失败", "图书添加失败，请重试！");
        }
    }
}

// 删除图书
void BookManage::onBtnDeleteBookClicked()
{
    // 获取选中的行
    QModelIndexList selectedRows = ui->tableViewBooks->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择要删除的图书！");
        return;
    }
    // 确认删除
    int bookId = m_bookModel->data(m_bookModel->index(selectedRows.first().row(), 0)).toInt();
    QString bookName = m_bookModel->data(m_bookModel->index(selectedRows.first().row(), 1)).toString();
    if (QMessageBox::question(this, "确认", QString("是否删除图书《%1》？").arg(bookName),
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) {
        return;
    }
    // 调用数据库接口删除
    bool success = m_dbManager->deleteBook(bookId);
    if (success) {
        QMessageBox::information(this, "成功", "图书删除成功！");
        refreshBookList();
    } else {
        QMessageBox::critical(this, "失败", "图书删除失败（可能存在关联借阅记录）！");
    }
}

// 搜索图书
void BookManage::onBtnSearchClicked()
{
    QString keyword = ui->leSearch->text().trimmed();
    refreshBookList(keyword);
}

// 刷新列表
void BookManage::onBtnRefreshClicked()
{
    ui->leSearch->clear();
    refreshBookList();
}
