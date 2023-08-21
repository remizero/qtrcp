#-------------------------------------------------
#
# Project created by QtCreator 2017-10-06T11:54:25
#
#-------------------------------------------------

QT       -= gui

TARGET = resources
TEMPLATE = lib

DEFINES += RESOURCES_LIBRARY

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
  Resources.cpp

HEADERS += \
  resources_global.h \
  Resources.h

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

RESOURCES += \
  iconsresource.qrc \
  xmlresources.qrc \
  xsdresources.qrc

DEF_FILE += \
  export.def

DISTFILES += \
  export.def

unix {
    target.path = /usr/lib
    INSTALLS += target
}

#QMAKE_LFLAGS += /DEF:\"$${PWD}\\export.def\"
#OTHER_FILES += \
#    export.def
