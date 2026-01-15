#ifndef ADMINVIEW_H
#define ADMINVIEW_H
#include <QWidget>
#include <QSqlQueryModel>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QComboBox>
#include <QHeaderView>
#include "databasemanager.h"

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
    void on_cbxStatus_currentTextChanged(const QString &text);
    void on_btnRefreshBorrow_clicked();


private:
    Ui::AdminView *ui;
    QString adminId;
    QSqlQueryModel* bookModel;
    QSqlQueryModel* readerModel;
    QSqlQueryModel* borrowModel;
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
    bool isModifyMode;

    void initBookModel(const QString& searchKey = "");
    void initReaderModel(const QString& searchKey = "");
    void initBorrowModel(const QString& status = "全部记录");
    void initBookDialog();
    void initBorrowStatusCombo();
};

#endif // ADMINVIEW_H
