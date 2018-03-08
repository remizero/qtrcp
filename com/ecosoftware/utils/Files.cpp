#include "Files.h"
#include <QDebug>

using namespace Com::Ecosoftware::Utils;

QFile *Files::load ( QString fileName, bool readOnly ) {

  bool fileOpen = false;
  QFile *file = new QFile ( fileName );

  if ( file->exists () ) {

    if ( readOnly ) {

      fileOpen = file->open ( QIODevice::ReadOnly | QIODevice::Text );

    } else {

      fileOpen = file->open ( QIODevice::ReadWrite | QIODevice::Text );
    }
    if ( !fileOpen ) {

      // TODO: Aquí guardar el error de apertura del archivo y mostrar error
      QMessageBox msgBox ( QMessageBox::Warning, QCoreApplication::applicationName (), "Imposible abrir el archivo xml.", QMessageBox::Ok );
      msgBox.exec ();
      return nullptr;

    } else {

      if ( !file->isReadable () ) {

        // TODO: Aquí guardar el error de apertura del archivo y mostrar error
        QMessageBox msgBox ( QMessageBox::Warning, QCoreApplication::applicationName (), "El archivo xml no se puede leer.", QMessageBox::Ok );
        msgBox.exec ();
        return nullptr;
      }
    }
  } else {

    // TODO: Aquí guardar el error de apertura del archivo y mostrar error
    QMessageBox msgBox ( QMessageBox::Warning, QCoreApplication::applicationName (), "El archivo xml no existe.", QMessageBox::Ok );
    msgBox.exec ();
    return nullptr;
  }
  return file;
}
