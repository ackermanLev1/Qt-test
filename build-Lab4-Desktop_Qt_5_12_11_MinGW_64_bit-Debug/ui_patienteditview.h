/********************************************************************************
** Form generated from reading UI file 'patienteditview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTEDITVIEW_H
#define UI_PATIENTEDITVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
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

class Ui_PatientEditView
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *dbEditID;
    QLabel *label_2;
    QLineEdit *dbEditName;
    QLabel *label_4;
    QLineEdit *dbEditIDCard;
    QLabel *label_3;
    QComboBox *dbComboSex;
    QLabel *label_7;
    QLabel *label_6;
    QSpinBox *dbSpinHeight;
    QLabel *label_5;
    QSpinBox *dbSpinWeight;
    QLabel *label_8;
    QLineEdit *dbEditMobile;
    QLabel *label_9;
    QLineEdit *dbCreatedTimestamp;
    QDateEdit *dbDateEditDOB;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *PatientEditView)
    {
        if (PatientEditView->objectName().isEmpty())
            PatientEditView->setObjectName(QString::fromUtf8("PatientEditView"));
        PatientEditView->resize(586, 353);
        PatientEditView->setMinimumSize(QSize(0, 0));
        PatientEditView->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(PatientEditView);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 44, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(121, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(PatientEditView);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        dbEditID = new QLineEdit(PatientEditView);
        dbEditID->setObjectName(QString::fromUtf8("dbEditID"));

        formLayout->setWidget(0, QFormLayout::FieldRole, dbEditID);

        label_2 = new QLabel(PatientEditView);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        dbEditName = new QLineEdit(PatientEditView);
        dbEditName->setObjectName(QString::fromUtf8("dbEditName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, dbEditName);

        label_4 = new QLabel(PatientEditView);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        dbEditIDCard = new QLineEdit(PatientEditView);
        dbEditIDCard->setObjectName(QString::fromUtf8("dbEditIDCard"));

        formLayout->setWidget(2, QFormLayout::FieldRole, dbEditIDCard);

        label_3 = new QLabel(PatientEditView);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        dbComboSex = new QComboBox(PatientEditView);
        dbComboSex->addItem(QString());
        dbComboSex->addItem(QString());
        dbComboSex->setObjectName(QString::fromUtf8("dbComboSex"));

        formLayout->setWidget(3, QFormLayout::FieldRole, dbComboSex);

        label_7 = new QLabel(PatientEditView);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        label_6 = new QLabel(PatientEditView);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        dbSpinHeight = new QSpinBox(PatientEditView);
        dbSpinHeight->setObjectName(QString::fromUtf8("dbSpinHeight"));

        formLayout->setWidget(5, QFormLayout::FieldRole, dbSpinHeight);

        label_5 = new QLabel(PatientEditView);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_5);

        dbSpinWeight = new QSpinBox(PatientEditView);
        dbSpinWeight->setObjectName(QString::fromUtf8("dbSpinWeight"));

        formLayout->setWidget(6, QFormLayout::FieldRole, dbSpinWeight);

        label_8 = new QLabel(PatientEditView);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        dbEditMobile = new QLineEdit(PatientEditView);
        dbEditMobile->setObjectName(QString::fromUtf8("dbEditMobile"));

        formLayout->setWidget(7, QFormLayout::FieldRole, dbEditMobile);

        label_9 = new QLabel(PatientEditView);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_9);

        dbCreatedTimestamp = new QLineEdit(PatientEditView);
        dbCreatedTimestamp->setObjectName(QString::fromUtf8("dbCreatedTimestamp"));

        formLayout->setWidget(8, QFormLayout::FieldRole, dbCreatedTimestamp);

        dbDateEditDOB = new QDateEdit(PatientEditView);
        dbDateEditDOB->setObjectName(QString::fromUtf8("dbDateEditDOB"));

        formLayout->setWidget(4, QFormLayout::FieldRole, dbDateEditDOB);


        horizontalLayout->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(PatientEditView);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(PatientEditView);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 44, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        retranslateUi(PatientEditView);

        QMetaObject::connectSlotsByName(PatientEditView);
    } // setupUi

    void retranslateUi(QWidget *PatientEditView)
    {
        PatientEditView->setWindowTitle(QApplication::translate("PatientEditView", "\347\274\226\350\276\221\346\202\243\350\200\205\344\277\241\346\201\257", nullptr));
        label->setText(QApplication::translate("PatientEditView", "ID\357\274\232", nullptr));
        label_2->setText(QApplication::translate("PatientEditView", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_4->setText(QApplication::translate("PatientEditView", "\350\272\253\344\273\275\350\257\201\357\274\232", nullptr));
        label_3->setText(QApplication::translate("PatientEditView", "\346\200\247\345\210\253\357\274\232", nullptr));
        dbComboSex->setItemText(0, QApplication::translate("PatientEditView", "\347\224\267", nullptr));
        dbComboSex->setItemText(1, QApplication::translate("PatientEditView", "\345\245\263", nullptr));

        label_7->setText(QApplication::translate("PatientEditView", "\345\207\272\347\224\237\346\227\245\346\234\237\357\274\232", nullptr));
        label_6->setText(QApplication::translate("PatientEditView", "\350\272\253\351\253\230\357\274\232", nullptr));
        label_5->setText(QApplication::translate("PatientEditView", "\344\275\223\351\207\215\357\274\232", nullptr));
        label_8->setText(QApplication::translate("PatientEditView", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        label_9->setText(QApplication::translate("PatientEditView", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("PatientEditView", "\344\277\235\345\255\230", nullptr));
        pushButton_2->setText(QApplication::translate("PatientEditView", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientEditView: public Ui_PatientEditView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTEDITVIEW_H
