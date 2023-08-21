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
#include <QDebug>

int main ( int argc, char *argv [] ) {

  int currentExitCode = 0;

  do {

    NAMESPACE_LIBRARY_APP::App *app = new NAMESPACE_LIBRARY_APP::App ( argc, argv );
    QScopedPointer<QCoreApplication> appScopedPointer ( app->getApplication () );

    if ( qobject_cast < QApplication *> ( appScopedPointer.data () ) ) {
// start GUI version...

      if ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().checkVersion () ) {

        return 0;
      }

      Com::Vgvgs::SingleInstance::SingleInstance singleInstance ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/applicationhashkey" ).toString () );

      appScopedPointer->setOrganizationName ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/organizationname" ).toString () );
      appScopedPointer->setOrganizationDomain ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/organizationdomain" ).toString () );
      appScopedPointer->setApplicationName ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/applicationname" ).toString () );
      qobject_cast < QApplication *> ( appScopedPointer.data () )->setApplicationDisplayName ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/applicationdisplayname" ).toString () );
      appScopedPointer->setApplicationVersion ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/applicationversion" ).toString () );

      if ( !singleInstance.tryToRun () ) {

        QMessageBox msgBox ( QMessageBox::Warning, qobject_cast < QApplication *> ( appScopedPointer.data () )->applicationDisplayName (), "Ya existe una instancia de esta aplicación ejecutándose.", QMessageBox::Ok );
        msgBox.exec ();
        return 0;
      }

      NewInstantiationMainWindow mainWindow ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings () );
      mainWindow.show ();

    } else {
// start non-GUI version...
      qDebug () << "Está entrando por la versión non-GUI";

    }
    currentExitCode = appScopedPointer->exec ();
    qDebug () << "En teoría se ejecutó appInstance->exec ()";

  } while ( currentExitCode == NewInstantiationMainWindow::EXIT_CODE_REBOOT );

  return currentExitCode;
}
