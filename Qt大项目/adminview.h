#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>

namespace Ui {
class AdminView;
}

class AdminView : public QWidget {
    Q_OBJECT

public:
    explicit AdminView(const QString& adminId, QWidget *parent = nullptr);
    ~AdminView();

signals:
    void logout();

private slots:
    void on_btnBookManage_clicked();
    void on_btnReaderManage_clicked();
    void on_btnBorrowData_clicked();
    void on_btnExit_clicked();
    void on_btnSearchBook_clicked();
    void on_btnAddBook_clicked();
    void on_btnModifyBook_clicked();
    void on_btnDeleteBook_clicked();
    void on_btnSearchReader_clicked();
    void on_btnDeleteReader_clicked();
    void on_btnAllBorrow_clicked();
    void on_btnUnreturned_clicked();
    void on_btnReturned_clicked();
    void on_btnRefreshBorrow_clicked();

private:
    Ui::AdminView *ui;
    QString adminId;
    QSqlQueryModel* bookModel;
    QSqlQueryModel* readerModel;
    QSqlQueryModel* borrowModel;
    // 添加/修改图书对话框
    QDialog* bookDialog;
    QLineEdit* leBookId;
    QLineEdit* leBookName;
    QLineEdit* leBookAuthor;
    QLineEdit* leBookPublisher;
    QDateEdit* deBookDate;
    QLineEdit* leBookCategory;
    QLineEdit* leBookStock;
    QPushButton* btnBookOk;
    QPushButton* btnBookCancel;
    bool isModifyMode; // 是否为修改模式

    void initBookModel(const QString& searchKey = "");
    void initReaderModel(const QString& searchKey = "");
    void initBorrowModel(const QString& type = "all");
};

#endif // ADMINVIEW_H
