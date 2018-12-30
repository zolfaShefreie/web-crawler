#-------------------------------------------------
#
# Project created by QtCreator 2018-12-19T06:04:22
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = web-crawler
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    node.cpp \
    tree_node.cpp \
    download_files.cpp \
    result_page.cpp

HEADERS  += mainwindow.h \
    node.h \
    tree_node.h \
    download_files.h \
    result_page.h

FORMS    += mainwindow.ui \
    result_page.ui

RESOURCES += \
    gif/gif.qrc \
    icon/icons.qrc
