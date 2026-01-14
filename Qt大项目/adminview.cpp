#include "Headers/AdminView.h"
#include "ui_AdminView.h"
#include <QMessageBox>
#include <QGridLayout>

AdminView::AdminView(const QString& adminId, QWidget *parent) : QWidget(parent), ui(new Ui::AdminView), adminId(adminId), isModifyMode(false) {
    ui->setupUi(this);
    // 初始化模型
    bookModel = new QSqlQueryModel();
    readerModel = new QSqlQueryModel();
    borrowModel = new QSqlQueryModel();
    ui->tableViewBooks->setModel(bookModel);
    ui->tableViewReaders->setModel(readerModel);
    ui->tableViewBorrow->setModel(borrowModel);
    // 设置表格自适应列宽
    ui->tableViewBooks->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewReaders->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewBorrow->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // 初始化默认页面
    initBookModel();
    ui->stackedWidget->setCurrentWidget(ui->pageBookManage);

    // 初始化图书对话框
    bookDialog = new QDialog(this);
    bookDialog->setWindowTitle("添加图书");
    bookDialog->setMinimumSize(400, 300);
    QGridLayout* bookLayout = new QGridLayout(bookDialog);

    bookLayout->addWidget(new QLabel("图书ID:"), 0, 0);
    leBookId = new QLineEdit();
    bookLayout->addWidget(leBookId, 0, 1);

    bookLayout->addWidget(new QLabel("图书名称*:"), 1, 0);
    leBookName = new QLineEdit();
    bookLayout->addWidget(leBookName, 1, 1);

    bookLayout->addWidget(new QLabel("作者*:"), 2, 0);
    leBookAuthor = new QLineEdit();
    bookLayout->addWidget(leBookAuthor, 2, 1);

    bookLayout->addWidget(new QLabel("出版社:"), 3, 0);
    leBookPublisher = new QLineEdit();
    bookLayout->addWidget(leBookPublisher, 3, 1);

    bookLayout->addWidget(new QLabel("出版日期:"), 4, 0);
    deBookDate = new QDateEdit(QDate::currentDate());
    deBookDate->setCalendarPopup(true);
    bookLayout->addWidget(deBookDate, 4, 1);

    bookLayout->addWidget(new QLabel("分类:"), 5, 0);
    leBookCategory = new QLineEdit();
    bookLayout->addWidget(leBookCategory, 5, 1);

    bookLayout->addWidget(new QLabel("库存数量:"), 6, 0);
    leBookStock = new QLineEdit("0");
    bookLayout->addWidget(leBookStock, 6, 1);

    btnBookOk = new QPushButton("确认");
    btnBookCancel = new QPushButton("取消");
    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->addWidget(btnBookOk);
    btnLayout->addWidget(btnBookCancel);
    bookLayout->addLayout(btnLayout, 7, 0, 1, 2);

    // 图书对话框信号槽
    connect(btnBookOk, &QPushButton::clicked, this, [=]() {
        QString bookId = leBookId->text().trimmed();
        QString name = leBookName->text().trimmed();
        QString author = leBookAuthor->text().trimmed();
        QString publisher = leBookPublisher->text().trimmed();
        QString publishDate = deBookDate->date().toString("yyyy-MM-dd");
        QString category = leBookCategory->text().trimmed();
        int stock = leBookStock->text().toInt();

        if (name.isEmpty() || author.isEmpty()) {
            QMessageBox::warning(bookDialog, "警告", "图书名称和作者不能为空！");
            return;
        }

        bool success = false;
        if (isModifyMode) {
            success = DataBaseManager::getInstance()->modifyBook(bookId, name, author, publisher, publishDate, category, stock);
        } else {
            if (bookId.isEmpty()) {
                bookId = DataBaseManager::getInstance()->generateBookId();
            }
            success = DataBaseManager::getInstance()->addBook(bookId, name, author, publisher, publishDate, category, stock);
        }

        if (success) {
            QMessageBox::information(bookDialog, "成功", isModifyMode ? "修改图书成功！" : "添加图书成功！");
            bookDialog->close();
            initBookModel();
            // 清空输入框
            leBookId->clear();
            leBookName->clear();
            leBookAuthor->clear();
            leBookPublisher->clear();
            leBookCategory->clear();
            leBookStock->setText("0");
        } else {
            QMessageBox::warning(bookDialog, "失败", isModifyMode ? "修改图书失败！" : "添加图书失败（图书ID已存在）！");
        }
    });

    connect(btnBookCancel, &QPushButton::clicked, bookDialog, &QDialog::close);
}

AdminView::~AdminView() {
    delete ui;
    delete bookModel;
    delete readerModel;
    delete borrowModel;
}

