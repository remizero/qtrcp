QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
DEFINES += COLORPICKER_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
  ColorPicker.cpp \
  ColorPickerDialog.cpp \
  ColorSelector.cpp \
  ColorWidget.cpp \
  SVSelector.cpp

HEADERS += \
  ColorPickerDialog.h \
  ColorSelector.h \
  ColorWidget.h \
  SVSelector.h \
  colorpicker_global.h \
  ColorPicker.h

DESTDIR = ../

# UI_DIR = ../../../../../ui

win32:CONFIG(release, debug|release): LIBS += \
  -L$$OUT_PWD/../../../ -lmacros
  #-L$$OUT_PWD/../../ -lmainwindow
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$OUT_PWD/../../../ -lmacros
else:unix: LIBS += \
  -L$$OUT_PWD/../../../ -lmacros

INCLUDEPATH += \
  $$PWD/../../../macros

DEPENDPATH += \
  $$PWD/../../../macros

# Default rules for deployment.
unix {
  target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
  Agradecimientos.txt

FORMS += \
  ColorPickerDialog.ui
