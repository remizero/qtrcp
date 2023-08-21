#include "FullScreenAct.h"

using namespace NAMESPACE_LIBRARY_ACTONS;

FullScreenAct::FullScreenAct ( QString title , QWidget *parent ) : ActionAbs ( title, parent ) {

  this->setObjectName ( this->metaObject ()->className () );
  this->setIcon ( QIcon ( ":/images/application-exit.svg" ) );
  this->setShortcut ( QKeySequence::FullScreen );
}

void FullScreenAct::execAct () {

  // TODO: Falta comprobar y agregar código para MacOsX
  if ( ( ( QMainWindow * ) this->myParent )->isFullScreen () ) {

    ( ( QMainWindow * ) this->myParent )->showNormal ();

  } else {

    ( ( QMainWindow * ) this->myParent )->showFullScreen ();
  }
}
