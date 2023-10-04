// Librerías Internas
#include "VentanaPrincipal.h"

// Librerías Externas
#include "App.h"
#include "AppInit.h"
#include "AppPaths.h"
#include "AppSettings.h"
#include "Logger.h"
#include "SingleInstance.h"

// Librerías Qt
#include <QApplication>
#include <QDebug>
#include <QException>
#include <QMessageBox>
#include <QMessageLogContext>
#include <QFile>
#include <QFileInfo>
#include <exception>
#include <QException>


int main ( int argc, char *argv [] ) {

  int currentExitCode = 0;

  do {

    NAMESPACE_LIBRARY_APP::App appInstance ( argc, argv );
    try {

      NAMESPACE_LIBRARY_LOGGER::Logger::getInstance ();
      throw QException ();

    } catch ( const QException &e ) {

      qDebug () << e.what ();
      // qDebug () << __FILE__; // TODO Este debe ser un valor que se debe pasar como parámetro en la excepción
      // qDebug () << Q_FUNC_INFO; // TODO Este debe ser un valor que se debe pasar como parámetro en la excepción
      // qDebug () << QString::number ( __LINE__ ); // TODO Este debe ser un valor que se debe pasar como parámetro en la excepción
    }

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
    try {

      currentExitCode = appInstance.exec ();

    } catch ( const std::bad_alloc & ) {

      // clean up here, e.g. save the session
      // and close all config files.
      // currentExitCode = QCoreApplication::exit ( EXIT_FAILURE );
      currentExitCode = EXIT_FAILURE;
      break;
      // return EXIT_FAILURE; // exit the application
    }
  } while ( currentExitCode == NAMESPACE_LIBRARY_APP::App::EXIT_CODE_REBOOT );

  return currentExitCode;
}
