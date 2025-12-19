/********************************************************************************
** Form generated from reading UI file 'replacedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACEDIALOG_H
#define UI_REPLACEDIALOG_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReplaceDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *searchText;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *targetText;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *cbCaseSensetive;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbUp;
    QRadioButton *rbDown;
    QVBoxLayout *verticalLayout;
    QPushButton *btFindNext;
    QPushButton *btReplace;
    QPushButton *btReplaceAll;
    QPushButton *btCancel;

    void setupUi(QDialog *ReplaceDialog)
    {
        if (ReplaceDialog->objectName().isEmpty())
            ReplaceDialog->setObjectName(QString::fromUtf8("ReplaceDialog"));
        ReplaceDialog->resize(450, 170);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ReplaceDialog->sizePolicy().hasHeightForWidth());
        ReplaceDialog->setSizePolicy(sizePolicy);
        ReplaceDialog->setMinimumSize(QSize(450, 170));
        ReplaceDialog->setMaximumSize(QSize(450, 170));
        layoutWidget = new QWidget(ReplaceDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 425, 137));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(75, 0));

        horizontalLayout_4->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        searchText = new QLineEdit(layoutWidget);
        searchText->setObjectName(QString::fromUtf8("searchText"));

        horizontalLayout_2->addWidget(searchText);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(75, 0));

        horizontalLayout_5->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        targetText = new QLineEdit(layoutWidget);
        targetText->setObjectName(QString::fromUtf8("targetText"));

        horizontalLayout_3->addWidget(targetText);


        horizontalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        cbCaseSensetive = new QCheckBox(layoutWidget);
        cbCaseSensetive->setObjectName(QString::fromUtf8("cbCaseSensetive"));

        horizontalLayout_6->addWidget(cbCaseSensetive);

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


        horizontalLayout_6->addWidget(groupBox);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout_7->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btFindNext = new QPushButton(layoutWidget);
        btFindNext->setObjectName(QString::fromUtf8("btFindNext"));

        verticalLayout->addWidget(btFindNext);

        btReplace = new QPushButton(layoutWidget);
        btReplace->setObjectName(QString::fromUtf8("btReplace"));

        verticalLayout->addWidget(btReplace);

        btReplaceAll = new QPushButton(layoutWidget);
        btReplaceAll->setObjectName(QString::fromUtf8("btReplaceAll"));

        verticalLayout->addWidget(btReplaceAll);

        btCancel = new QPushButton(layoutWidget);
        btCancel->setObjectName(QString::fromUtf8("btCancel"));

        verticalLayout->addWidget(btCancel);


        horizontalLayout_7->addLayout(verticalLayout);


        retranslateUi(ReplaceDialog);

        QMetaObject::connectSlotsByName(ReplaceDialog);
    } // setupUi

    void retranslateUi(QDialog *ReplaceDialog)
    {
        ReplaceDialog->setWindowTitle(QApplication::translate("ReplaceDialog", "\346\233\277\346\215\242", nullptr));
        label->setText(QApplication::translate("ReplaceDialog", "\346\237\245\346\211\276\347\233\256\346\240\207\357\274\232", nullptr));
        label_2->setText(QApplication::translate("ReplaceDialog", "\346\233\277\346\215\242\344\270\272:", nullptr));
        cbCaseSensetive->setText(QApplication::translate("ReplaceDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        groupBox->setTitle(QApplication::translate("ReplaceDialog", "\346\226\271\345\220\221", nullptr));
        rbUp->setText(QApplication::translate("ReplaceDialog", "\345\220\221\344\270\212(&U)", nullptr));
        rbDown->setText(QApplication::translate("ReplaceDialog", "\345\220\221\344\270\213(&D)", nullptr));
        btFindNext->setText(QApplication::translate("ReplaceDialog", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252(&F)", nullptr));
        btReplace->setText(QApplication::translate("ReplaceDialog", "\346\233\277\346\215\242(&R)", nullptr));
        btReplaceAll->setText(QApplication::translate("ReplaceDialog", "\345\205\250\351\203\250\346\233\277\346\215\242(&A)", nullptr));
        btCancel->setText(QApplication::translate("ReplaceDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReplaceDialog: public Ui_ReplaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEDIALOG_H
