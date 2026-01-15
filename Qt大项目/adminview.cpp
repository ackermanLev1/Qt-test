#include "adminview.h"
#include "ui_adminview.h"
#include <QMessageBox>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QIntValidator>

AdminView::AdminView(const QString& adminId, QWidget *parent)
    : QWidget(parent), ui(new Ui::AdminView), adminId(adminId), isModifyMode(false) {
    ui->setupUi(this);

    // 初始化数据模型
    bookModel = new QSqlQueryModel();
    readerModel = new QSqlQueryModel();
    borrowModel = new QSqlQueryModel();

    // 设置表格模型（确保控件名称与 .ui 一致）
    ui->tableViewBooks->setModel(bookModel);
    ui->tableViewReaders->setModel(readerModel);
    ui->tableViewBorrow->setModel(borrowModel);

    // 表格自适应列宽
    ui->tableViewBooks->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewReaders->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableViewBorrow->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 设置搜索框占位文本（匹配 .ui 控件名称）
    ui->leBookSearch->setPlaceholderText("请输入图书ID/名称");
    ui->leReaderSearch->setPlaceholderText("请输入读者ID/姓名");

    // 初始化借阅状态下拉框
    initBorrowStatusCombo();

    // 初始化默认页面（图书管理）
    initBookModel();
    ui->stackedWidget->setCurrentWidget(ui->pageBookManage);

    // 初始化图书对话框
    initBookDialog();
}

AdminView::~AdminView() {
    delete ui;
    delete bookModel;
    delete readerModel;
    delete borrowModel;
    delete bookDialog;
}

// 初始化借阅状态下拉框
void AdminView::initBorrowStatusCombo() {
    ui->cbxStatus->clear();
    ui->cbxStatus->addItems({"全部记录", "已还记录", "未还记录"});
    ui->cbxStatus->setCurrentIndex(0);
    initBorrowModel("全部记录");
}

// 根据下拉框状态初始化借阅模型
void AdminView::initBorrowModel(const QString& status) {
    delete borrowModel;
    QString type = "all";
    if (status == "未还记录") type = "unreturned";
    else if (status == "已还记录") type = "returned";
    borrowModel = DataBaseManager::getInstance()->getBorrowList(type);
    ui->tableViewBorrow->setModel(borrowModel);
}

// 下拉框状态变化槽函数
void AdminView::on_cbxStatus_currentTextChanged(const QString &text) {
    initBorrowModel(text);
}

// 借阅数据刷新按钮
void AdminView::on_btnRefreshBorrow_clicked() {
    initBorrowModel(ui->cbxStatus->currentText());
}

// 删除图书按钮（增加输入校验）
void AdminView::on_btnDeleteBook_clicked() {
    QModelIndex index = ui->tableViewBooks->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择要删除的图书！");
        return;
    }

    QString bookId = bookModel->index(index.row(), 0).data().toString();
    QString bookName = bookModel->index(index.row(), 1).data().toString();

    QMessageBox::StandardButton res = QMessageBox::question(
        this, "确认删除",
        QString("是否删除图书《%1》？\n注：存在未还借阅记录时无法删除").arg(bookName),
        QMessageBox::Yes | QMessageBox::No, QMessageBox::No
    );

    if (res == QMessageBox::Yes) {
        if (DataBaseManager::getInstance()->deleteBook(bookId)) {
            QMessageBox::information(this, "成功", "图书删除成功！");
            initBookModel(ui->leBookSearch->text().trimmed());
        } else {
            QMessageBox::warning(this, "失败", "删除失败！该图书存在未还借阅记录。");
        }
    }
}

// 初始化图书模型
void AdminView::initBookModel(const QString& searchKey) {
    delete bookModel;
    bookModel = DataBaseManager::getInstance()->getBookList(searchKey);
    ui->tableViewBooks->setModel(bookModel);
}

// 初始化读者模型
void AdminView::initReaderModel(const QString& searchKey) {
    delete readerModel;
    readerModel = DataBaseManager::getInstance()->getReaderList(searchKey);
    ui->tableViewReaders->setModel(readerModel);
}

