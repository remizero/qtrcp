# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../../../qmakeSupportFiles/buildPaths.prf)

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml

TARGET = mainwindow

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
  MainWindow.cpp \
  MainWindowActions.cpp \
  MainWindowEvents.cpp \
  MainWindowSignals.cpp \
  MainWindowSlots.cpp

HEADERS += \
  mainwindow_global.h \
  MainWindow.h \
  MainWindowActions.h \
  MainWindowEvents.h \
  MainWindowSignals.h \
  MainWindowSlots.h

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lApp \
  -L$$LIB_PATH/ -lUtils \
  -L$$LIB_PATH/ -lXsd \
  -L$$LIB_PATH/ -lColorpicker \
  -L$$LIB_PATH/ -lColorbox \
  -L$$LIB_PATH/ -lXsdform \
  -L$$LIB_PATH/ -lActions \
  -L$$LIB_PATH/ -lMenubar \
  -L$$LIB_PATH/ -lStatusbar \
  -L$$LIB_PATH/ -lSystemtrayicon
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lApp \
  -L$$LIB_PATH/ -lUtils \
  -L$$LIB_PATH/ -lXsd \
  -L$$LIB_PATH/ -lColorpicker \
  -L$$LIB_PATH/ -lColorbox \
  -L$$LIB_PATH/ -lXsdform \
  -L$$LIB_PATH/ -lActions \
  -L$$LIB_PATH/ -lMenubar \
  -L$$LIB_PATH/ -lStatusbar \
  -L$$LIB_PATH/ -lSystemtrayicon
else:unix: LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lApp \
  -L$$LIB_PATH/ -lUtils \
  -L$$LIB_PATH/ -lXsd \
  -L$$LIB_PATH/ -lColorpicker \
  -L$$LIB_PATH/ -lColorbox \
  -L$$LIB_PATH/ -lXsdform \
  -L$$LIB_PATH/ -lActions \
  -L$$LIB_PATH/ -lMenubar \
  -L$$LIB_PATH/ -lStatusbar \
  -L$$LIB_PATH/ -lSystemtrayicon

INCLUDEPATH += \
  $$PWD/../../macros \
  $$PWD/../../app \
  $$PWD/../../utils \
  $$PWD/../../engines/xsd \
  $$UI_DIR \
  $$PWD/../components/colorpicker \
  $$PWD/../components/colorbox \
  $$PWD/../components/xsdform \
  $$PWD/../components/actions \
  $$PWD/../components/menubar \
  $$PWD/../components/statusbar \
  $$PWD/../components/systemtrayicon

DEPENDPATH += \
  $$PWD/../../macros \
  $$PWD/../../app \
  $$PWD/../../utils \
  $$PWD/../../engines/xsd \
  $$UI_DIR \
  $$PWD/../components/colorpicker \
  $$PWD/../components/colorbox \
  $$PWD/../components/xsdform \
  $$PWD/../components/actions \
  $$PWD/../components/menubar \
  $$PWD/../components/statusbar \
  $$PWD/../components/systemtrayicon

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../../../qmakeSupportFiles/copyLibraries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../../../qmakeSupportFiles/deploymentRulesLib.prf)
