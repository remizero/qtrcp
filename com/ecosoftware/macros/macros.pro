QT       -= gui

CONFIG += c++17

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets core xml

TARGET = macros
TEMPLATE = lib

DEFINES += MACROS_LIBRARY

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
  Macros.cpp

HEADERS += \
  macros_global.h \
  Macros.h

DESTDIR = ../

UI_DIR = ../../../ui
MOC_DIR = ../../../moc
OBJECTS_DIR = ../../../obj
RCC_DIR = ../../../rcc

# Default rules for deployment.
unix {
  target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
