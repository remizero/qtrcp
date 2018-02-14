// Librerías Internas
#include "VentanaPrincipal.h"

// Librerías Externas
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

  Com::Ecosoftware::SingleInstance::SingleInstance singleInstance ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "ecomoditor/applicationhashkey" ).toString () );

  appInstance.setOrganizationName ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "ecomoditor/organizationname" ).toString () );
  appInstance.setOrganizationDomain ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "ecomoditor/organizationdomain" ).toString () );
  appInstance.setApplicationName ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "ecomoditor/applicationname" ).toString () );
  appInstance.setApplicationDisplayName ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "ecomoditor/applicationdisplayname" ).toString () );
  appInstance.setApplicationVersion ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "ecomoditor/applicationversion" ).toString () );

  if ( !singleInstance.tryToRun () ) {

    QMessageBox msgBox ( QMessageBox::Warning, appInstance.applicationDisplayName (), "Ya existe una instancia de esta aplicación ejecutándose.", 0 );
    msgBox.exec ();
    return 0;
  }
  VentanaPrincipal mainWindow ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings () );
  mainWindow.show ();

  return appInstance.exec ();
}
