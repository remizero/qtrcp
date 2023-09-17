# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../qmakeSupportFiles/buildPaths.prf)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml

TARGET = appventanaprincipal

# Normalización del nombre de proyecto.
# Project name normalization.
include (../../qmakeSupportFiles/normalizeProjectName.prf)
TARGET = $$PROJECT_NAME

# Definiciones particulares del tipo de proyecto.
# Particular definitions of the project type.
include (../../qmakeSupportFiles/projectBinConfiguration.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
include(../../qmakeSupportFiles/buildConfiguration.prf)

SOURCES += \
  main.cpp \
  VentanaPrincipal.cpp

HEADERS  += \
  VentanaPrincipal.h

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lApp \
  #-L$$LIB_PATH/ -lLogger \
  -L$$LIB_PATH/ -lResources \
  -L$$LIB_PATH/ -lUtils \
  -L$$LIB_PATH/ -lSingleinstance \
  -L$$LIB_PATH/ -lXsd \
  -L$$LIB_PATH/ -lColorpicker \
  -L$$LIB_PATH/ -lColorbox \
  -L$$LIB_PATH/ -lXsdform \
  -L$$LIB_PATH/ -lActions \
  -L$$LIB_PATH/ -lMenubar \
  -L$$LIB_PATH/ -lStatusbar \
  -L$$LIB_PATH/ -lSystemtrayicon \
  -L$$LIB_PATH/ -lMainwindow
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lApp \
  #-L$$LIB_PATH/ -lLogger \
  -L$$LIB_PATH/ -lResources \
  -L$$LIB_PATH/ -lUtils \
  -L$$LIB_PATH/ -lSingleinstance \
  -L$$LIB_PATH/ -lXsd \
  -L$$LIB_PATH/ -lColorpicker \
  -L$$LIB_PATH/ -lColorbox \
  -L$$LIB_PATH/ -lXsdform \
  -L$$LIB_PATH/ -lActions \
  -L$$LIB_PATH/ -lMenubar \
  -L$$LIB_PATH/ -lStatusbar \
  -L$$LIB_PATH/ -lSystemtrayicon \
  -L$$LIB_PATH/ -lMainwindow
else:unix: LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lApp \
  #-L$$LIB_PATH/ -lLogger \
  -L$$LIB_PATH/ -lResources \
  -L$$LIB_PATH/ -lUtils \
  -L$$LIB_PATH/ -lSingleinstance \
  -L$$LIB_PATH/ -lXsd \
  -L$$LIB_PATH/ -lColorpicker \
  -L$$LIB_PATH/ -lColorbox \
  -L$$LIB_PATH/ -lXsdform \
  -L$$LIB_PATH/ -lActions \
  -L$$LIB_PATH/ -lMenubar \
  -L$$LIB_PATH/ -lStatusbar \
  -L$$LIB_PATH/ -lSystemtrayicon \
  -L$$LIB_PATH/ -lMainwindow

INCLUDEPATH += \
  $$PWD/../../com/vgvgs/macros \
  $$PWD/../../com/vgvgs/app \
  #$$PWD/../../com/vgvgs/logger \
  $$PWD/../../com/vgvgs/resources \
  $$PWD/../../com/vgvgs/utils \
  $$PWD/../../com/vgvgs/singleinstance \
  $$PWD/../../com/vgvgs/engines/xsd \
  $$UI_DIR \
  $$PWD/../../com/vgvgs/window/components/colorpicker \
  $$PWD/../../com/vgvgs/window/components/colorbox \
  $$PWD/../../com/vgvgs/window/components/xsdform \
  $$PWD/../../com/vgvgs/window/components/actions \
  $$PWD/../../com/vgvgs/window/components/menubar \
  $$PWD/../../com/vgvgs/window/components/statusbar \
  $$PWD/../../com/vgvgs/window/components/systemtrayicon \
  $$PWD/../../com/vgvgs/window/mainwindow

DEPENDPATH += \
  $$PWD/../../com/vgvgs/macros \
  $$PWD/../../com/vgvgs/app \
  #$$PWD/../../com/vgvgs/logger \
  $$PWD/../../com/vgvgs/resources \
  $$PWD/../../com/vgvgs/utils \
  $$PWD/../../com/vgvgs/singleinstance \
  $$PWD/../../com/vgvgs/engines/xsd \
  $$UI_DIR \
  $$PWD/../../com/vgvgs/window/components/colorpicker \
  $$PWD/../../com/vgvgs/window/components/colorbox \
  $$PWD/../../com/vgvgs/window/components/xsdform \
  $$PWD/../../com/vgvgs/window/components/actions \
  $$PWD/../../com/vgvgs/window/components/colorbox \
  $$PWD/../../com/vgvgs/window/components/menubar \
  $$PWD/../../com/vgvgs/window/components/statusbar \
  $$PWD/../../com/vgvgs/window/components/systemtrayicon \
  $$PWD/../../com/vgvgs/window/mainwindow

FORMS +=

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../qmakeSupportFiles/copyBinaries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../qmakeSupportFiles/deploymentRulesLib.prf)
