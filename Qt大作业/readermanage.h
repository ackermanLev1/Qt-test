// readermanage.h（简化版）
#ifndef READERMANAGE_H
#define READERMANAGE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include "databasemanager.h"

namespace Ui {
class ReaderManage;
}

class ReaderManage : public QWidget
{
    Q_OBJECT

public:
    explicit ReaderManage(DatabaseManager *dbManager, QWidget *parent = nullptr);
    ~ReaderManage();
    void refreshReaderList(const QString &keyword = "");

private slots:
    void onBtnAddReaderClicked();


    void on_btnSearchReader_clicked();

    void on_btnDeleteReader_clicked();

    void on_btnRefreshReader_clicked();

private:
    Ui::ReaderManage *ui;
    DatabaseManager *m_dbManager;
    QSqlQueryModel *m_readerModel;

    // 添加读者对话框（类似添加图书对话框）
    class AddReaderDialog : public QDialog
    {
    public:
        AddReaderDialog(QWidget *parent = nullptr) : QDialog(parent)
        {
            this->setWindowTitle("添加读者");
            this->setModal(true);
            this->resize(350, 250);

            leName = new QLineEdit(this);
            leGender = new QLineEdit(this);
            lePhone = new QLineEdit(this);
            btnConfirm = new QPushButton("确认添加", this);
            btnCancel = new QPushButton("取消", this);

            QFormLayout *formLayout = new QFormLayout;
            formLayout->addRow("读者姓名*", leName);
            formLayout->addRow("性别", leGender);
            formLayout->addRow("联系电话", lePhone);

            QHBoxLayout *btnLayout = new QHBoxLayout;
            btnLayout->addStretch();
            btnLayout->addWidget(btnConfirm);
            btnLayout->addWidget(btnCancel);

            QVBoxLayout *mainLayout = new QVBoxLayout(this);
            mainLayout->addLayout(formLayout);
            mainLayout->addLayout(btnLayout);

            connect(btnConfirm, &QPushButton::clicked, this, &AddReaderDialog::accept);
            connect(btnCancel, &QPushButton::clicked, this, &AddReaderDialog::reject);
        }

        QMap<QString, QVariant> getReaderInfo() const
        {
            QMap<QString, QVariant> info;
            info["name"] = leName->text();
            info["gender"] = leGender->text();
            info["phone"] = lePhone->text();
            return info;
        }

    private:
        QLineEdit *leName;
        QLineEdit *leGender;
        QLineEdit *lePhone;
        QPushButton *btnConfirm;
        QPushButton *btnCancel;
    };
};

#endif // READERMANAGE_H
