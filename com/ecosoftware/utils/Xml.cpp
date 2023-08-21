#include "Xml.h"
#include <QDebug>

using namespace NAMESPACE_LIBRARY_UTILS;

QDomDocument Xml::load ( QString fileName, bool readOnly ) {

  QFile *file = Files::load ( fileName, readOnly );
  QDomDocument doc;
  if ( file == nullptr ) {

    return doc;
  }
  if ( !doc.setContent ( file ) ) {

    // TODO: Aquí guardar el error de asignación del archivo al objeto QDomDocument y mostrar error
    file->close ();
    return doc;
  }
  file->close ();
  doc.normalize ();
  return doc;
}

void Xml::save ( QDomDocument domDocument, QString fileName ) {

  QFile file ( fileName );
  if ( !file.exists () ) {

    qDebug( "El archivo no existe" );
  }
  if( !file.open ( QIODevice::WriteOnly | QIODevice::Text ) ) {

    qDebug( "Failed to open file for writing." );
    //return -1;
  }
  QTextStream stream ( &file );
  stream << domDocument.toString ();
  file.close ();
}
