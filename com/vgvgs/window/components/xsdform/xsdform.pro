# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../../../../qmakeSupportFiles/buildPaths.prf)

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml

TARGET = xsdform

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
  XsdDialog.cpp \
  XsdFormCreator.cpp

HEADERS += \
  xsdform_global.h \
  XsdDialog.h \
  XsdFormCreator.h

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lApp \
  -L$$LIB_PATH/ -lResources \
  -L$$LIB_PATH/ -lUtils \
  -L$$LIB_PATH/ -lXsd \
  -L$$LIB_PATH/ -lColorpicker \
  -L$$LIB_PATH/ -lColorbox
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lApp \
  -L$$LIB_PATH/ -lResources \
  -L$$LIB_PATH/ -lUtils \
  -L$$LIB_PATH/ -lXsd \
  -L$$LIB_PATH/ -lColorpicker \
  -L$$LIB_PATH/ -lColorbox
else:unix: LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lApp \
  -L$$LIB_PATH/ -lResources \
  -L$$LIB_PATH/ -lUtils \
  -L$$LIB_PATH/ -lXsd \
  -L$$LIB_PATH/ -lColorpicker \
  -L$$LIB_PATH/ -lColorbox

INCLUDEPATH += \
  $$PWD/../../../macros \
  $$PWD/../../../app \
  $$PWD/../../../resources \
  $$PWD/../../../utils \
  $$PWD/../../../engines/xsd \
  $$UI_DIR \
  $$PWD/../colorpicker \
  $$PWD/../colorbox

DEPENDPATH += \
  $$PWD/../../../macros \
  $$PWD/../../../app \
  $$PWD/../../../resources \
  $$PWD/../../../utils \
  $$PWD/../../../engines/xsd \
  $$UI_DIR \
  $$PWD/../colorpicker \
  $$PWD/../colorbox

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../../../../qmakeSupportFiles/copyLibraries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../../../../qmakeSupportFiles/deploymentRulesLib.prf)
