#-------------------------------------------------
#
# Project created by QtCreator 2017-11-17T14:39:19
#
#-------------------------------------------------

QT       -= gui

CONFIG += c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml

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
