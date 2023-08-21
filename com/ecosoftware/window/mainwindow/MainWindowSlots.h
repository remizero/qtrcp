#ifndef MAINWINDOWSLOTS_H
#define MAINWINDOWSLOTS_H

// Librerías Internas
#include "mainwindow_global.h"

// Librerías Externas
#include "macros_global.h"
#include "MainWindow.h"

// Librerías Externas
#include "App.h"

// Librerías Qt
#include <QApplication>
#include <QMainWindow>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_MAINWINDOW {

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
