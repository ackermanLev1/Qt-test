/********************************************************************************
** Form generated from reading UI file 'paitenteditview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAITENTEDITVIEW_H
#define UI_PAITENTEDITVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PaitentEditView
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_7;
    QSpinBox *spinBox;
    QLabel *label_6;
    QSpinBox *spinBox_2;
    QLabel *label_5;
    QSpinBox *spinBox_3;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *PaitentEditView)
    {
        if (PaitentEditView->objectName().isEmpty())
            PaitentEditView->setObjectName(QString::fromUtf8("PaitentEditView"));
        PaitentEditView->resize(489, 246);
        horizontalLayout = new QHBoxLayout(PaitentEditView);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(PaitentEditView);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(PaitentEditView);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(PaitentEditView);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(PaitentEditView);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_4 = new QLabel(PaitentEditView);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        lineEdit_3 = new QLineEdit(PaitentEditView);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        label_3 = new QLabel(PaitentEditView);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        comboBox = new QComboBox(PaitentEditView);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox);

        label_7 = new QLabel(PaitentEditView);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        spinBox = new QSpinBox(PaitentEditView);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBox);

        label_6 = new QLabel(PaitentEditView);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        spinBox_2 = new QSpinBox(PaitentEditView);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBox_2);

        label_5 = new QLabel(PaitentEditView);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_5);

        spinBox_3 = new QSpinBox(PaitentEditView);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));

        formLayout->setWidget(6, QFormLayout::FieldRole, spinBox_3);

        label_8 = new QLabel(PaitentEditView);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        lineEdit_4 = new QLineEdit(PaitentEditView);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEdit_4);


        horizontalLayout->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(PaitentEditView);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(PaitentEditView);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(PaitentEditView);

        QMetaObject::connectSlotsByName(PaitentEditView);
    } // setupUi

    void retranslateUi(QWidget *PaitentEditView)
    {
        PaitentEditView->setWindowTitle(QApplication::translate("PaitentEditView", "Form", nullptr));
        label->setText(QApplication::translate("PaitentEditView", "ID\357\274\232", nullptr));
        label_2->setText(QApplication::translate("PaitentEditView", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_4->setText(QApplication::translate("PaitentEditView", "\350\272\253\344\273\275\350\257\201\357\274\232", nullptr));
        label_3->setText(QApplication::translate("PaitentEditView", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_7->setText(QApplication::translate("PaitentEditView", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_6->setText(QApplication::translate("PaitentEditView", "\350\272\253\351\253\230\357\274\232", nullptr));
        label_5->setText(QApplication::translate("PaitentEditView", "\344\275\223\351\207\215\357\274\232", nullptr));
        label_8->setText(QApplication::translate("PaitentEditView", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("PaitentEditView", "\344\277\235\345\255\230", nullptr));
        pushButton_2->setText(QApplication::translate("PaitentEditView", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PaitentEditView: public Ui_PaitentEditView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAITENTEDITVIEW_H
