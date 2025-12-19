/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *btnDivide;
    QPushButton *btnClear;
    QPushButton *btnMinus;
    QPushButton *btnNum9;
    QPushButton *btnEqual;
    QPushButton *btnNum3;
    QPushButton *btnNum8;
    QPushButton *btnNum6;
    QPushButton *btnNum0;
    QPushButton *btnMultiply;
    QPushButton *btnInverse;
    QPushButton *btnNum2;
    QPushButton *btnSquareRoot;
    QPushButton *btnSign;
    QPushButton *btnDelete;
    QPushButton *btnCLearAll;
    QPushButton *btnNum4;
    QPushButton *btnPercent;
    QPushButton *btnNum1;
    QPushButton *btnNum7;
    QPushButton *btnNum5;
    QPushButton *btnPeriod;
    QPushButton *btnSquare;
    QPushButton *btnAdd;
    QLineEdit *display;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(512, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgb(246, 246, 246);\n"
"	font-size:24pt;\n"
"	color:black;\n"
"	border-radius:2px;	\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"	background-color:rgb(222, 255, 222);\n"
"}\n"
"\n"
"QPushButton::pressed{\n"
"	background-color:rgb(191, 255, 191);\n"
"}\n"
"\n"
"QLineEdit{\n"
"	font-size:40pt;\n"
"	color:black;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(1, 1, 1, 1);
        btnDivide = new QPushButton(centralwidget);
        btnDivide->setObjectName(QString::fromUtf8("btnDivide"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnDivide->sizePolicy().hasHeightForWidth());
        btnDivide->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnDivide, 2, 3, 1, 1);

        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        sizePolicy.setHeightForWidth(btnClear->sizePolicy().hasHeightForWidth());
        btnClear->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnClear, 1, 2, 1, 1);

        btnMinus = new QPushButton(centralwidget);
        btnMinus->setObjectName(QString::fromUtf8("btnMinus"));
        sizePolicy.setHeightForWidth(btnMinus->sizePolicy().hasHeightForWidth());
        btnMinus->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnMinus, 4, 3, 1, 1);

        btnNum9 = new QPushButton(centralwidget);
        btnNum9->setObjectName(QString::fromUtf8("btnNum9"));
        sizePolicy.setHeightForWidth(btnNum9->sizePolicy().hasHeightForWidth());
        btnNum9->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnNum9, 3, 2, 1, 1);

        btnEqual = new QPushButton(centralwidget);
        btnEqual->setObjectName(QString::fromUtf8("btnEqual"));
        sizePolicy.setHeightForWidth(btnEqual->sizePolicy().hasHeightForWidth());
        btnEqual->setSizePolicy(sizePolicy);
        btnEqual->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color:rgb(29, 105, 120);\n"
