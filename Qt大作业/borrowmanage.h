// borrowmanage.h（简化版）
#ifndef BORROWMANAGE_H
#define BORROWMANAGE_H

#include <QWidget>
#include <QSqlQueryModel>
#include "databasemanager.h"

namespace Ui {
class BorrowManage;
}

class BorrowManage : public QWidget
{
    Q_OBJECT

public:
    explicit BorrowManage(DatabaseManager *dbManager, QWidget *parent = nullptr);
    ~BorrowManage();
    void refreshBorrowList(int status = -1); // -1=全部，0=未还，1=已还

private slots:
    void onBtnBorrowClicked(); // 借阅按钮
    void onBtnReturnClicked(); // 归还按钮
    void onBtnRefreshBorrowClicked(); // 刷新按钮
    void onCbxStatusCurrentIndexChanged(int index); // 状态筛选下拉框变化

private:
    Ui::BorrowManage *ui;
    DatabaseManager *m_dbManager;
    QSqlQueryModel *m_borrowModel;
};

#endif // BORROWMANAGE_H
