/********************************************************************************
** Form generated from reading UI file 'departmentview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMENTVIEW_H
#define UI_DEPARTMENTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepartmentView
{
public:

    void setupUi(QWidget *DepartmentView)
    {
        if (DepartmentView->objectName().isEmpty())
            DepartmentView->setObjectName(QString::fromUtf8("DepartmentView"));
        DepartmentView->resize(400, 300);

        retranslateUi(DepartmentView);

        QMetaObject::connectSlotsByName(DepartmentView);
    } // setupUi

    void retranslateUi(QWidget *DepartmentView)
    {
        DepartmentView->setWindowTitle(QApplication::translate("DepartmentView", "\347\247\221\345\256\244\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DepartmentView: public Ui_DepartmentView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMENTVIEW_H
