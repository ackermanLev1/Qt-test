#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databasemanager.h"
#include "bookmanage.h"
#include "readermanage.h"
#include "borrowmanage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(DatabaseManager *dbManager, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 菜单/工具栏切换界面的槽函数
    void onActionBookManageTriggered();
    void onActionReaderManageTriggered();
    void onActionBorrowManageTriggered();
    void onActionQuitTriggered();

private:
    Ui::MainWindow *ui;
    DatabaseManager *m_dbManager; // 数据库管理实例
    BookManage *m_bookWidget;     // 图书管理子界面
    ReaderManage *m_readerWidget; // 读者管理子界面
    BorrowManage *m_borrowWidget; // 借阅管理子界面
};

#endif // MAINWINDOW_H
