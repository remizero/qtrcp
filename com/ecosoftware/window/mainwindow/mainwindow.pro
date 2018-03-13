#-------------------------------------------------
#
# Project created by QtCreator 2017-02-12T18:39:17
#
#-------------------------------------------------

QT       -= gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml xmlpatterns

TARGET = mainwindow
TEMPLATE = lib

DEFINES += MAINWINDOW_LIBRARY

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
  MainWindow.cpp \
  MainWindowActions.cpp \
  MainWindowEvents.cpp \
  MainWindowSignals.cpp \
  MainWindowSlots.cpp

HEADERS += \
  mainwindow_global.h \
  MainWindow.h \
  MainWindowActions.h \
  MainWindowEvents.h \
  MainWindowSignals.h \
  MainWindowSlots.h

DESTDIR = ../

UI_DIR = ../../../../ui

win32:CONFIG(release, debug|release): LIBS += \
  -L$$OUT_PWD/../../ -lapp \
  -L$$OUT_PWD/../../ -lutils \
  -L$$OUT_PWD/../../engines/ -lxsd \
  -L$$OUT_PWD/../../engines/ -lxsdform \
  -L$$OUT_PWD/../components/ -lactions \
  -L$$OUT_PWD/../components/ -lmenubar \
  -L$$OUT_PWD/../components/ -lstatusbar \
  -L$$OUT_PWD/../components/ -lsystemtrayicon
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$OUT_PWD/../../ -lapp \
  -L$$OUT_PWD/../../ -lutils \
  -L$$OUT_PWD/../../engines/ -lxsd \
  -L$$OUT_PWD/../../engines/ -lxsdform \
  -L$$OUT_PWD/../components/ -lactions \
  -L$$OUT_PWD/../components/ -lmenubar \
  -L$$OUT_PWD/../components/ -lstatusbar \
  -L$$OUT_PWD/../components/ -lsystemtrayicon
else:unix: LIBS += \
  -L$$OUT_PWD/../../ -lapp \
  -L$$OUT_PWD/../../ -lutils \
  -L$$OUT_PWD/../../engines/ -lxsd \
  -L$$OUT_PWD/../../engines/ -lxsdform \
  -L$$OUT_PWD/../components/ -lactions \
  -L$$OUT_PWD/../components/ -lmenubar \
  -L$$OUT_PWD/../components/ -lstatusbar \
  -L$$OUT_PWD/../components/ -lsystemtrayicon

INCLUDEPATH += \
  $$PWD/../../app \
  $$PWD/../../utils \
  $$PWD/../../engines/xsd \
  $$PWD/../../engines/xsdform \
  $$PWD/../components/actions \
  $$PWD/../components/menubar \
  $$PWD/../components/statusbar \
  $$PWD/../components/systemtrayicon

DEPENDPATH += \
  $$PWD/../../app \
  $$PWD/../../utils \
  $$PWD/../../engines/xsd \
  $$PWD/../../engines/xsdform \
  $$PWD/../components/actions \
  $$PWD/../components/menubar \
  $$PWD/../components/statusbar \
  $$PWD/../components/systemtrayicon

unix {
    target.path = /usr/lib
    INSTALLS += target
}
