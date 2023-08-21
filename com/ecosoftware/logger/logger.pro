#-------------------------------------------------
#
# Project created by QtCreator 2018-03-08T09:02:30
#
#-------------------------------------------------

QT       -= gui

CONFIG += c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += core

TARGET = logger
TEMPLATE = lib

DEFINES += LOGGER_LIBRARY

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
  Logger.cpp

HEADERS += \
  logger_global.h \
  Logger.h

DESTDIR = ../

UI_DIR = ../../../ui
MOC_DIR = ../../../moc
OBJECTS_DIR = ../../../obj
RCC_DIR = ../../../rcc

win32:CONFIG(release, debug|release): LIBS += \
  -L$$OUT_PWD/../ -lmacros \
  -L$$OUT_PWD/../ -lapp
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$OUT_PWD/../ -lmacros \
  -L$$OUT_PWD/../ -lapp
else:unix: LIBS += \
  -L$$OUT_PWD/../ -lmacros \
  -L$$OUT_PWD/../ -lapp

INCLUDEPATH += \
  $$PWD/../macros \
  $$PWD/../app

DEPENDPATH += \
  $$PWD/../macros \
  $$PWD/../app

unix {
  target.path = /usr/lib
  INSTALLS += target
}
