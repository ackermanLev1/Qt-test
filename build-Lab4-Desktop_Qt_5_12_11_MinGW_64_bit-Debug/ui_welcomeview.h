/********************************************************************************
** Form generated from reading UI file 'welcomeview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEVIEW_H
#define UI_WELCOMEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeView
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btDepartment;
    QPushButton *btDoctor;
    QPushButton *btPatient;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *WelcomeView)
    {
        if (WelcomeView->objectName().isEmpty())
            WelcomeView->setObjectName(QString::fromUtf8("WelcomeView"));
        WelcomeView->resize(587, 459);
        verticalLayout = new QVBoxLayout(WelcomeView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 158, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btDepartment = new QPushButton(WelcomeView);
        btDepartment->setObjectName(QString::fromUtf8("btDepartment"));
        btDepartment->setEnabled(true);
        btDepartment->setMinimumSize(QSize(100, 100));
        btDepartment->setMaximumSize(QSize(100, 100));

        horizontalLayout->addWidget(btDepartment);

        btDoctor = new QPushButton(WelcomeView);
        btDoctor->setObjectName(QString::fromUtf8("btDoctor"));
        btDoctor->setMinimumSize(QSize(100, 100));
        btDoctor->setMaximumSize(QSize(100, 100));

        horizontalLayout->addWidget(btDoctor);

        btPatient = new QPushButton(WelcomeView);
        btPatient->setObjectName(QString::fromUtf8("btPatient"));
        btPatient->setMinimumSize(QSize(100, 100));
        btPatient->setMaximumSize(QSize(100, 100));

        horizontalLayout->addWidget(btPatient);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 157, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(WelcomeView);

        QMetaObject::connectSlotsByName(WelcomeView);
    } // setupUi

    void retranslateUi(QWidget *WelcomeView)
    {
        WelcomeView->setWindowTitle(QApplication::translate("WelcomeView", "\346\254\242\350\277\216", nullptr));
        btDepartment->setText(QApplication::translate("WelcomeView", "\347\247\221\345\256\244\347\256\241\347\220\206", nullptr));
        btDoctor->setText(QApplication::translate("WelcomeView", "\345\214\273\347\224\237\347\256\241\347\220\206", nullptr));
        btPatient->setText(QApplication::translate("WelcomeView", "\346\202\243\350\200\205\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomeView: public Ui_WelcomeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEVIEW_H
