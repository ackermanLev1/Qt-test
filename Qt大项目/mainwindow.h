#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMessageBox>
#include "loginview.h"
#include "adminview.h"
#include "readerview.h"
#include "databasemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();   

private slots:
    // 处理登录成功
    void handleLoginSuccess(int userType, const QString& userId);
    // 处理退出登录
    void handleLogout();
    // 处理返回主界面
    void handleReturnToMain();

private:
    Ui::MainWindow *ui;
    // 子界面指针
    LoginView* loginView;
    AdminView* adminView;
    ReaderView* readerView;
    // 中心部件布局
    QWidget* centralWidget;
    QVBoxLayout* mainLayout;
};

#endif // MAINWINDOW_H
