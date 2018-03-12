#include "FullScreenAct.h"

using namespace Com::Ecosoftware::Window::Components::Actions;

FullScreenAct::FullScreenAct ( QString title , QWidget *parent ) : ActionAbs ( title, parent ) {

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
