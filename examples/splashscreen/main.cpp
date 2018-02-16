// Librerías Internas
#include "VentanaPrincipal.h"

// Librerías Externas
#include "AppInit.h"
#include "AppPaths.h"
#include "AppSettings.h"
#include "SingleInstance.h"
#include "SplashScreen.h"

// Librerías Qt
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QThread>

int main ( int argc, char *argv [] ) {

  QApplication appInstance ( argc, argv );

  if ( Com::Ecosoftware::App::AppInit::getInstance ().checkVersion () ) {

    return 0;
  }

  Com::Ecosoftware::SingleInstance::SingleInstance singleInstance ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "ecomoditor/applicationhashkey" ).toString () );

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

  Com::Ecosoftware::SplashScreen::SplashScreen *splash;
  if ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/showsplash" ).toBool () ) {

    splash = new Com::Ecosoftware::SplashScreen::SplashScreen ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings () );
    splash->show ();

    QThread::msleep ( 1000 );
    appInstance.processEvents ();
    splash->showStatusMessage ( QObject::tr ( "Initializing…" ) );
    emit splash->updateProgressValueSignal ( 25 );

    QThread::msleep ( 1000 );
    appInstance.processEvents ();
    splash->showStatusMessage ( QObject::tr ( "Loading modules…" ) );
    emit splash->updateProgressValueSignal ( 50 );

    QThread::msleep ( 1000 );
    appInstance.processEvents ();
    splash->showStatusMessage ( QObject::tr ( "Loading plugins…" ) );
    emit splash->updateProgressValueSignal ( 75 );

    QThread::msleep ( 1000 );
    appInstance.processEvents ();
    splash->showStatusMessage ( QObject::tr ( "Loading database…" ) );
    emit splash->updateProgressValueSignal ( 100 );

    QThread::msleep ( 1000 );
  }

  VentanaPrincipal mainWindow ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings () );

  if ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/showsplash" ).toBool () ) {

    splash->finish ( &mainWindow );
  }

  mainWindow.show ();

  return appInstance.exec ();
}
