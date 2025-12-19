/********************************************************************************
** Form generated from reading UI file 'paitentview.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAITENTVIEW_H
#define UI_PAITENTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PaitentView
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *txtSearch;
    QPushButton *btSearch;
    QPushButton *btAdd;
    QPushButton *btDelete;
    QPushButton *btEdit;
    QTableView *tableView;

    void setupUi(QWidget *PaitentView)
    {
        if (PaitentView->objectName().isEmpty())
            PaitentView->setObjectName(QString::fromUtf8("PaitentView"));
        PaitentView->resize(624, 630);
        verticalLayout = new QVBoxLayout(PaitentView);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        txtSearch = new QLineEdit(PaitentView);
        txtSearch->setObjectName(QString::fromUtf8("txtSearch"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(txtSearch->sizePolicy().hasHeightForWidth());
        txtSearch->setSizePolicy(sizePolicy);
        txtSearch->setMinimumSize(QSize(200, 30));
        txtSearch->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(txtSearch);

        btSearch = new QPushButton(PaitentView);
        btSearch->setObjectName(QString::fromUtf8("btSearch"));
        btSearch->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(btSearch);

        btAdd = new QPushButton(PaitentView);
        btAdd->setObjectName(QString::fromUtf8("btAdd"));
        btAdd->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(btAdd);

        btDelete = new QPushButton(PaitentView);
        btDelete->setObjectName(QString::fromUtf8("btDelete"));
        btDelete->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(btDelete);

        btEdit = new QPushButton(PaitentView);
        btEdit->setObjectName(QString::fromUtf8("btEdit"));
        btEdit->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(btEdit);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(PaitentView);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(PaitentView);

        QMetaObject::connectSlotsByName(PaitentView);
    } // setupUi

    void retranslateUi(QWidget *PaitentView)
    {
        PaitentView->setWindowTitle(QApplication::translate("PaitentView", "\346\202\243\350\200\205\347\256\241\347\220\206", nullptr));
        btSearch->setText(QApplication::translate("PaitentView", "\346\237\245\346\211\276", nullptr));
        btAdd->setText(QApplication::translate("PaitentView", "\346\267\273\345\212\240", nullptr));
        btDelete->setText(QApplication::translate("PaitentView", "\345\210\240\351\231\244", nullptr));
        btEdit->setText(QApplication::translate("PaitentView", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PaitentView: public Ui_PaitentView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAITENTVIEW_H
