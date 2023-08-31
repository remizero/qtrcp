QT += widgets

TARGET = colorbox
TEMPLATE = lib
DEFINES += COLORBOX_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
  ColorBox.cpp

HEADERS += \
  colorbox_global.h \
  ColorBox.h

DESTDIR = ../

win32:CONFIG(release, debug|release): LIBS += \
  -L$$OUT_PWD/../../../ -lmacros \
  -L$$OUT_PWD/../ -lcolorpicker
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$OUT_PWD/../../../ -lmacros \
  -L$$OUT_PWD/../ -lcolorpicker
else:unix: LIBS += \
  -L$$OUT_PWD/../../../ -lmacros \
  -L$$OUT_PWD/../ -lcolorpicker

INCLUDEPATH += \
  $$PWD/../../../macros \
  $$PWD/../colorpicker

DEPENDPATH += \
  $$PWD/../../../macros \
  $$PWD/../colorpicker

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
