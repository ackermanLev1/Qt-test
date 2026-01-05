QT       += core gui sql widgets
TARGET = LibrarySystem
TEMPLATE = app
SOURCES += main.cpp \
           databasemanager.cpp \
           mainwindow.cpp \
           bookmanage.cpp \
           borrowmanage.cpp \
           readermanage.cpp
HEADERS  += mainwindow.h \
            bookmanage.h \
            borrowmanage.h \
            databasemanager.h \
            mainwindow.h \
            readermanage.h
FORMS    += mainwindow.ui \
            bookmanage.ui \
            borrowmanage.ui \
            readermanage.ui
