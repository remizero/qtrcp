#include "HelpTopicsAct.h"
#include <QDesktopServices>
#include <QUrl>

using namespace Com::Ecosoftware::Window::Components::Actions;

HelpTopicsAct::HelpTopicsAct ( QString title , QWidget *parent ) : ActionAbs ( title, parent ) {

  this->setIcon ( QIcon ( ":/images/application-exit.svg" ) );
  this->setShortcut ( QKeySequence::HelpContents );
}

void HelpTopicsAct::execAct () {

  QDesktopServices::openUrl ( QUrl ( "http://www.ecosoftware.com.ve" ) );
}
