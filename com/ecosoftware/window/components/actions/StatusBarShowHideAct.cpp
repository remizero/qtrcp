#include "StatusBarShowHideAct.h"

using namespace Com::Ecosoftware::Window::Components::Actions;

StatusBarShowHideAct::StatusBarShowHideAct ( QString title , QWidget *parent ) : ActionAbs ( title, parent ) {

  this->setObjectName ( this->metaObject ()->className () );
  this->setIcon ( QIcon ( ":/images/application-exit.svg" ) );
  this->setShortcut ( QKeySequence::Quit );
}

void StatusBarShowHideAct::execAct () {

  // TODO: Dado que de esta manera se crearía un statusbar si no se ha creado,
  // controlar que al crearse, sea del tipo correcto de la clase StatusBar
  if ( ( ( QMainWindow * ) this->myParent )->statusBar ()->isVisible () ) {

    ( ( QMainWindow * ) this->myParent )->statusBar ()->hide ();

  } else {

    ( ( QMainWindow * ) this->myParent )->statusBar ()->setVisible ( true );
  }
}
