#include "App.h"


using namespace NAMESPACE_LIBRARY_APP;


App::App ( int &argc, char **argv ) : QApplication ( argc, argv ) {

  for ( int i = 1; i < argc; ++i ) {

    if ( qstrcmp ( argv [ i ], "-no-gui" ) ) {

      this->application = new QCoreApplication ( argc, argv );
      break;
    }
  }
  if ( this->application == nullptr ) {

    this->application = new QApplication ( argc, argv );
  }
}

App::~App () {}

QCoreApplication *App::getApplication () {

  return this->application;
}

bool App::notify ( QObject *receiver, QEvent *event ) {

  try {

    return QApplication::notify ( receiver, event );

  } catch ( std::exception &e ) {

    qCritical () << "Exception thrown:" << e.what ();
  }
  return false;
}
