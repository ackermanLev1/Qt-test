QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# 源文件
SOURCES += \
    adminview.cpp \
    databasemanager.cpp \
    loginview.cpp \
    main.cpp \
    readerview.cpp

# 头文件
HEADERS += \
    adminview.h \
    databasemanager.h \
    loginview.h \
    readerview.h

# UI文件
FORMS += \
    adminview.ui \
    loginview.ui \
    readerview.ui

# 输出目录
DESTDIR = ./bin

# 确保编译器能找到当前目录中的所有文件
INCLUDEPATH += .

# 设置可执行文件名称
TARGET = BookLendingSystem

# 清理设置
MOC_DIR = moc
OBJECTS_DIR = obj
RCC_DIR = rcc
UI_DIR = ui
