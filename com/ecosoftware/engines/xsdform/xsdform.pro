#-------------------------------------------------
#
# Project created by QtCreator 2018-03-06T13:54:13
#
#-------------------------------------------------

QT       -= gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml

TARGET = xsdform
TEMPLATE = lib

DEFINES += XSDFORM_LIBRARY

SOURCES += \
  XsdDialog.cpp \
  XsdFormCreator.cpp

HEADERS += \
  xsdform_global.h \
  XsdDialog.h \
  XsdFormCreator.h

DESTDIR = ../

UI_DIR = ../../../../ui

win32:CONFIG(release, debug|release): LIBS += \
  -L$$OUT_PWD/../ -lxsd \
  -L$$OUT_PWD/../../ -lapp \
  -L$$OUT_PWD/../../ -lresources \
  -L$$OUT_PWD/../../ -lutils
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$OUT_PWD/../ -lxsd \
  -L$$OUT_PWD/../../ -lapp \
  -L$$OUT_PWD/../../ -lresources \
  -L$$OUT_PWD/../../ -lutils
else:unix: LIBS += \
  -L$$OUT_PWD/../ -lxsd \
  -L$$OUT_PWD/../../ -lapp \
  -L$$OUT_PWD/../../ -lresources \
  -L$$OUT_PWD/../../ -lutils

INCLUDEPATH += \
  $$PWD/../xsd \
  $$PWD/../../app \
  $$PWD/../../resources \
  $$PWD/../../utils

DEPENDPATH += \
  $$PWD/../xsd \
  $$PWD/../../app \
  $$PWD/../../resources \
  $$PWD/../../utils

unix {
    target.path = /usr/lib
    INSTALLS += target
}
