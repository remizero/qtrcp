#include "OnlineHelpAct.h"

using namespace NAMESPACE_LIBRARY_ACTONS;

OnlineHelpAct::OnlineHelpAct ( QString title , QWidget *parent ) : ActionAbs ( title, parent ) {

  this->setObjectName ( this->metaObject ()->className () );
  this->setIcon ( QIcon ( ":/images/application-exit.svg" ) );
  this->setShortcut ( QKeySequence::SelectAll );
}

void OnlineHelpAct::execAct () {

  QDesktopServices::openUrl ( QUrl ( "http://www.ecosoftware.com.ve" ) );
}
