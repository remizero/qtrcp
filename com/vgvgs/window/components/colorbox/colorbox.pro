# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../../../../qmakeSupportFiles/buildPaths.prf)

QT += widgets

TARGET = colorbox

# Normalización del nombre de proyecto.
# Project name normalization.
include (../../../../../qmakeSupportFiles/normalizeProjectName.prf)
TARGET = $$PROJECT_NAME

# Definiciones particulares del tipo de proyecto.
# Particular definitions of the project type.
include (../../../../../qmakeSupportFiles/projectLibConfiguration.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
include(../../../../../qmakeSupportFiles/buildConfiguration.prf)

SOURCES += \
  ColorBox.cpp

HEADERS += \
  colorbox_global.h \
  ColorBox.h

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lColorpicker
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lColorpicker
else:unix: LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lColorpicker

INCLUDEPATH += \
  $$PWD/../../../macros \
  $$UI_DIR \
  $$PWD/../colorpicker

DEPENDPATH += \
  $$PWD/../../../macros \
  $$UI_DIR \
  $$PWD/../colorpicker

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../../../../qmakeSupportFiles/copyLibraries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../../../../qmakeSupportFiles/deploymentRulesLib.prf)
