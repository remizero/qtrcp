#ifndef MAINWINDOWSIGNALS_H
#define MAINWINDOWSIGNALS_H

#include "mainwindow_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

#include <QMainWindow>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_MAINWINDOW {

        class MAINWINDOWSHARED_EXPORT MainWindowSignals {

          public :
            MainWindowSignals ( QMainWindow *parent );

          private :
            QMainWindow *parent;
        };
      }
    }
  }
}

#endif // MAINWINDOWSIGNALS_H
