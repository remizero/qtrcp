// Librerías Internas
// Internal Libraries
#include "VentanaPrincipal.h"

// Librerías Externas
// External Libraries
#include "App.h"
#include "AppInit.h"
#include "AppPaths.h"
#include "AppSettings.h"
#include "Logger.h"
#include "SingleInstance.h"
#include "Exception.h"
#include "pluginsystem/PluginManager.h"

// Librerías Qt
// Qt Libraries
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

    // TODO Esta línea que sigue se pueden gestionar directamente en NAMESPACE_LIBRARY_APP::App
    appInstance.addLibraryPath ( NAMESPACE_LIBRARY_APP::AppPaths::getInstance ().getApplicationPluginsPath () );
    qDebug () << "LIBRARY PATHS" << appInstance.libraryPaths ();
    try {

      // TODO Esta línea que sigue se pueden gestionar directamente en NAMESPACE_LIBRARY_APP::App
      NAMESPACE_LIBRARY_LOGGER::Logger::getInstance ();
      throw NAMESPACE_LIBRARY_CORE::Exception ( "Mensaje de prueba", __FILE__, __LINE__, Q_FUNC_INFO );

    } catch ( const NAMESPACE_LIBRARY_CORE::Exception &exception ) {

      NAMESPACE_LIBRARY_LOGGER::Logger::getInstance ()->exception ( exception );
    }

    // TODO Esta línea que sigue se pueden gestionar directamente en NAMESPACE_LIBRARY_APP::App
    if ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().checkVersion () ) {

      return 0;
    }

    NAMESPACE_LIBRARY_SINGLEINSTANCE::SingleInstance singleInstance ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/applicationhashkey" ).toString () );

    // TODO Estas cinco líneas se pueden gestionar directamente en NAMESPACE_LIBRARY_APP::App
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
    // TODO Esta línea que sigue se pueden gestionar directamente en NAMESPACE_LIBRARY_APP::App
    NAMESPACE_LIBRARY_CORE::PluginManager::getInstance ()->initialize ();

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
  NAMESPACE_LIBRARY_CORE::PluginManager::getInstance ()->uninitialize ();
  return currentExitCode;
}
