// readermanage.cpp（核心函数）
#include "readermanage.h"
#include "ui_readermanage.h"
#include <QMessageBox>

ReaderManage::ReaderManage(DatabaseManager *dbManager, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReaderManage),
    m_dbManager(dbManager)
{
    ui->setupUi(this);

    m_readerModel = new QSqlQueryModel(this);
    ui->tableViewReaders->setModel(m_readerModel);
    ui->tableViewReaders->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewReaders->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableViewReaders->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->btnAddReader, &QPushButton::clicked, this, &ReaderManage::onBtnAddReaderClicked);
    connect(ui->btnDeleteReader, &QPushButton::clicked, this, &ReaderManage::on_btnDeleteReader_clicked);
    connect(ui->btnSearchReader, &QPushButton::clicked, this, &ReaderManage::on_btnSearchReader_clicked);
    connect(ui->btnRefreshReader, &QPushButton::clicked, this, &ReaderManage::on_btnRefreshReader_clicked);

    refreshReaderList();
}

void ReaderManage::refreshReaderList(const QString &keyword)
{
    QSqlQueryModel *newModel = m_dbManager->getReaderList(keyword);
    m_readerModel->setQuery(newModel->query());
    m_readerModel->setHeaderData(0, Qt::Horizontal, "读者ID");
    m_readerModel->setHeaderData(1, Qt::Horizontal, "读者姓名");
    m_readerModel->setHeaderData(2, Qt::Horizontal, "性别");
    m_readerModel->setHeaderData(3, Qt::Horizontal, "联系电话");
    m_readerModel->setHeaderData(4, Qt::Horizontal, "注册日期");
    delete newModel;
}

void ReaderManage::onBtnAddReaderClicked()
{
    AddReaderDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QMap<QString, QVariant> info = dialog.getReaderInfo();
        if (info["name"].toString().isEmpty()) {
            QMessageBox::warning(this, "警告", "读者姓名不能为空！");
            return;
        }
        bool success = m_dbManager->addReader(
            info["name"].toString(),
            info["gender"].toString(),
            info["phone"].toString()
        );
        if (success) {
            QMessageBox::information(this, "成功", "读者添加成功！");
            refreshReaderList();
        } else {
            QMessageBox::critical(this, "失败", "读者添加失败，请重试！");
        }
    }
}

void ReaderManage::on_btnSearchReader_clicked()
{
    QString keyword = ui->leSearchReader->text().trimmed();
    refreshReaderList(keyword);
}

void ReaderManage::on_btnDeleteReader_clicked()
{
    // 1. 获取选中的行
    QModelIndex currentIndex = ui->tableViewReaders->currentIndex();
    if (!currentIndex.isValid()) { // 未选中任何行
        QMessageBox::warning(this, "提示", "请先选中要删除的读者！");
        return;
    }

    // 2. 获取选中行的读者ID（假设读者ID在第0列）
    int row = currentIndex.row();
    QString readerId = m_readerModel->data(m_readerModel->index(row, 0)).toString();


    // 3. 二次确认删除
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "确认删除",
        QString("确定要删除读者ID为「%1」的信息吗？").arg(readerId),
        QMessageBox::Yes | QMessageBox::No
    );
    if (reply != QMessageBox::Yes) {
        return; // 用户取消操作
    }


    // 4. 调用DatabaseManager删除数据库中的读者
    bool deleteSuccess = m_dbManager->deleteReader(readerId);
    if (deleteSuccess) {
        QMessageBox::information(this, "成功", "读者信息删除成功！");
        refreshReaderList(); // 刷新表格
    } else {
        QMessageBox::critical(this, "失败",
            QString("删除失败：%1").arg(m_dbManager->getLastError()));
    }
}

void ReaderManage::on_btnRefreshReader_clicked()
{
    ui->leSearchReader->clear();
    refreshReaderList();
}
