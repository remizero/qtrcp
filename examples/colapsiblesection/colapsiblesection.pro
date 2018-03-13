#-------------------------------------------------
#
# Project created by QtCreator 2018-03-13T13:54:52
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = colapsiblesection
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Section.cpp

HEADERS  += MainWindow.h \
    Section.h

FORMS += \
    mainwindow.ui
