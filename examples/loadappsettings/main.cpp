// Librerías Internas
#include "MainWindow.h"

// Librerías Externas
#include "AppInfo.h"
#include "AppInit.h"
#include "AppPaths.h"
#include "AppSettings.h"
#include "SingleInstance.h"

// Librerías Qt
#include <QApplication>
#include <QDebug>
#include <QMessageBox>

int main ( int argc, char *argv [] ) {

  QApplication appInstance ( argc, argv );

  if ( Com::Ecosoftware::App::AppInit::getInstance ().checkVersion () ) {

    return 0;
  }

  Com::Ecosoftware::SingleInstance::SingleInstance singleInstance ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/applicationhashkey" ).toString () );

  appInstance.setOrganizationName ( Com::Ecosoftware::App::AppInfo::getOrganizationName () );
  appInstance.setOrganizationDomain ( Com::Ecosoftware::App::AppInfo::getOrganizationDomain () );
  appInstance.setApplicationName ( Com::Ecosoftware::App::AppInfo::getApplicationName () );
  appInstance.setApplicationDisplayName ( Com::Ecosoftware::App::AppInfo::getApplicationDisplayName () );
  appInstance.setApplicationVersion ( Com::Ecosoftware::App::AppInfo::getApplicationVersion () );

  if ( !singleInstance.tryToRun () ) {

    QMessageBox msgBox ( QMessageBox::Warning, appInstance.applicationDisplayName (), "Ya existe una instancia de esta aplicación ejecutándose.", QMessageBox::Ok );
    msgBox.exec ();
    return 0;
  }
  MainWindow mainWindow;
  mainWindow.show ();

  return appInstance.exec ();
}
