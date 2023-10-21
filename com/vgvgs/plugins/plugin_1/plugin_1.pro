# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../../../qmakeSupportFiles/buildPaths.prf)

# QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += gui

TARGET = plugin_1
CONFIG       += plugin

# Normalización del nombre de proyecto.
# Project name normalization.
include (../../../../qmakeSupportFiles/normalizeProjectName.prf)
TARGET = $$PROJECT_NAME

# Definiciones particulares del tipo de proyecto.
# Particular definitions of the project type.
include (../../../../qmakeSupportFiles/projectLibConfiguration.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
include(../../../../qmakeSupportFiles/buildConfiguration.prf)

SOURCES += \
  Plugin_1.cpp

HEADERS += \
  plugin_1_global.h \
  Plugin_1.h

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lApp \
  -L$$LIB_PATH/ -lPatternify \
  -L$$LIB_PATH/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lApp \
  -L$$LIB_PATH/ -lPatternify \
  -L$$LIB_PATH/ -lCore
else:unix: LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lApp \
  -L$$LIB_PATH/ -lPatternify \
  -L$$LIB_PATH/ -lCore

INCLUDEPATH += \
  $$PWD/../../macros \
  $$PWD/../../app \
  $$PWD/../../patternify \
  $$PWD/../../core

DEPENDPATH += \
  $$PWD/../../macros \
  $$PWD/../../app \
  $$PWD/../../patternify \
  $$PWD/../../core

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../../../qmakeSupportFiles/copyPlugins.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../../../qmakeSupportFiles/deploymentRulesLib.prf)

DISTFILES += \
  Plugin_1.json
