#include <QApplication>
#include "mainwindow.h"
#include "databasemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 初始化数据库（全局唯一实例，可通过 MainWindow 调用）
    DatabaseManager dbManager;
    if (!dbManager.isConnected()) {
        qDebug() << "数据库初始化失败，程序退出！";
        return -1;
    }

    MainWindow w(&dbManager); // 传入数据库管理实例
    w.show();

    return a.exec();
}
