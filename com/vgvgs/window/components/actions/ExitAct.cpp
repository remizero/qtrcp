#include "ExitAct.h"

using namespace NAMESPACE_LIBRARY_ACTONS;

ExitAct::ExitAct ( QString title , QWidget *parent ) : ActionAbs ( title, parent ) {

  this->setObjectName ( this->metaObject ()->className () );
  this->setIcon ( QIcon ( ":/images/application-exit.svg" ) );
  this->setShortcut ( QKeySequence::Quit );
}

void ExitAct::execAct () {

  this->myParent->close ();
}
