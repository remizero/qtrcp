#-------------------------------------------------
#
# Project created by QtCreator 2017-11-10T08:40:08
#
#-------------------------------------------------

QT       -= gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml xmlpatterns

TARGET = xsdengine
TEMPLATE = lib

DEFINES += XSDENGINE_LIBRARY

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
  XsdEngine.cpp \
  XsdFormCreator.cpp \
  XsdFormElement.cpp \
  XsdFormEngine.cpp \
  Element.cpp \
  Attribute.cpp \
  Type.cpp \
  XsdClassCreator.cpp \
  XsdXmlCreator.cpp \
  Property.cpp \
  Facet.cpp

HEADERS += \
  xsdengine_global.h \
  XsdEngine.h \
  XsdFormCreator.h \
  XsdFormElement.h \
  XsdFormEngine.h \
  Element.h \
  Attribute.h \
  Type.h \
  XsdClassCreator.h \
  XsdXmlCreator.h \
  Property.h \
  Facet.h

DESTDIR = ../

UI_DIR = ../../../ui

win32:CONFIG(release, debug|release): LIBS += \
  -L$$OUT_PWD/../../ -lresources
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$OUT_PWD/../../ -lresources
else:unix: LIBS += \
  -L$$OUT_PWD/../../ -lresources

INCLUDEPATH += \
  $$PWD/../../resources

DEPENDPATH += \
  $$PWD/../../resources

unix {
    target.path = /usr/lib
    INSTALLS += target
}
