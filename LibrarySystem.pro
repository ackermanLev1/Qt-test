QT       += core gui widgets sql

TARGET = LibrarySystem
TEMPLATE = app

# 配置C++标准
CONFIG += c++11

SOURCES += \
        databasemanager.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        databasemanager.h \
        mainwindow.h
# 资源文件（可选，如图片）
# RESOURCES += \
#        resources.qrc
