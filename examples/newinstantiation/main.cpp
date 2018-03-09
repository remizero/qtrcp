// Librerías Internas
#include "NewInstantiationMainWindow.h"

// Librerías Externas
#include "App.h"
#include "AppInit.h"
#include "AppPaths.h"
#include "AppSettings.h"
#include "SingleInstance.h"

// Librerías Qt
//#include <QApplication>

int main ( int argc, char *argv [] ) {

  int currentExitCode = 0;

  do {
//error: LNK2001: unresolved external symbol "private: static class
    Com::Ecosoftware::App::App *app = new Com::Ecosoftware::App::App ( argc, argv );
    QScopedPointer<QCoreApplication> appScopedPointer ( app->createApplication ( argc, argv ) );
    QApplication *appInstance = qobject_cast < QApplication *> ( appScopedPointer.data () );

    if ( appInstance ) {
// start GUI version...
      if ( Com::Ecosoftware::App::AppInit::getInstance ().checkVersion () ) {

        return 0;
      }

      Com::Ecosoftware::SingleInstance::SingleInstance singleInstance ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "ecomoditor/applicationhashkey" ).toString () );

      appInstance->setOrganizationName ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "ecomoditor/organizationname" ).toString () );
      appInstance->setOrganizationDomain ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "ecomoditor/organizationdomain" ).toString () );
      appInstance->setApplicationName ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "ecomoditor/applicationname" ).toString () );
      appInstance->setApplicationDisplayName ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "ecomoditor/applicationdisplayname" ).toString () );
      appInstance->setApplicationVersion ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "ecomoditor/applicationversion" ).toString () );

      if ( !singleInstance.tryToRun () ) {

        QMessageBox msgBox ( QMessageBox::Warning, appInstance->applicationDisplayName (), "Ya existe una instancia de esta aplicación ejecutándose.", 0 );
        msgBox.exec ();
        return 0;
      }
      NewInstantiationMainWindow mainWindow ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings () );
      mainWindow.show ();

    } else {
// start non-GUI version...

    }
    currentExitCode = appInstance->exec ();

  } while( currentExitCode == NewInstantiationMainWindow::EXIT_CODE_REBOOT );

  return currentExitCode;
}
