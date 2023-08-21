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

  if ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().checkVersion () ) {

    return 0;
  }

  Com::Vgvgs::SingleInstance::SingleInstance singleInstance ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/applicationhashkey" ).toString () );

  appInstance.setOrganizationName ( NAMESPACE_LIBRARY_APP::AppInfo::getOrganizationName () );
  appInstance.setOrganizationDomain ( NAMESPACE_LIBRARY_APP::AppInfo::getOrganizationDomain () );
  appInstance.setApplicationName ( NAMESPACE_LIBRARY_APP::AppInfo::getApplicationName () );
  appInstance.setApplicationDisplayName ( NAMESPACE_LIBRARY_APP::AppInfo::getApplicationDisplayName () );
  appInstance.setApplicationVersion ( NAMESPACE_LIBRARY_APP::AppInfo::getApplicationVersion () );

  if ( !singleInstance.tryToRun () ) {

    QMessageBox msgBox ( QMessageBox::Warning, appInstance.applicationDisplayName (), "Ya existe una instancia de esta aplicación ejecutándose.", QMessageBox::Ok );
    msgBox.exec ();
    return 0;
  }
  MainWindow mainWindow;
  mainWindow.show ();

  return appInstance.exec ();
}
