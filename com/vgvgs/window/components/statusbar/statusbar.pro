# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../../../../qmakeSupportFiles/buildPaths.prf)

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = statusbar

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
  StatusBar.cpp

HEADERS += \
  StatusBar.h \
  statusbar_global.h

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros
else:unix: LIBS += \
  -L$$LIB_PATH/ -lMacros

INCLUDEPATH += \
  $$PWD/../../../macros

DEPENDPATH += \
  $$PWD/../../../macros

DISTFILES += \
  TODO.txt

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../../../../qmakeSupportFiles/copyLibraries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../../../../qmakeSupportFiles/deploymentRulesLib.prf)
