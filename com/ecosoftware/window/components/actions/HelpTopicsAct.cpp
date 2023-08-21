#include "HelpTopicsAct.h"
#include <QDesktopServices>
#include <QUrl>

using namespace NAMESPACE_LIBRARY_ACTONS;

HelpTopicsAct::HelpTopicsAct ( QString title , QWidget *parent ) : ActionAbs ( title, parent ) {

  this->setObjectName ( this->metaObject ()->className () );
  this->setIcon ( QIcon ( ":/images/application-exit.svg" ) );
  this->setShortcut ( QKeySequence::HelpContents );
}

void HelpTopicsAct::execAct () {

  QDesktopServices::openUrl ( QUrl ( "http://www.ecosoftware.com.ve" ) );
}
