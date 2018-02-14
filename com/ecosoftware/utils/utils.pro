#-------------------------------------------------
#
# Project created by QtCreator 2017-11-17T14:39:19
#
#-------------------------------------------------

QT       -= gui

TARGET = utils
TEMPLATE = lib

DEFINES += UTILS_LIBRARY

SOURCES += \
  Enumeration.cpp \
  Utils.cpp \
    Strings.cpp

HEADERS += \
  utils_global.h \
  Enumeration.h \
  Utils.h \
    Strings.h

DESTDIR = ../

UI_DIR = ../../../ui

unix {
    target.path = /usr/lib
    INSTALLS += target
}
