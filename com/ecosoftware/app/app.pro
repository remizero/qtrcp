#-------------------------------------------------
#
# Project created by QtCreator 2017-02-12T17:56:09
#
#-------------------------------------------------

QT       -= gui

CONFIG += c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets core xml

TARGET = app
TEMPLATE = lib

DEFINES += APP_LIBRARY

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
  AppInfo.cpp \
  AppInit.cpp \
  AppSettings.cpp \
  AppUtils.cpp \
  AppPaths.cpp \
    App.cpp

HEADERS += \
  app_global.h \
  AppInfo.h \
  AppInit.h \
  AppSettings.h \
  AppUtils.h \
  AppPaths.h \
    App.h

DESTDIR = ../

UI_DIR = ../../../ui
MOC_DIR = ../../../moc
OBJECTS_DIR = ../../../obj
RCC_DIR = ../../../rcc

unix {
  target.path = /usr/lib
  INSTALLS += target
}
