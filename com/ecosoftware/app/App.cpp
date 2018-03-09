#include "App.h"
#include <QDebug>

using namespace Com::Ecosoftware::App;

App::App ( int &argc, char **argv ) :  QApplication ( argc, argv ) {}

App::~App () {}

QCoreApplication *App::createApplication ( int &argc, char *argv [] ) {

  for ( int i = 1; i < argc; ++i ) {

    if ( !qstrcmp ( argv [ i ], "-no-gui" ) ) {

      qDebug () << "La aplicación es una QCoreApplication";
      return new QCoreApplication ( argc, argv );
    }
  }
  return new QApplication ( argc, argv );
}

bool App::notify ( QObject *receiver, QEvent *event ) {

  try {

    return QApplication::notify ( receiver, event );

  } catch ( std::exception& e ) {

    qCritical () << "Exception thrown:" << e.what ();
  }
  return false;
}
