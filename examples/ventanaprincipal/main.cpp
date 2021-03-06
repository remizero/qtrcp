// Librerías Internas
#include "VentanaPrincipal.h"

// Librerías Externas
#include "AppInit.h"
#include "AppPaths.h"
#include "AppSettings.h"
//#include "Logger.h"
#include "SingleInstance.h"

// Librerías Qt
#include <QApplication>
#include <QDebug>
#include <QMessageBox>

int main ( int argc, char *argv [] ) {

  int currentExitCode = 0;

  do {

    QApplication appInstance ( argc, argv );
    //Com::Ecosoftware::Logger::Logger *logger = new Com::Ecosoftware::Logger::Logger ();

    if ( Com::Ecosoftware::App::AppInit::getInstance ().checkVersion () ) {

      return 0;
    }

    Com::Ecosoftware::SingleInstance::SingleInstance singleInstance ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/applicationhashkey" ).toString () );

    appInstance.setOrganizationName ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/organizationname" ).toString () );
    appInstance.setOrganizationDomain ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/organizationdomain" ).toString () );
    appInstance.setApplicationName ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/applicationname" ).toString () );
    appInstance.setApplicationDisplayName ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/applicationdisplayname" ).toString () );
    appInstance.setApplicationVersion ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/applicationversion" ).toString () );

    if ( !singleInstance.tryToRun () ) {

      QMessageBox msgBox ( QMessageBox::Warning, appInstance.applicationDisplayName (), "Ya existe una instancia de esta aplicación ejecutándose.", 0 );
      msgBox.exec ();
      return 0;
    }
    VentanaPrincipal mainWindow ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings () );
    mainWindow.show ();
    currentExitCode = appInstance.exec ();

  } while ( currentExitCode == VentanaPrincipal::EXIT_CODE_REBOOT );

  return currentExitCode;
}
