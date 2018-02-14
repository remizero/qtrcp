// Librerías Internas
#include "MainWindow.h"

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

  qDebug () << Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/applicationhashkey" ).toString ();
  qDebug () << Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/organizationname" ).toString ();
  qDebug () << Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/organizationdomain" ).toString ();
  qDebug () << Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/applicationname" ).toString ();
  qDebug () << Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/applicationdisplayname" ).toString ();
  qDebug () << Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/applicationversion" ).toString ();

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
  MainWindow mainWindow;
  mainWindow.show ();

  return appInstance.exec ();
}
