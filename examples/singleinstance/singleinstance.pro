#-------------------------------------------------
#
# Project created by QtCreator 2017-09-21T18:55:23
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = appsingleinstance
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
  main.cpp \
  MainWindow.cpp

HEADERS  += \
  MainWindow.h

DESTDIR = ../

win32:CONFIG(release, debug|release): LIBS += \
  -L$$OUT_PWD/../../com/ecosoftware/ -lsingleinstance
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$OUT_PWD/../../com/ecosoftware/ -lsingleinstance
else:unix: LIBS += \
  -L$$OUT_PWD/../../com/ecosoftware/ -lsingleinstance

INCLUDEPATH += $$PWD/../../com/ecosoftware/singleinstance
DEPENDPATH += $$PWD/../../com/ecosoftware/singleinstance
