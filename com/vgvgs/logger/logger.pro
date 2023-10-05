# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../../qmakeSupportFiles/buildPaths.prf)

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += core widgets xml

TARGET = logger

# Normalización del nombre de proyecto.
# Project name normalization.
include (../../../qmakeSupportFiles/normalizeProjectName.prf)
TARGET = $$PROJECT_NAME

# Definiciones particulares del tipo de proyecto.
# Particular definitions of the project type.
include (../../../qmakeSupportFiles/projectLibConfiguration.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
include(../../../qmakeSupportFiles/buildConfiguration.prf)

SOURCES += \
  Logger.cpp

HEADERS += \
  Logger.h \
  logger_global.h

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lApp \
  -L$$LIB_PATH/ -lCore \
  -L$$LIB_PATH/ -lPatternify \
  -L$$VENDORS_PATH/ -lSmtpMime
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lApp \
  -L$$LIB_PATH/ -lCore \
  -L$$LIB_PATH/ -lPatternify \
  -L$$VENDORS_PATH/ -lSmtpMime
else:unix: LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lApp \
  -L$$LIB_PATH/ -lCore \
  -L$$LIB_PATH/ -lPatternify \
  -L$$VENDORS_PATH/ -lSmtpMime

INCLUDEPATH += \
  $$PWD/../macros \
  $$PWD/../app \
  $$PWD/../core \
  $$PWD/../patternify \
  $$PWD/../../../third-party/SMTPEmail

DEPENDPATH += \
  $$PWD/../macros \
  $$PWD/../app \
  $$PWD/../core \
  $$PWD/../patternify \
  $$PWD/../../../third-party/SMTPEmail

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../../qmakeSupportFiles/copyLibraries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../../qmakeSupportFiles/deploymentRulesLib.prf)