// 初始化图书对话框（增加输入校验）
void AdminView::initBookDialog() {
    bookDialog = new QDialog(this);
    bookDialog->setWindowTitle("图书信息");
    bookDialog->setModal(true);
    bookDialog->setFixedSize(400, 350);

    // 初始化对话框控件
    leBookId = new QLineEdit(bookDialog);
    leBookId->setPlaceholderText("请输入图书ID（唯一）");
    leBookName = new QLineEdit(bookDialog);
    leBookName->setPlaceholderText("请输入图书名称");
    leBookAuthor = new QLineEdit(bookDialog);
    leBookAuthor->setPlaceholderText("请输入作者");
    leBookPublisher = new QLineEdit(bookDialog);
    leBookPublisher->setPlaceholderText("请输入出版社");
    deBookDate = new QDateEdit(bookDialog);
    deBookDate->setCalendarPopup(true);
    deBookDate->setDate(QDate::currentDate());
    leBookCategory = new QLineEdit(bookDialog);
    leBookCategory->setPlaceholderText("请输入分类（如：编程、文学）");
    leBookStock = new QLineEdit(bookDialog);
    leBookStock->setPlaceholderText("请输入库存数量（≥0）");
    leBookStock->setValidator(new QIntValidator(0, 1000, this)); // 库存只能是0-1000的整数

    btnBookOk = new QPushButton("确认", bookDialog);
    btnBookCancel = new QPushButton("取消", bookDialog);

    // 布局
    QGridLayout* layout = new QGridLayout(bookDialog);
    layout->addWidget(new QLabel("图书ID："), 0, 0);
    layout->addWidget(leBookId, 0, 1);
    layout->addWidget(new QLabel("图书名称："), 1, 0);
    layout->addWidget(leBookName, 1, 1);
    layout->addWidget(new QLabel("作者："), 2, 0);
    layout->addWidget(leBookAuthor, 2, 1);
    layout->addWidget(new QLabel("出版社："), 3, 0);
    layout->addWidget(leBookPublisher, 3, 1);
    layout->addWidget(new QLabel("出版日期："), 4, 0);
    layout->addWidget(deBookDate, 4, 1);
    layout->addWidget(new QLabel("分类："), 5, 0);
    layout->addWidget(leBookCategory, 5, 1);
    layout->addWidget(new QLabel("库存："), 6, 0);
    layout->addWidget(leBookStock, 6, 1);

    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->addWidget(btnBookOk);
    btnLayout->addWidget(btnBookCancel);
    layout->addLayout(btnLayout, 7, 0, 1, 2, Qt::AlignCenter);

    // 连接按钮信号槽（增加输入校验）
    connect(btnBookCancel, &QPushButton::clicked, bookDialog, &QDialog::close);
    connect(btnBookOk, &QPushButton::clicked, this, [=]() {
        // 输入校验
        QString bookId = leBookId->text().trimmed();
        QString bookName = leBookName->text().trimmed();
        QString author = leBookAuthor->text().trimmed();
        QString stockText = leBookStock->text().trimmed();

        if (bookId.isEmpty() || bookName.isEmpty() || author.isEmpty() || stockText.isEmpty()) {
            QMessageBox::warning(bookDialog, "警告", "图书ID、名称、作者、库存不能为空！");
            return;
        }

        if (stockText.toInt() < 0) {
            QMessageBox::warning(bookDialog, "警告", "库存数量不能为负数！");
            return;
        }

        bookDialog->accept();
    });
}

// 页面切换槽函数（确保切换时刷新数据）
void AdminView::on_btnBookManage_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->pageBookManage);
    initBookModel(ui->leBookSearch->text().trimmed());
}

void AdminView::on_btnReaderManage_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->pageReaderManage);
    initReaderModel(ui->leReaderSearch->text().trimmed());
}

void AdminView::on_btnBorrowData_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->pageBorrowData);
    initBorrowModel(ui->cbxStatus->currentText());
}

void AdminView::on_btnExit_clicked() {
    emit logout();
}

// 搜索槽函数
void AdminView::on_btnSearchBook_clicked() {
    initBookModel(ui->leBookSearch->text().trimmed());
}

