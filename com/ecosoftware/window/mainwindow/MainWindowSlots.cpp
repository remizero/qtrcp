#include "MainWindowSlots.h"
#include <QDebug>

using namespace Com::Ecosoftware::Window::MainWindow;

MainWindowSlots::MainWindowSlots ( QMainWindow *parent ) {

  this->parent = parent;
}

void MainWindowSlots::slotReboot () {

  qDebug () << "Performing application reboot...";
  qApp->exit ( MainWindow::EXIT_CODE_REBOOT );
}
