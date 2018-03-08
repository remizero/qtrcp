#-------------------------------------------------
#
# Project created by QtCreator 2017-11-17T14:39:19
#
#-------------------------------------------------

QT       -= gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml xmlpatterns

TARGET = utils
TEMPLATE = lib

DEFINES += UTILS_LIBRARY

SOURCES += \
  Enumeration.cpp \
  Utils.cpp \
    Strings.cpp \
    Files.cpp \
    Xml.cpp

HEADERS += \
  utils_global.h \
  Enumeration.h \
  Utils.h \
    Strings.h \
    Files.h \
    Xml.h

DESTDIR = ../

UI_DIR = ../../../ui

unix {
    target.path = /usr/lib
    INSTALLS += target
}