void AdminView::on_btnSearchReader_clicked() {
    initReaderModel(ui->leReaderSearch->text().trimmed());
}

// 添加图书槽函数
void AdminView::on_btnAddBook_clicked() {
    isModifyMode = false;
    leBookId->setEnabled(true);
    // 清空输入框
    leBookId->clear();
    leBookName->clear();
    leBookAuthor->clear();
    leBookPublisher->clear();
    deBookDate->setDate(QDate::currentDate());
    leBookCategory->clear();
    leBookStock->clear();

    if (bookDialog->exec() == QDialog::Accepted) {
        QString bookId = leBookId->text().trimmed();
        QString bookName = leBookName->text().trimmed();
        QString author = leBookAuthor->text().trimmed();
        QString publisher = leBookPublisher->text().trimmed();
        QString publishDate = deBookDate->date().toString("yyyy-MM-dd");
        QString category = leBookCategory->text().trimmed();
        int stock = leBookStock->text().toInt();

        if (DataBaseManager::getInstance()->addBook(bookId, bookName, author, publisher, publishDate, category, stock)) {
            QMessageBox::information(this, "成功", "图书添加成功！");
            initBookModel();
        } else {
            QMessageBox::warning(this, "失败", "图书添加失败！可能是图书ID已存在。");
        }
    }
}

// 修改图书槽函数
void AdminView::on_btnModifyBook_clicked() {
    QModelIndex index = ui->tableViewBooks->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择要修改的图书！");
        return;
    }

    isModifyMode = true;
    // 填充当前图书信息
    leBookId->setText(bookModel->index(index.row(), 0).data().toString());
    leBookId->setEnabled(false); // 图书ID不可修改
    leBookName->setText(bookModel->index(index.row(), 1).data().toString());
    leBookAuthor->setText(bookModel->index(index.row(), 2).data().toString());
    leBookPublisher->setText(bookModel->index(index.row(), 3).data().toString());

    QString dateStr = bookModel->index(index.row(), 4).data().toString();
    QDate date = QDate::fromString(dateStr, "yyyy-MM-dd");
    deBookDate->setDate(date.isValid() ? date : QDate::currentDate());

    leBookCategory->setText(bookModel->index(index.row(), 5).data().toString());
    leBookStock->setText(bookModel->index(index.row(), 6).data().toString());

    if (bookDialog->exec() == QDialog::Accepted) {
        QString bookId = leBookId->text().trimmed();
        QString bookName = leBookName->text().trimmed();
        QString author = leBookAuthor->text().trimmed();
        QString publisher = leBookPublisher->text().trimmed();
        QString publishDate = deBookDate->date().toString("yyyy-MM-dd");
        QString category = leBookCategory->text().trimmed();
        int stock = leBookStock->text().toInt();

        if (DataBaseManager::getInstance()->modifyBook(bookId, bookName, author, publisher, publishDate, category, stock)) {
            QMessageBox::information(this, "成功", "图书修改成功！");
            initBookModel(ui->leBookSearch->text().trimmed());
        } else {
            QMessageBox::warning(this, "失败", "图书修改失败！");
        }
    }
}

// 删除读者按钮（增加校验）
void AdminView::on_btnDeleteReader_clicked() {
    QModelIndex index = ui->tableViewReaders->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "警告", "请选择要删除的读者！");
        return;
    }

    QString readerId = readerModel->index(index.row(), 0).data().toString();
    QString readerName = readerModel->index(index.row(), 1).data().toString();

    QMessageBox::StandardButton res = QMessageBox::question(
        this, "确认删除", QString("是否删除读者「%1」？\n注：存在未还借阅记录时无法删除").arg(readerName),
        QMessageBox::Yes | QMessageBox::No, QMessageBox::No
    );

    if (res == QMessageBox::Yes) {
        if (DataBaseManager::getInstance()->deleteReader(readerId)) {
            QMessageBox::information(this, "成功", "读者删除成功！");
            initReaderModel(ui->leReaderSearch->text().trimmed());
        } else {
            QMessageBox::warning(this, "失败", "删除失败！该读者存在未还借阅记录。");
        }
    }
}