void AdminView::initBookModel(const QString& searchKey) {
    delete bookModel;
    bookModel = DataBaseManager::getInstance()->getBookList(searchKey);
    ui->tableViewBooks->setModel(bookModel);
}

void AdminView::initReaderModel(const QString& searchKey) {
    delete readerModel;
    readerModel = DataBaseManager::getInstance()->getReaderList(searchKey);
    ui->tableViewReaders->setModel(readerModel);
}

void AdminView::initBorrowModel(const QString& type) {
    delete borrowModel;
    borrowModel = DataBaseManager::getInstance()->getBorrowList(type);
    ui->tableViewBorrow->setModel(borrowModel);
}

void AdminView::on_btnBookManage_clicked() {
    initBookModel();
    ui->stackedWidget->setCurrentWidget(ui->pageBookManage);
}

void AdminView::on_btnReaderManage_clicked() {
    initReaderModel();
    ui->stackedWidget->setCurrentWidget(ui->pageReaderManage);
}

void AdminView::on_btnBorrowData_clicked() {
    initBorrowModel("all");
    ui->stackedWidget->setCurrentWidget(ui->pageBorrowData);
}

void AdminView::on_btnExit_clicked() {
    emit logout();
    this->hide();
}

void AdminView::on_btnSearchBook_clicked() {
    QString searchKey = ui->leBookSearch->text().trimmed();
    initBookModel(searchKey);
}

void AdminView::on_btnAddBook_clicked() {
    isModifyMode = false;
    bookDialog->setWindowTitle("添加图书");
    leBookId->setEnabled(true);
    bookDialog->exec();
}

void AdminView::on_btnModifyBook_clicked() {
    QModelIndex index = ui->tableViewBooks->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择要修改的图书！");
        return;
    }
    // 获取选中图书的ID和当前信息
    QString bookId = bookModel->index(index.row(), 0).data().toString();
    QString name = bookModel->index(index.row(), 1).data().toString();
    QString author = bookModel->index(index.row(), 2).data().toString();
    QString publisher = bookModel->index(index.row(), 3).data().toString();
    QString publishDate = bookModel->index(index.row(), 4).data().toString();
    QString category = bookModel->index(index.row(), 5).data().toString();
    int stock = bookModel->index(index.row(), 6).data().toInt();

    // 填充到对话框
    isModifyMode = true;
    bookDialog->setWindowTitle("修改图书");
    leBookId->setText(bookId);
    leBookId->setEnabled(false); // 禁止修改图书ID
    leBookName->setText(name);
    leBookAuthor->setText(author);
    leBookPublisher->setText(publisher);
    deBookDate->setDate(QDate::fromString(publishDate, "yyyy-MM-dd"));
    leBookCategory->setText(category);
    leBookStock->setText(QString::number(stock));
    bookDialog->exec();
}

void AdminView::on_btnDeleteBook_clicked() {
    QModelIndex index = ui->tableViewBooks->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择要删除的图书！");
        return;
    }
    QString bookId = bookModel->index(index.row(), 0).data().toString();
    QString bookName = bookModel->index(index.row(), 1).data().toString();

    if (QMessageBox::question(this, "确认", "是否删除图书《" + bookName + "》？", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        if (DataBaseManager::getInstance()->deleteBook(bookId)) {
            QMessageBox::information(this, "成功", "删除图书成功！");
            initBookModel();
        } else {
            QMessageBox::warning(this, "失败", "删除失败（存在未还借阅记录）！");
        }
    }
}

void AdminView::on_btnSearchReader_clicked() {
    QString searchKey = ui->leReaderSearch->text().trimmed();
    initReaderModel(searchKey);
}

void AdminView::on_btnDeleteReader_clicked() {
    QModelIndex index = ui->tableViewReaders->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择要删除的读者！");
        return;
    }
    QString readerId = readerModel->index(index.row(), 0).data().toString();
    QString readerName = readerModel->index(index.row(), 1).data().toString();

    if (QMessageBox::question(this, "确认", "是否删除读者" + readerName + "？", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        if (DataBaseManager::getInstance()->deleteReader(readerId)) {
            QMessageBox::information(this, "成功", "删除读者成功！");
            initReaderModel();
        } else {
            QMessageBox::warning(this, "失败", "删除失败（存在未还借阅记录）！");
        }
    }
}

void AdminView::on_btnAllBorrow_clicked() {
    initBorrowModel("all");
}

void AdminView::on_btnUnreturned_clicked() {
    initBorrowModel("unreturned");
}

void AdminView::on_btnReturned_clicked() {
    initBorrowModel("returned");
}

void AdminView::on_btnRefreshBorrow_clicked() {
    initBorrowModel("all");
}
