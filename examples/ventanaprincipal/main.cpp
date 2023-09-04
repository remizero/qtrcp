// Librerías Internas
#include "VentanaPrincipal.h"

// Librerías Externas
#include "App.h"
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

    NAMESPACE_LIBRARY_APP::App appInstance ( argc, argv );
    // QApplication appInstance ( argc, argv );
    //Com::Vgvgs::Logger::Logger *logger = new Com::Vgvgs::Logger::Logger ();

    if ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().checkVersion () ) {

      return 0;
    }

    NAMESPACE_LIBRARY_SINGLEINSTANCE::SingleInstance singleInstance ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/applicationhashkey" ).toString () );

    appInstance.setOrganizationName ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/organizationname" ).toString () );
    appInstance.setOrganizationDomain ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/organizationdomain" ).toString () );
    appInstance.setApplicationName ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/applicationname" ).toString () );
    appInstance.setApplicationDisplayName ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/applicationdisplayname" ).toString () );
    appInstance.setApplicationVersion ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/applicationversion" ).toString () );

    if ( !singleInstance.tryToRun () ) {

      QMessageBox msgBox ( QMessageBox::Warning, appInstance.applicationDisplayName (), "Ya existe una instancia de esta aplicación ejecutándose.", QMessageBox::Ok );
      msgBox.exec ();
      return 0;
    }
    VentanaPrincipal mainWindow ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings () );
    mainWindow.show ();
    currentExitCode = appInstance.exec ();

  } while ( currentExitCode == NAMESPACE_LIBRARY_APP::App::EXIT_CODE_REBOOT );

  return currentExitCode;
}
