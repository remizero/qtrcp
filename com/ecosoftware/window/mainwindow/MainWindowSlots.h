#ifndef MAINWINDOWSLOTS_H
#define MAINWINDOWSLOTS_H

#include "mainwindow_global.h"

#include <QMainWindow>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace MainWindow {

        class MAINWINDOWSHARED_EXPORT MainWindowSlots {

          public:
            MainWindowSlots ( QMainWindow *parent );

          private:
            QMainWindow *parent;
        };
      }
    }
  }
}

#endif // MAINWINDOWSLOTS_H
