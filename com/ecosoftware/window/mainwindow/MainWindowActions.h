#ifndef MAINWINDOWACTIONS_H
#define MAINWINDOWACTIONS_H

// Librerías internas
#include "mainwindow_global.h"

#include <QMainWindow>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace MainWindow {

        class MAINWINDOWSHARED_EXPORT MainWindowActions {

          public:
            MainWindowActions ();
            ~MainWindowActions ();

            virtual void createActions () = 0;
            QMainWindow *getParent () const;
            void setParent ( QMainWindow *value );
            void loadBasicActions ();
            void loadPluginActions ();
            void setPluginAction ();

          private:
            QMainWindow *parent;
        };
      }
    }
  }
}

#endif // MAINWINDOWACTIONS_H
