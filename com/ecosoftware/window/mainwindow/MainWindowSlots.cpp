#include "MainWindowSlots.h"

#include <QDebug>

using namespace NAMESPACE_LIBRARY_MAINWINDOW;

MainWindowSlots::MainWindowSlots ( QMainWindow *parent ) {

  this->parent = parent;
}

void MainWindowSlots::slotReboot () {

  qDebug () << "Performing application reboot...";
  qApp->exit ( NAMESPACE_LIBRARY_APP::App::EXIT_CODE_REBOOT );
}
