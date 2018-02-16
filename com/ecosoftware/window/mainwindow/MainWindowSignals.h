#ifndef MAINWINDOWSIGNALS_H
#define MAINWINDOWSIGNALS_H

#include "mainwindow_global.h"

#include <QMainWindow>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace MainWindow {

        class MAINWINDOWSHARED_EXPORT MainWindowSignals {

          public:
            MainWindowSignals ( QMainWindow *parent );

          private:
            QMainWindow *parent;
        };
      }
    }
  }
}

#endif // MAINWINDOWSIGNALS_H
