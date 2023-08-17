#-------------------------------------------------
#
# Project created by QtCreator 2017-02-12T18:41:54
#
#-------------------------------------------------

QT       -= gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml #xmlpatterns

TARGET = menubar
TEMPLATE = lib

DEFINES += MENUBAR_LIBRARY

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
  Menu.cpp \
  MenuBar.cpp

HEADERS += \
  menubar_global.h \
  Menu.h \
  MenuBar.h

DESTDIR = ../

UI_DIR = ../../../../../ui

win32:CONFIG(release, debug|release): LIBS += \
  -L$$OUT_PWD/../../../ -lapp \
  -L$$OUT_PWD/../../../ -lutils \
  -L$$OUT_PWD/../../../engines/ -lxsd \
  -L$$OUT_PWD/../../../engines/ -lxsdform \
  -L$$OUT_PWD/../ -lactions
  #-L$$OUT_PWD/../../ -lmainwindow
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$OUT_PWD/../../../ -lapp \
  -L$$OUT_PWD/../../../ -lutils \
  -L$$OUT_PWD/../../../engines/ -lxsd \
  -L$$OUT_PWD/../../../engines/ -lxsdform \
  -L$$OUT_PWD/../ -lactions
  #-L$$OUT_PWD/../../ -lmainwindow
else:unix: LIBS += \
  -L$$OUT_PWD/../../../ -lapp \
  -L$$OUT_PWD/../../../ -lutils \
  -L$$OUT_PWD/../../../engines/ -lxsd \
  -L$$OUT_PWD/../../../engines/ -lxsdform \
  -L$$OUT_PWD/../ -lactions
  #-L$$OUT_PWD/../../ -lmainwindow

INCLUDEPATH += \
  $$PWD/../../../app \
  $$PWD/../../../utils \
  $$PWD/../../../engines/xsd \
  $$PWD/../../../engines/xsdform \
  $$PWD/../actions
  #$$PWD/../../mainwindow

DEPENDPATH += \
  $$PWD/../../../app \
  $$PWD/../../../utils \
  $$PWD/../../../engines/xsd \
  $$PWD/../../../engines/xsdform \
  $$PWD/../actions
  #$$PWD/../../mainwindow

unix {
    target.path = /usr/lib
    INSTALLS += target
}
