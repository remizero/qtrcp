#ifndef MAINWINDOWSLOTS_H
#define MAINWINDOWSLOTS_H

// Librerías Internas
#include "mainwindow_global.h"
#include "MainWindow.h"

// Librerías Qt
#include <QApplication>
#include <QMainWindow>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace MainWindow {

        class MAINWINDOWSHARED_EXPORT MainWindowSlots {

          public :
            MainWindowSlots ( QMainWindow *parent );

            void slotReboot ();

          private :
            QMainWindow *parent;
        };
      }
    }
  }
}

#endif // MAINWINDOWSLOTS_H
