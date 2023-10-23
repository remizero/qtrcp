#include "AppInit.h"


using namespace NAMESPACE_LIBRARY_CORE;


AppInit::AppInit ( QObject *parent ) : QObject ( parent ) {

  this->loadSettings ();
}

bool AppInit::checkVersion () {

  bool checkVersion = false;
  if ( ( checkVersion = ( QT_VERSION < QT_VERSION_CHECK ( this->settings->value ( "app/mayorversion" ).toInt (), this->settings->value ( "app/minorversion" ).toInt (), this->settings->value ( "app/pathversion" ).toInt () ) ) ) ) {

    QMessageBox msgBox (
          QMessageBox::Warning,
          this->settings->value ( "app/applicationdisplayname" ).toString (),
          "Debe tener instalada una versión de Qt igual o superior " + this->settings->value ( "app/mayorversion" ).toString () + "." + this->settings->value ( "app/minorversion" ).toString () + "." + this->settings->value ( "app/pathversion" ).toString () + ".",
          QMessageBox::Ok );
    msgBox.exec ();
  }
  return checkVersion;
}

QSettings *AppInit::getSettings () const {

  return this->settings;
}

void AppInit::loadSettings () {

  const QSettings::Format XmlFormat = AppSettings::getXmlFormat ();
  this->settings = new QSettings ( AppPaths::getInstance ().getApplicationConfigPath () + "config.xml", XmlFormat );
}

bool AppInit::restoreDockWidget ( QMainWindow *parent , QDockWidget *dockWidget ) {

  //QSettings settings ( "./ecosoftware/ecomodeditor/data/rockolaSettings.ini", QSettings::IniFormat );
  return parent->restoreDockWidget ( dockWidget );
}

bool AppInit::restoreGeometry ( QMainWindow *parent ) {

  QSettings settings ( "./ecosoftware/ecomodeditor/data/rockolaSettings.ini", QSettings::IniFormat );
  return parent->restoreGeometry ( settings.value ( "geometry" ).toByteArray () );
}

bool AppInit::restoreState ( QMainWindow *parent ) {

  QSettings settings ( "./ecosoftware/ecomodeditor/data/rockolaSettings.ini", QSettings::IniFormat );
  return parent->restoreState ( settings.value ( "windowState" ).toByteArray () );
}

void AppInit::saveSettings () {

  /**
   * TODO
   * Qué hacer aquí?
   */
}

void AppInit::saveState ( QMainWindow *parent ) {

    QSettings settings ( "./ecosoftware/ecomodeditor/data/rockolaSettings.ini", QSettings::IniFormat );
    //settings.setValue ( "dockWidget", parent->saveState () );
    settings.setValue ( "geometry", parent->saveGeometry () );
    settings.setValue ( "windowState", parent->saveState () );
}
