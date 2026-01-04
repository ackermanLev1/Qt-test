// borrowmanage.cpp（核心函数）
#include "borrowmanage.h"
#include "ui_borrowmanage.h"
#include <QMessageBox>

BorrowManage::BorrowManage(DatabaseManager *dbManager, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BorrowManage),
    m_dbManager(dbManager)
{
    ui->setupUi(this);

    m_borrowModel = new QSqlQueryModel(this);
    ui->tableViewBorrows->setModel(m_borrowModel);
    ui->tableViewBorrows->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewBorrows->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewBorrows->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 初始化筛选下拉框
    ui->cbxStatus->addItem("全部记录");
    ui->cbxStatus->addItem("未还记录");
    ui->cbxStatus->addItem("已还记录");

    // 绑定按钮事件
    connect(ui->btnBorrow, &QPushButton::clicked, this, &BorrowManage::onBtnBorrowClicked);
    connect(ui->btnReturn, &QPushButton::clicked, this, &BorrowManage::onBtnReturnClicked);
    connect(ui->btnRefreshBorrow, &QPushButton::clicked, this, &BorrowManage::onBtnRefreshBorrowClicked);
    connect(ui->cbxStatus, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),this, &BorrowManage::onCbxStatusCurrentIndexChanged);
    refreshBorrowList();
}

void BorrowManage::refreshBorrowList(int status)
{
    QSqlQueryModel *newModel = m_dbManager->getBorrowList(status);
    m_borrowModel->setQuery(newModel->query());
    m_borrowModel->setHeaderData(0, Qt::Horizontal, "借阅ID");
    m_borrowModel->setHeaderData(1, Qt::Horizontal, "图书名称");
    m_borrowModel->setHeaderData(2, Qt::Horizontal, "读者姓名");
    m_borrowModel->setHeaderData(3, Qt::Horizontal, "借阅日期");
    m_borrowModel->setHeaderData(4, Qt::Horizontal, "归还日期");
    m_borrowModel->setHeaderData(5, Qt::Horizontal, "状态");
    delete newModel;
}

// 图书借阅
void BorrowManage::onBtnBorrowClicked()
{
    int bookId = ui->leBookId->text().trimmed().toInt();
    int readerId = ui->leReaderId->text().trimmed().toInt();

    if (bookId <= 0 || readerId <= 0) {
        QMessageBox::warning(this, "警告", "图书ID和读者ID必须为正整数！");
        return;
    }

    bool success = m_dbManager->borrowBook(bookId, readerId);
    if (success) {
        QMessageBox::information(this, "成功", "图书借阅成功！");
        ui->leBookId->clear();
        ui->leReaderId->clear();
        refreshBorrowList(ui->cbxStatus->currentIndex() - 1); // 刷新当前筛选状态
    } else {
        QMessageBox::critical(this, "失败", "图书借阅失败（可能库存不足或ID不存在）！");
    }
}

// 图书归还
void BorrowManage::onBtnReturnClicked()
{
    int borrowId = ui->leBorrowId->text().trimmed().toInt();
    if (borrowId <= 0) {
        QMessageBox::warning(this, "警告", "借阅ID必须为正整数！");
        return;
    }

    bool success = m_dbManager->returnBook(borrowId);
    if (success) {
        QMessageBox::information(this, "成功", "图书归还成功！");
        ui->leBorrowId->clear();
        refreshBorrowList(ui->cbxStatus->currentIndex() - 1);
    } else {
        QMessageBox::critical(this, "失败", "图书归还失败（可能借阅ID不存在或已归还）！");
    }
}

// 筛选状态变化
void BorrowManage::onCbxStatusCurrentIndexChanged(int index)
{
    refreshBorrowList(index - 1); // index 0=全部（-1），1=未还（0），2=已还（1）
}

// 刷新借阅列表
void BorrowManage::onBtnRefreshBorrowClicked()
{
    refreshBorrowList(ui->cbxStatus->currentIndex() - 1);
}
