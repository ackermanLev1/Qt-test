/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AboutDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(40, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        label = new QLabel(AboutDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 331, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(28);
        label->setFont(font);
        label_5 = new QLabel(AboutDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 80, 111, 141));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(:/img/logo.jpg);"));
        label_6 = new QLabel(AboutDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 260, 171, 16));
        layoutWidget = new QWidget(AboutDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(180, 120, 193, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);


        retranslateUi(AboutDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AboutDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AboutDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "\345\205\263\344\272\216", nullptr));
        label->setText(QApplication::translate("AboutDialog", "\345\260\217\344\271\235\346\226\207\346\234\254\347\274\226\350\276\221\345\231\250", nullptr));
        label_5->setText(QString());
        label_6->setText(QApplication::translate("AboutDialog", "V1.0 build 20251111", nullptr));
        label_3->setText(QApplication::translate("AboutDialog", "\345\255\246\345\217\267\357\274\2322023414290338", nullptr));
        label_2->setText(QApplication::translate("AboutDialog", "\345\274\200\345\217\221\350\200\205\357\274\232\351\203\221\345\273\267\351\224\264", nullptr));
        label_4->setText(QApplication::translate("AboutDialog", "email\357\274\2321304508605@qq.com", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
