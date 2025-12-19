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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <codeeditor.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionUndo;
    QAction *actionCut;
    QAction *actionExit;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionFind;
    QAction *actionReplace;
    QAction *actionFont;
    QAction *actionLineWrap;
    QAction *actionToolbar;
    QAction *actionStatus;
    QAction *actionRedo;
    QAction *actionSelectALl;
    QAction *actionLine;
    QAction *actionPrint;
    QAction *actionAbout;
    QAction *actionFontColor;
    QAction *actionFontBackgroundColor;
    QAction *action_BackgroundColor;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    CodeEditor *textEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_E;
    QMenu *menu_O;
    QMenu *menu_V;
    QMenu *menu_H;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/saveas.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveAs->setIcon(icon3);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon4);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon5);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon6);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon7);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon8);
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/find.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setIcon(icon9);
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName(QString::fromUtf8("actionReplace"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/replace.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReplace->setIcon(icon10);
        actionFont = new QAction(MainWindow);
        actionFont->setObjectName(QString::fromUtf8("actionFont"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/font.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFont->setIcon(icon11);
        actionLineWrap = new QAction(MainWindow);
        actionLineWrap->setObjectName(QString::fromUtf8("actionLineWrap"));
        actionLineWrap->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/wrap.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLineWrap->setIcon(icon12);
        actionToolbar = new QAction(MainWindow);
        actionToolbar->setObjectName(QString::fromUtf8("actionToolbar"));
        actionToolbar->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/bar.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionToolbar->setIcon(icon13);
        actionStatus = new QAction(MainWindow);
        actionStatus->setObjectName(QString::fromUtf8("actionStatus"));
        actionStatus->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/bar2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStatus->setIcon(icon14);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon15);
        actionSelectALl = new QAction(MainWindow);
        actionSelectALl->setObjectName(QString::fromUtf8("actionSelectALl"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/C:/Users/levi1/Downloads/img (2)/img/selceltall.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectALl->setIcon(icon16);
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName(QString::fromUtf8("actionLine"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/img/line.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionLine->setIcon(icon17);
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/img/print.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon18);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionFontColor = new QAction(MainWindow);
        actionFontColor->setObjectName(QString::fromUtf8("actionFontColor"));
        actionFontBackgroundColor = new QAction(MainWindow);
        actionFontBackgroundColor->setObjectName(QString::fromUtf8("actionFontBackgroundColor"));
        action_BackgroundColor = new QAction(MainWindow);
        action_BackgroundColor->setObjectName(QString::fromUtf8("action_BackgroundColor"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        textEdit = new CodeEditor(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_E = new QMenu(menubar);
        menu_E->setObjectName(QString::fromUtf8("menu_E"));
        menu_O = new QMenu(menubar);
        menu_O->setObjectName(QString::fromUtf8("menu_O"));
        menu_V = new QMenu(menubar);
        menu_V->setObjectName(QString::fromUtf8("menu_V"));
        menu_H = new QMenu(menubar);
        menu_H->setObjectName(QString::fromUtf8("menu_H"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_E->menuAction());
        menubar->addAction(menu_O->menuAction());
        menubar->addAction(menu_V->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu->addAction(actionNew);
        menu->addAction(actionOpen);
        menu->addAction(actionSave);
        menu->addAction(actionSaveAs);
        menu->addSeparator();
        menu->addAction(actionExit);
        menu_E->addAction(actionUndo);
        menu_E->addAction(actionRedo);
        menu_E->addAction(actionCut);
        menu_E->addAction(actionCopy);
        menu_E->addAction(actionPaste);
        menu_E->addSeparator();
        menu_E->addAction(actionFind);
        menu_E->addAction(actionReplace);
        menu_E->addSeparator();
        menu_E->addAction(actionSelectALl);
        menu_O->addAction(actionLineWrap);
        menu_O->addAction(actionLine);
        menu_O->addAction(actionFont);
        menu_O->addAction(actionFontColor);
        menu_O->addSeparator();
        menu_O->addAction(actionFontBackgroundColor);
        menu_O->addAction(action_BackgroundColor);
        menu_V->addAction(actionToolbar);
        menu_V->addAction(actionStatus);
        menu_H->addAction(actionAbout);
        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionSaveAs);
        toolBar->addSeparator();
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);
        toolBar->addAction(actionCut);
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionPaste);
        toolBar->addSeparator();
        toolBar->addAction(actionFind);
        toolBar->addAction(actionReplace);
        toolBar->addSeparator();
        toolBar->addAction(actionFont);
        toolBar->addAction(actionLine);
        toolBar->addAction(actionLineWrap);
        toolBar->addSeparator();
        toolBar->addAction(actionToolbar);
        toolBar->addAction(actionStatus);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\256\260\344\272\213\346\234\254", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSaveAs->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(&A)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSaveAs->setToolTip(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
#endif // QT_NO_TOOLTIP
        actionUndo->setText(QApplication::translate("MainWindow", "\346\222\244\351\224\200(&U)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionUndo->setToolTip(QApplication::translate("MainWindow", "\346\222\244\351\224\200", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionCut->setText(QApplication::translate("MainWindow", "\345\211\252\345\210\207(&T)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCut->setToolTip(QApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272(&X)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#endif // QT_NO_TOOLTIP
        actionCopy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266(&C)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCopy->setToolTip(QApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264(&P)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPaste->setToolTip(QApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionFind->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276(&F)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionFind->setToolTip(QApplication::translate("MainWindow", "\346\237\245\346\211\276", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionFind->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_NO_SHORTCUT
        actionReplace->setText(QApplication::translate("MainWindow", "\346\233\277\346\215\242(&R)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionReplace->setToolTip(QApplication::translate("MainWindow", "\346\233\277\346\215\242", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionReplace->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_NO_SHORTCUT
        actionFont->setText(QApplication::translate("MainWindow", "\345\255\227\344\275\223(&F)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionFont->setToolTip(QApplication::translate("MainWindow", "\345\255\227\344\275\223", nullptr));
#endif // QT_NO_TOOLTIP
        actionLineWrap->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214(&W)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionLineWrap->setToolTip(QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
#endif // QT_NO_TOOLTIP
        actionToolbar->setText(QApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217(&T)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionToolbar->setToolTip(QApplication::translate("MainWindow", "\345\267\245\345\205\267\346\240\217", nullptr));
#endif // QT_NO_TOOLTIP
        actionStatus->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217(&S)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionStatus->setToolTip(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", nullptr));
#endif // QT_NO_TOOLTIP
        actionRedo->setText(QApplication::translate("MainWindow", "\346\201\242\345\244\215(&)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRedo->setToolTip(QApplication::translate("MainWindow", "\346\201\242\345\244\215", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionSelectALl->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211(&A)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSelectALl->setToolTip(QApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSelectALl->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionLine->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\350\241\214\345\217\267(&L)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionLine->setToolTip(QApplication::translate("MainWindow", "\346\230\276\347\244\272\350\241\214\345\217\267", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionLine->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_NO_SHORTCUT
        actionPrint->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPrint->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\215\260", nullptr));
#endif // QT_NO_TOOLTIP
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216(&A)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216                                                       ", nullptr));
#endif // QT_NO_TOOLTIP
        actionFontColor->setText(QApplication::translate("MainWindow", "\345\255\227\344\275\223\351\242\234\350\211\262", nullptr));
        actionFontBackgroundColor->setText(QApplication::translate("MainWindow", "\345\255\227\344\275\223\350\203\214\346\231\257\350\211\262", nullptr));
#ifndef QT_NO_TOOLTIP
        actionFontBackgroundColor->setToolTip(QApplication::translate("MainWindow", "\345\255\227\344\275\223\350\203\214\346\231\257\350\211\262", nullptr));
#endif // QT_NO_TOOLTIP
        action_BackgroundColor->setText(QApplication::translate("MainWindow", "\347\274\226\350\276\221\345\231\250\350\203\214\346\231\257\350\211\262", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", nullptr));
        menu_O->setTitle(QApplication::translate("MainWindow", "\346\240\274\345\274\217(&O)", nullptr));
        menu_V->setTitle(QApplication::translate("MainWindow", "\346\237\245\347\234\213(&V)", nullptr));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
