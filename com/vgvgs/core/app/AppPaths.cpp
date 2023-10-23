#include "AppPaths.h"


using namespace NAMESPACE_LIBRARY_CORE;


AppPaths::AppPaths () {

  QString userPathApp = QDir::toNativeSeparators ( QDir::homePath () + QDir::separator () + ".ecosoftware" + QDir::separator () + "qtrcp" + QDir::separator () );
  this->applicationDirPath = new QDir ( QCoreApplication::applicationDirPath () );
  this->applicationPath = QDir::toNativeSeparators ( this->applicationDirPath->absolutePath () + QDir::separator () );
  this->applicationDirPath->cdUp ();
  this->applicationDirPath->cdUp ();
  this->applicationPathRoot = QDir::toNativeSeparators ( this->applicationDirPath->absolutePath () + QDir::separator () );
  this->applicationPluginsPath = QDir::toNativeSeparators ( this->getApplicationPathRoot () + "plugins" + QDir::separator () );
  this->applicationLibrariesPath = QDir::toNativeSeparators ( this->getApplicationPathRoot () + "lib" + QDir::separator () );
  this->applicationConfigPath = QDir::toNativeSeparators ( userPathApp + "config" + QDir::separator () );
  this->applicationDataPath = QDir::toNativeSeparators ( userPathApp + "data" + QDir::separator () );
  this->applicationImagePath = QDir::toNativeSeparators ( this->getApplicationPathRoot () + "images" + QDir::separator () );
  this->applicationLanguagePath = QDir::toNativeSeparators ( userPathApp + "language" + QDir::separator () );
  this->applicationLogPath =  QDir::toNativeSeparators ( userPathApp + "log" + QDir::separator () );
  this->applicationResourcesPath = QDir::toNativeSeparators ( this->getApplicationPathRoot () + "resources" + QDir::separator () );
  this->applicationTempPath = QDir::toNativeSeparators ( userPathApp + "temp" + QDir::separator () );
  // TODO: Como hacer que esta ruta pueda ser modificada por el usuario.
  // Esta ruta debe ser leida del archivo de configuración xml, por lo que no puede
  // se cargada en este punto. Una opción sería crear un listener que al cargar
  // el archivo config.xml emita un signal que actualice esta variable, en caso
  // de que la aplicación requiera trabajar con una ruta de espacio de trabajo.
  // Esta variable, debe contener una ruta válida en todo momento, es decir, en
  // este punto se agrega una ruta que puede ser la ruta al directorio del ejecutable
  // o la ruta home del usuario actual.
  this->applicationWorkspacePath = QDir::toNativeSeparators ( QDir::homePath () + QDir::separator () + "ecomoditor" + QDir::separator () );
  // TODO: Como hacer para que este tipo de archivos sean guardados en la
  // librería resources y como leerlos desde la misma.
  this->xsdPath = QDir::toNativeSeparators ( this->getApplicationPathRoot () + "data" + QDir::separator () + "MANIFEST.xsd" );
}

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

QString AppPaths::getApplicationLibrariesPath () const {

  return this->applicationLibrariesPath;
}

QString AppPaths::getApplicationLogPath () const {

  return this->applicationLogPath;
}

QString AppPaths::getApplicationPath () const {

  return this->applicationPath;
}

QString AppPaths::getApplicationPathRoot () const {

  return this->applicationPathRoot;
}

QString AppPaths::getApplicationPluginsPath () const {

  return this->applicationPluginsPath;
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
