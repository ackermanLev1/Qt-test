/********************************************************************************
** Form generated from reading UI file 'doctorview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORVIEW_H
#define UI_DOCTORVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoctorView
{
public:

    void setupUi(QWidget *DoctorView)
    {
        if (DoctorView->objectName().isEmpty())
            DoctorView->setObjectName(QString::fromUtf8("DoctorView"));
        DoctorView->resize(400, 300);

        retranslateUi(DoctorView);

        QMetaObject::connectSlotsByName(DoctorView);
    } // setupUi

    void retranslateUi(QWidget *DoctorView)
    {
        DoctorView->setWindowTitle(QApplication::translate("DoctorView", "\345\214\273\347\224\237\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorView: public Ui_DoctorView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORVIEW_H
