#include "AppInit.h"
#include "AppSettings.h"

#include <QIODevice>
#include <QSettings>
#include <QtXml>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <stdlib.h>

#include <QDebug>

using namespace Com::Ecosoftware::App;

AppInit::AppInit () {

  this->loadSettings ();
}

AppInit::~AppInit () {}

bool AppInit::checkVersion () {

  bool checkVersion = false;
  if ( ( checkVersion = ( QT_VERSION < QT_VERSION_CHECK ( this->settings->value ( "app/mayorversion" ).toInt (), this->settings->value ( "app/minorversion" ).toInt (), this->settings->value ( "app/pathversion" ).toInt () ) ) ) ) {

    QMessageBox msgBox ( QMessageBox::Warning, this->settings->value ( "app/applicationdisplayname" ).toString (), "Debe tener instalada una versión de Qt igual o superior " + this->settings->value ( "app/mayorversion" ).toString () + "." + this->settings->value ( "app/minorversion" ).toString () + "." + this->settings->value ( "app/pathversion" ).toString () + ".", 0 );
    msgBox.exec ();
  }
  return checkVersion;
}

AppInit &AppInit::getInstance () {

  static AppInit instance;
  return instance;
}

QSettings *AppInit::getSettings () const {

  return this->settings;
}

void AppInit::loadSettings () {

  const QSettings::Format XmlFormat = AppSettings::getXmlFormat ();
  //const QSettings::Format XmlFormat = QSettings::registerFormat ( "xml", ( QSettings::ReadFunc ) AppSettings::readXmlFile, ( QSettings::WriteFunc ) AppSettings::writeXmlFile );
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

}

void AppInit::saveState ( QMainWindow *parent ) {

    QSettings settings ( "./ecosoftware/ecomodeditor/data/rockolaSettings.ini", QSettings::IniFormat );
    //settings.setValue ( "dockWidget", parent->saveState () );
    settings.setValue ( "geometry", parent->saveGeometry () );
    settings.setValue ( "windowState", parent->saveState () );
}
