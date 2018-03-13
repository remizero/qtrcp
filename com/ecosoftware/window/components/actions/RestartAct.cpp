#include "RestartAct.h"

using namespace Com::Ecosoftware::Window::Components::Actions;

RestartAct::RestartAct ( QString title , QWidget *parent ) : ActionAbs ( title, parent ) {

  this->setObjectName ( this->metaObject ()->className () );
  this->setIcon ( QIcon ( ":/images/application-exit.svg" ) );
  this->setShortcut ( QKeySequence::Close );
}

void RestartAct::execAct () {

  // TODO: Revisar estos enlaces
  // https://forum.qt.io/topic/6155/solved-restart-a-qt-application
  // http://www.qtcentre.org/threads/30792-How-to-restart-an-application
  // https://richardstechnotes.wordpress.com/2014/06/28/restarting-a-qt-app-programmatically/
  // https://wiki.qt.io/How_to_make_an_Application_restartable
  //( ( Com::Ecosoftware::Window::MainWindow::MainWindow * ) this->parent () )->getMainWindowSlots ()->slotReboot ();
}
