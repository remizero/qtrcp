#include "AppPaths.h"
#include <QDebug>

using namespace Com::Ecosoftware::App;

AppPaths::AppPaths () {

  QString userPathApp = QDir::toNativeSeparators ( QDir::homePath () + QDir::separator() + ".ecosoftware" + QDir::separator() + "qtrcp" + QDir::separator() );
  this->applicationDirPath = new QDir ( QCoreApplication::applicationDirPath () );
  this->applicationPath = QDir::toNativeSeparators ( this->applicationDirPath->absolutePath () + QDir::separator() );
  this->applicationDirPath->cdUp ();
  this->applicationPathRoot = QDir::toNativeSeparators ( this->applicationDirPath->absolutePath () + QDir::separator() );
  this->applicationConfigPath = QDir::toNativeSeparators ( userPathApp + "config" + QDir::separator() );
  this->applicationDataPath = QDir::toNativeSeparators ( userPathApp + "data" + QDir::separator() );
  this->applicationImagePath = QDir::toNativeSeparators ( this->getApplicationPathRoot () + "images" + QDir::separator() );
  this->applicationLanguagePath = QDir::toNativeSeparators ( userPathApp + "language" + QDir::separator() );
  this->applicationResourcesPath = QDir::toNativeSeparators ( this->getApplicationPathRoot () + "resources" + QDir::separator() );
  this->applicationTempPath = QDir::toNativeSeparators ( userPathApp + "temp" + QDir::separator() );
  // TODO: Como hacer que esta ruta pueda ser modificada por el usuario.
  this->applicationWorkspacePath = QDir::toNativeSeparators ( QDir::homePath () + QDir::separator() + "ecomoditor" + QDir::separator() );
  // TODO: Como hacer para que este tipo de archivos sean guardados en la
  // librería resources y como leerlos desde la misma.
  this->xsdPath = QDir::toNativeSeparators ( this->getApplicationPathRoot () + "data" + QDir::separator() + "MANIFEST.xsd" );
}

AppPaths::~AppPaths () {}

QString AppPaths::getApplicationConfigPath () const {

  return this->applicationConfigPath;
}

QString AppPaths::getApplicationDataPath () const {

  return this->applicationDataPath;
}

QString AppPaths::getApplicationImagePath () const {

  return this->applicationImagePath;
}

QString AppPaths::getApplicationLanguagePath () const {

  return this->applicationLanguagePath;
}

QString AppPaths::getApplicationPath () const {

  return this->applicationPath;
}

QString AppPaths::getApplicationPathRoot () const {

  return this->applicationPathRoot;
}

QString AppPaths::getApplicationResourcesPath () const {

  return this->applicationResourcesPath;
}

QString AppPaths::getApplicationTempPath () const {

  return this->applicationTempPath;
}

QString AppPaths::getApplicationWorkspacePath () const {

  return this->applicationWorkspacePath;
}

QString AppPaths::getXsdPath () const {

  return this->xsdPath;
}

AppPaths &AppPaths::getInstance () {

  static AppPaths instance;
  return instance;
}
