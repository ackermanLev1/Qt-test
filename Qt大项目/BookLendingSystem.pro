QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# 源文件
SOURCES += \
    adminview.cpp \
    databasemanager.cpp \
    loginview.cpp \
    main.cpp \
    mainwindow.cpp \
    readerview.cpp

# 头文件
HEADERS += \
    adminview.h \
    databasemanager.h \
    loginview.h \
    mainwindow.h \
    readerview.h

# UI文件
FORMS += \
    adminview.ui \
    loginview.ui \
    mainwindow.ui \
    readerview.ui
