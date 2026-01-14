#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "LoginView.h"
#include "AdminView.h"
#include "ReaderView.h"
#include "DataBaseManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleLoginSuccess(int userType, const QString& userId);
    void handleLogout();
    void handleReturnToMain();

private:
    Ui::MainWindow *ui;
    LoginView* loginView;
    AdminView* adminView;
    ReaderView* readerView;

    void showLoginView();
    void showUserView(int userType, const QString& userId);
    void cleanupUserView();
};

#endif // MAINWINDOW_H
