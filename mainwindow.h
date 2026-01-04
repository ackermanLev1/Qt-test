#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QTabWidget>
#include <QDateEdit>
#include <QSpinBox>
#include <QMessageBox>
#include <QSqlQueryModel>

#include "databasemanager.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 图书管理槽函数
    void onAddBook();
    void onUpdateBook();
    void onDeleteBook();
    // 借阅管理槽函数
    void onBorrowBook();
    void onReturnBook();
    // 刷新数据
    void refreshBookModel();
    void refreshBorrowModel();

private:
    // UI组件
    QTabWidget* m_tabWidget;
    // 图书管理界面
    QWidget* m_bookWidget;
    QTableView* m_bookTableView;
    QSqlQueryModel* m_bookModel;
    // 借阅管理界面
    QWidget* m_borrowWidget;
    QTableView* m_borrowTableView;
    QSqlQueryModel* m_borrowModel;
    // 表单组件（添加/修改图书）
    QLineEdit* m_bookNameEdit;
    QLineEdit* m_authorEdit;
    QLineEdit* m_publisherEdit;
    QDateEdit* m_publishDateEdit;
    QLineEdit* m_categoryEdit;
    QSpinBox* m_totalCountSpin;
    QLineEdit* m_locationEdit;
    // 借阅/归还组件
    QLineEdit* m_readerIdEdit;

    // 初始化UI
    void initUI();
    // 初始化图书管理界面
    void initBookWidget();
    // 初始化借阅管理界面
    void initBorrowWidget();
    // 获取选中的图书ID
    int getSelectedBookId();
    // 获取选中的借阅记录ID
    int getSelectedBorrowId();
};

#endif // MAINWINDOW_H
