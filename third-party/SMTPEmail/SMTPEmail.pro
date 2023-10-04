# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../qmakeSupportFiles/buildPaths.prf)

#-------------------------------------------------
#
# Project created by QtCreator 2011-08-11T20:59:25
#
#-------------------------------------------------

QT = core network

VERSION = 2.0.0
VER_MAJ = 2
VER_MIN = 0
VER_PAT = 0

TARGET = SmtpMime

# Normalización del nombre de proyecto.
# Project name normalization.
include (../../qmakeSupportFiles/normalizeProjectName.prf)
TARGET = $$PROJECT_NAME

# Definiciones particulares del tipo de proyecto.
# Particular definitions of the project type.
include (../../qmakeSupportFiles/projectLibConfiguration.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
include(../../qmakeSupportFiles/buildConfiguration.prf)

SOURCES += \
  emailaddress.cpp \
  mimeattachment.cpp \
  mimefile.cpp \
  mimehtml.cpp \
  mimeinlinefile.cpp \
  mimemessage.cpp \
  mimepart.cpp \
  mimetext.cpp \
  smtpclient.cpp \
  quotedprintable.cpp \
  mimemultipart.cpp \
  mimecontentencoder.cpp \
  mimebase64encoder.cpp \
  mimeqpencoder.cpp \
  mimeqpformatter.cpp \
  mimebase64formatter.cpp \
  mimecontentformatter.cpp

HEADERS  += \
  emailaddress.h \
  mimeattachment.h \
  mimefile.h \
  mimehtml.h \
  mimeinlinefile.h \
  mimemessage.h \
  mimepart.h \
  mimetext.h \
  smtpclient.h \
  SmtpMime \
  quotedprintable.h \
  mimemultipart.h \
  smtpmime_global.h \
  mimecontentencoder.h \
  mimebase64encoder.h \
  mimeqpencoder.h \
  mimeqpformatter.h \
  mimebase64formatter.h \
  mimecontentformatter.h

OTHER_FILES += \
  LICENSE \
  README.md

FORMS +=

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../qmakeSupportFiles/copyVendorLibFiles.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../qmakeSupportFiles/deploymentRulesLib.prf)
