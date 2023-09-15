#ifndef MAINWINDOWACTIONS_H
#define MAINWINDOWACTIONS_H

// Librerías internas
#include "mainwindow_global.h"

// Librerías Externas
#include "macros_global.h"

#include <QMainWindow>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_MAINWINDOW {

        class MAINWINDOWSHARED_EXPORT MainWindowActions {

          public :
            MainWindowActions ();
            ~MainWindowActions ();

            virtual void createActions () = 0;
            QMainWindow *getParent () const;
            void setParent ( QMainWindow *value );
            void loadBasicActions ();
            void loadPluginActions ();
            void setPluginAction ();

          private :
            QMainWindow *parent;
        };
      }
    }
  }
}

#endif // MAINWINDOWACTIONS_H
