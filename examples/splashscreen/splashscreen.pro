#-------------------------------------------------
#
# Project created by QtCreator 2017-10-25T09:37:53
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml xmlpatterns

TARGET = appsplashscreen
TEMPLATE = app

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
  main.cpp \
  VentanaPrincipal.cpp

HEADERS  += \
  VentanaPrincipal.h

DESTDIR = ../

win32:CONFIG(release, debug|release): LIBS += \
  -L$$OUT_PWD/../../com/ecosoftware/ -lapp \
  -L$$OUT_PWD/../../com/ecosoftware/ -lutils \
  -L$$OUT_PWD/../../com/ecosoftware/ -lsingleinstance \
  -L$$OUT_PWD/../../com/ecosoftware/ -lsplashscreen \
  -L$$OUT_PWD/../../com/ecosoftware/ -lresources \
  -L$$OUT_PWD/../../com/ecosoftware/engines/ -lxsd \
  -L$$OUT_PWD/../../com/ecosoftware/engines/ -lxsdform \
  -L$$OUT_PWD/../../com/ecosoftware/window/components/ -lactions \
  -L$$OUT_PWD/../../com/ecosoftware/window/components/ -lmenubar \
  -L$$OUT_PWD/../../com/ecosoftware/window/components/ -lstatusbar \
  -L$$OUT_PWD/../../com/ecosoftware/window/ -lmainwindow
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$OUT_PWD/../../com/ecosoftware/ -lapp \
  -L$$OUT_PWD/../../com/ecosoftware/ -lutils \
  -L$$OUT_PWD/../../com/ecosoftware/ -lsingleinstance \
  -L$$OUT_PWD/../../com/ecosoftware/ -lsplashscreen \
  -L$$OUT_PWD/../../com/ecosoftware/ -lresources \
  -L$$OUT_PWD/../../com/ecosoftware/engines/ -lxsd \
  -L$$OUT_PWD/../../com/ecosoftware/engines/ -lxsdform \
  -L$$OUT_PWD/../../com/ecosoftware/window/components/ -lactions \
  -L$$OUT_PWD/../../com/ecosoftware/window/components/ -lmenubar \
  -L$$OUT_PWD/../../com/ecosoftware/window/components/ -lstatusbar \
  -L$$OUT_PWD/../../com/ecosoftware/window/ -lmainwindow
else:unix: LIBS += \
  -L$$OUT_PWD/../../com/ecosoftware/ -lapp \
  -L$$OUT_PWD/../../com/ecosoftware/ -lutils \
  -L$$OUT_PWD/../../com/ecosoftware/ -lsingleinstance \
  -L$$OUT_PWD/../../com/ecosoftware/ -lsplashscreen \
  -L$$OUT_PWD/../../com/ecosoftware/ -lresources \
  -L$$OUT_PWD/../../com/ecosoftware/engines/ -lxsd \
  -L$$OUT_PWD/../../com/ecosoftware/engines/ -lxsdform \
  -L$$OUT_PWD/../../com/ecosoftware/window/components/ -lactions \
  -L$$OUT_PWD/../../com/ecosoftware/window/components/ -lmenubar \
  -L$$OUT_PWD/../../com/ecosoftware/window/components/ -lstatusbar \
  -L$$OUT_PWD/../../com/ecosoftware/window/ -lmainwindow

INCLUDEPATH += \
  $$PWD/../../com/ecosoftware/app \
  $$PWD/../../com/ecosoftware/utils \
  $$PWD/../../com/ecosoftware/singleinstance \
  $$PWD/../../com/ecosoftware/splashscreen \
  $$PWD/../../com/ecosoftware/resources \
  $$PWD/../../com/ecosoftware/engines/xsd \
  $$PWD/../../com/ecosoftware/engines/xsdform \
  $$PWD/../../com/ecosoftware/window/components/actions \
  $$PWD/../../com/ecosoftware/window/components/menubar \
  $$PWD/../../com/ecosoftware/window/components/statusbar \
  $$PWD/../../com/ecosoftware/window/mainwindow

DEPENDPATH += \
  $$PWD/../../com/ecosoftware/app \
  $$PWD/../../com/ecosoftware/utils \
  $$PWD/../../com/ecosoftware/singleinstance \
  $$PWD/../../com/ecosoftware/splashscreen \
  $$PWD/../../com/ecosoftware/resources \
  $$PWD/../../com/ecosoftware/engines/xsd \
  $$PWD/../../com/ecosoftware/engines/xsdform \
  $$PWD/../../com/ecosoftware/window/components/actions \
  $$PWD/../../com/ecosoftware/window/components/menubar \
  $$PWD/../../com/ecosoftware/window/components/statusbar \
  $$PWD/../../com/ecosoftware/window/mainwindow
