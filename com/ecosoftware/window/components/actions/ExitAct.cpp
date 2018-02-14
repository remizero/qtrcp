#include "ExitAct.h"

using namespace Com::Ecosoftware::Window::Components::Actions;

ExitAct::ExitAct ( QString title , QWidget *parent ) : ActionAbs ( title, parent ) {

  this->setIcon ( QIcon ( ":/images/application-exit.svg" ) );
  this->setShortcut ( QKeySequence::Quit );
}

void ExitAct::execAct () {

  this->myParent->close ();
}
