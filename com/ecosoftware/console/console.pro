#-------------------------------------------------
#
# Project created by QtCreator 2017-02-12T20:28:17
#
#-------------------------------------------------

QT       -= gui

CONFIG += c++17

greaterThan(QT_MAJOR_VERSION, 4): QT +=

TARGET = console
TEMPLATE = lib

DEFINES += CONSOLE_LIBRARY

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
  Console.cpp

HEADERS += \
  console_global.h \
  Console.h

DESTDIR = ../

UI_DIR = ../../../ui

win32:CONFIG(release, debug|release): LIBS += \
  -L$$OUT_PWD/../ -lmacros
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$OUT_PWD/../ -lmacros
else:unix: LIBS += \
  -L$$OUT_PWD/../ -lmacros

INCLUDEPATH += \
  $$PWD/../macros

DEPENDPATH += \
  $$PWD/../macros

unix {
  target.path = /usr/lib
    INSTALLS += target
}
