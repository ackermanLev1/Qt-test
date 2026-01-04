// bookmanage.h
#ifndef BOOKMANAGE_H
#define BOOKMANAGE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QDialog>
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include "databasemanager.h"

namespace Ui {
class BookManage;
}

class BookManage : public QWidget
{
    Q_OBJECT

public:
    explicit BookManage(DatabaseManager *dbManager, QWidget *parent = nullptr);
    ~BookManage();

    void refreshBookList(const QString &keyword = ""); // 刷新图书列表

private slots:
    void onBtnAddBookClicked(); // 添加图书按钮点击
    void onBtnDeleteBookClicked(); // 删除图书按钮点击
    void onBtnSearchClicked(); // 搜索按钮点击
    void onBtnRefreshClicked(); // 刷新按钮点击

private:
    Ui::BookManage *ui;
    DatabaseManager *m_dbManager;
    QSqlQueryModel *m_bookModel; // 图书列表 Model

    // 添加图书的对话框（内部类）
    class AddBookDialog : public QDialog
    {
    public:
        AddBookDialog(QWidget *parent = nullptr) : QDialog(parent)
        {
            this->setWindowTitle("添加图书");
            this->setModal(true); // 模态对话框（阻塞父窗口）
            this->resize(400, 300);

            // 初始化控件
            leName = new QLineEdit(this);
            leAuthor = new QLineEdit(this);
            lePublisher = new QLineEdit(this);
            dePublishDate = new QDateEdit(this);
            dePublishDate->setDate(QDate::currentDate());
            leCategory = new QLineEdit(this);
            leStock = new QLineEdit(this);
            leStock->setPlaceholderText("请输入库存数量");
            leStock->setValidator(new QIntValidator(0, 999, this)); // 只允许输入整数

            btnConfirm = new QPushButton("确认添加", this);
            btnCancel = new QPushButton("取消", this);

            // 布局（表单布局 + 按钮布局）
            QFormLayout *formLayout = new QFormLayout;
            formLayout->addRow("图书名称*", leName);
            formLayout->addRow("作者*", leAuthor);
            formLayout->addRow("出版社", lePublisher);
            formLayout->addRow("出版日期", dePublishDate);
            formLayout->addRow("分类", leCategory);
            formLayout->addRow("库存数量", leStock);

            QHBoxLayout *btnLayout = new QHBoxLayout;
            btnLayout->addStretch();
            btnLayout->addWidget(btnConfirm);
            btnLayout->addWidget(btnCancel);

            QVBoxLayout *mainLayout = new QVBoxLayout(this);
            mainLayout->addLayout(formLayout);
            mainLayout->addLayout(btnLayout);

            // 绑定按钮事件
            connect(btnConfirm, &QPushButton::clicked, this, &AddBookDialog::accept);
            connect(btnCancel, &QPushButton::clicked, this, &AddBookDialog::reject);
        }

        // 获取输入的图书信息
        QMap<QString, QVariant> getBookInfo() const
        {
            QMap<QString, QVariant> info;
            info["name"] = leName->text();
            info["author"] = leAuthor->text();
            info["publisher"] = lePublisher->text();
            info["publishDate"] = dePublishDate->date();
            info["category"] = leCategory->text();
            info["stock"] = leStock->text().toInt();
            return info;
        }

    private:
        QLineEdit *leName;
        QLineEdit *leAuthor;
        QLineEdit *lePublisher;
        QDateEdit *dePublishDate;
        QLineEdit *leCategory;
        QLineEdit *leStock;
        QPushButton *btnConfirm;
        QPushButton *btnCancel;
    };
};

#endif // BOOKMANAGE_H