"	color:white;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"	background-color:rgb(51, 119, 133);\n"
"}\n"
"\n"
"QPushButton::pressed{\n"
"	background-color:rgb(72, 133, 145);\n"
"}"));

        gridLayout_2->addWidget(btnEqual, 6, 3, 1, 1);

        btnNum3 = new QPushButton(centralwidget);
        btnNum3->setObjectName(QString::fromUtf8("btnNum3"));
        sizePolicy.setHeightForWidth(btnNum3->sizePolicy().hasHeightForWidth());
        btnNum3->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnNum3, 5, 2, 1, 1);

        btnNum8 = new QPushButton(centralwidget);
        btnNum8->setObjectName(QString::fromUtf8("btnNum8"));
        sizePolicy.setHeightForWidth(btnNum8->sizePolicy().hasHeightForWidth());
        btnNum8->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnNum8, 3, 1, 1, 1);

        btnNum6 = new QPushButton(centralwidget);
        btnNum6->setObjectName(QString::fromUtf8("btnNum6"));
        sizePolicy.setHeightForWidth(btnNum6->sizePolicy().hasHeightForWidth());
        btnNum6->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnNum6, 4, 2, 1, 1);

        btnNum0 = new QPushButton(centralwidget);
        btnNum0->setObjectName(QString::fromUtf8("btnNum0"));
        sizePolicy.setHeightForWidth(btnNum0->sizePolicy().hasHeightForWidth());
        btnNum0->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnNum0, 6, 1, 1, 1);

        btnMultiply = new QPushButton(centralwidget);
        btnMultiply->setObjectName(QString::fromUtf8("btnMultiply"));
        sizePolicy.setHeightForWidth(btnMultiply->sizePolicy().hasHeightForWidth());
        btnMultiply->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnMultiply, 3, 3, 1, 1);

        btnInverse = new QPushButton(centralwidget);
        btnInverse->setObjectName(QString::fromUtf8("btnInverse"));
        sizePolicy.setHeightForWidth(btnInverse->sizePolicy().hasHeightForWidth());
        btnInverse->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnInverse, 2, 0, 1, 1);

        btnNum2 = new QPushButton(centralwidget);
        btnNum2->setObjectName(QString::fromUtf8("btnNum2"));
        sizePolicy.setHeightForWidth(btnNum2->sizePolicy().hasHeightForWidth());
        btnNum2->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnNum2, 5, 1, 1, 1);

        btnSquareRoot = new QPushButton(centralwidget);
        btnSquareRoot->setObjectName(QString::fromUtf8("btnSquareRoot"));
        sizePolicy.setHeightForWidth(btnSquareRoot->sizePolicy().hasHeightForWidth());
        btnSquareRoot->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnSquareRoot, 2, 2, 1, 1);

        btnSign = new QPushButton(centralwidget);
        btnSign->setObjectName(QString::fromUtf8("btnSign"));
        sizePolicy.setHeightForWidth(btnSign->sizePolicy().hasHeightForWidth());
        btnSign->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnSign, 6, 0, 1, 1);

        btnDelete = new QPushButton(centralwidget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        sizePolicy.setHeightForWidth(btnDelete->sizePolicy().hasHeightForWidth());
        btnDelete->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnDelete, 1, 3, 1, 1);

        btnCLearAll = new QPushButton(centralwidget);
        btnCLearAll->setObjectName(QString::fromUtf8("btnCLearAll"));
        sizePolicy.setHeightForWidth(btnCLearAll->sizePolicy().hasHeightForWidth());
        btnCLearAll->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnCLearAll, 1, 1, 1, 1);

        btnNum4 = new QPushButton(centralwidget);
        btnNum4->setObjectName(QString::fromUtf8("btnNum4"));
        sizePolicy.setHeightForWidth(btnNum4->sizePolicy().hasHeightForWidth());
        btnNum4->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnNum4, 4, 0, 1, 1);

        btnPercent = new QPushButton(centralwidget);
        btnPercent->setObjectName(QString::fromUtf8("btnPercent"));
        sizePolicy.setHeightForWidth(btnPercent->sizePolicy().hasHeightForWidth());
        btnPercent->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnPercent, 1, 0, 1, 1);

        btnNum1 = new QPushButton(centralwidget);
        btnNum1->setObjectName(QString::fromUtf8("btnNum1"));
        sizePolicy.setHeightForWidth(btnNum1->sizePolicy().hasHeightForWidth());
        btnNum1->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnNum1, 5, 0, 1, 1);

        btnNum7 = new QPushButton(centralwidget);
        btnNum7->setObjectName(QString::fromUtf8("btnNum7"));
        sizePolicy.setHeightForWidth(btnNum7->sizePolicy().hasHeightForWidth());
        btnNum7->setSizePolicy(sizePolicy);
        btnNum7->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(btnNum7, 3, 0, 1, 1);

        btnNum5 = new QPushButton(centralwidget);
        btnNum5->setObjectName(QString::fromUtf8("btnNum5"));
        sizePolicy.setHeightForWidth(btnNum5->sizePolicy().hasHeightForWidth());
        btnNum5->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnNum5, 4, 1, 1, 1);

        btnPeriod = new QPushButton(centralwidget);
        btnPeriod->setObjectName(QString::fromUtf8("btnPeriod"));
        sizePolicy.setHeightForWidth(btnPeriod->sizePolicy().hasHeightForWidth());
        btnPeriod->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnPeriod, 6, 2, 1, 1);

        btnSquare = new QPushButton(centralwidget);
        btnSquare->setObjectName(QString::fromUtf8("btnSquare"));
        sizePolicy.setHeightForWidth(btnSquare->sizePolicy().hasHeightForWidth());
        btnSquare->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnSquare, 2, 1, 1, 1);

        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        sizePolicy.setHeightForWidth(btnAdd->sizePolicy().hasHeightForWidth());
        btnAdd->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(btnAdd, 5, 3, 1, 1);

        display = new QLineEdit(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(display->sizePolicy().hasHeightForWidth());
        display->setSizePolicy(sizePolicy1);
        display->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(display, 0, 0, 1, 4);


        verticalLayout->addLayout(gridLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 512, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\256\241\347\256\227\345\231\250-\345\274\240\350\200\277\344\272\256-2023414290336", nullptr));
        btnDivide->setText(QApplication::translate("MainWindow", "/", nullptr));
        btnClear->setText(QApplication::translate("MainWindow", "C", nullptr));
        btnMinus->setText(QApplication::translate("MainWindow", "-", nullptr));
        btnNum9->setText(QApplication::translate("MainWindow", "9", nullptr));
        btnEqual->setText(QApplication::translate("MainWindow", "=", nullptr));
        btnNum3->setText(QApplication::translate("MainWindow", "3", nullptr));
        btnNum8->setText(QApplication::translate("MainWindow", "8", nullptr));
        btnNum6->setText(QApplication::translate("MainWindow", "6", nullptr));
        btnNum0->setText(QApplication::translate("MainWindow", "0", nullptr));
        btnMultiply->setText(QApplication::translate("MainWindow", "\303\227", nullptr));
        btnInverse->setText(QApplication::translate("MainWindow", "1/x", nullptr));
        btnNum2->setText(QApplication::translate("MainWindow", "2", nullptr));
        btnSquareRoot->setText(QApplication::translate("MainWindow", "\342\210\232x", nullptr));
        btnSign->setText(QApplication::translate("MainWindow", "\302\261", nullptr));
        btnDelete->setText(QApplication::translate("MainWindow", "\342\214\253", nullptr));
        btnCLearAll->setText(QApplication::translate("MainWindow", "CE", nullptr));
        btnNum4->setText(QApplication::translate("MainWindow", "4", nullptr));
        btnPercent->setText(QApplication::translate("MainWindow", "%", nullptr));
        btnNum1->setText(QApplication::translate("MainWindow", "1", nullptr));
        btnNum7->setText(QApplication::translate("MainWindow", "7", nullptr));
        btnNum5->setText(QApplication::translate("MainWindow", "5", nullptr));
        btnPeriod->setText(QApplication::translate("MainWindow", ".", nullptr));
        btnSquare->setText(QApplication::translate("MainWindow", "x^2", nullptr));
        btnAdd->setText(QApplication::translate("MainWindow", "+", nullptr));
        display->setPlaceholderText(QApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
