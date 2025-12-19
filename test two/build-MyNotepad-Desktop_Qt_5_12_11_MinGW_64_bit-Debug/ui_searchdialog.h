/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbUp;
    QRadioButton *rbDown;
    QVBoxLayout *verticalLayout;
    QPushButton *btFindNext;
    QSpacerItem *verticalSpacer;
    QPushButton *btCancel;

    void setupUi(QDialog *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName(QString::fromUtf8("SearchDialog"));
        SearchDialog->resize(457, 146);
        layoutWidget = new QWidget(SearchDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 431, 121));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_3->addWidget(checkBox);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rbUp = new QRadioButton(groupBox);
        rbUp->setObjectName(QString::fromUtf8("rbUp"));

        horizontalLayout->addWidget(rbUp);

        rbDown = new QRadioButton(groupBox);
        rbDown->setObjectName(QString::fromUtf8("rbDown"));

        horizontalLayout->addWidget(rbDown);


        horizontalLayout_3->addWidget(groupBox);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btFindNext = new QPushButton(layoutWidget);
        btFindNext->setObjectName(QString::fromUtf8("btFindNext"));

        verticalLayout->addWidget(btFindNext);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btCancel = new QPushButton(layoutWidget);
        btCancel->setObjectName(QString::fromUtf8("btCancel"));

        verticalLayout->addWidget(btCancel);


        horizontalLayout_5->addLayout(verticalLayout);


        retranslateUi(SearchDialog);

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchDialog)
    {
        SearchDialog->setWindowTitle(QApplication::translate("SearchDialog", "\346\237\245\346\211\276", nullptr));
        label->setText(QApplication::translate("SearchDialog", "\346\237\245\346\211\276\347\233\256\346\240\207\357\274\232", nullptr));
        checkBox->setText(QApplication::translate("SearchDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        groupBox->setTitle(QApplication::translate("SearchDialog", "\346\226\271\345\220\221", nullptr));
        rbUp->setText(QApplication::translate("SearchDialog", "\345\220\221\344\270\212(&U)", nullptr));
        rbDown->setText(QApplication::translate("SearchDialog", "\345\220\221\344\270\213(&D)", nullptr));
        btFindNext->setText(QApplication::translate("SearchDialog", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252(&F)", nullptr));
        btCancel->setText(QApplication::translate("SearchDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
