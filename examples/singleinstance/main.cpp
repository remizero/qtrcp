// Librerías Internas
#include "MainWindow.h"

// Librerías Externas
#include "SingleInstance.h"

// Librerías Qt
#include <QApplication>
#include <QMessageBox>

int main ( int argc, char *argv [] ) {

  QApplication appInstance ( argc, argv );

  Com::Ecosoftware::SingleInstance::SingleInstance singleInstance ( "ecomoditor" );

  if ( !singleInstance.tryToRun () ) {

    QMessageBox msgBox ( QMessageBox::Warning, appInstance.applicationDisplayName (), "Ya existe una instancia de esta aplicación ejecutándose.", 0 );
    msgBox.exec ();
    return 0;
  }
  MainWindow mainWindow;
  mainWindow.show ();

  return appInstance.exec ();
}
