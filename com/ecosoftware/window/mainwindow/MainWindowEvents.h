#ifndef MAINWINDOWEVENTS_H
#define MAINWINDOWEVENTS_H

// Librerías Internas
#include "mainwindow_global.h"

// Librerías Externas
#include "macros_global.h"
#include "MainWindow.h"

// Librerías Externas
#include "AppInit.h"

// Librerías Qt
#include <QCloseEvent>
#include <QEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QResizeEvent>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_MAINWINDOW {

        class MAINWINDOWSHARED_EXPORT MainWindowEvents {

          public :
            MainWindowEvents ( QMainWindow *parent );

            void adjustMaximizedSize ( QMainWindow *parent );
            void adjustMinimizedSize ( QMainWindow *parent );
            void changeEvent( QEvent *event );
            void closeEvent ( QCloseEvent *event );
            void resizeEvent ( QResizeEvent *event );

          private :
            QMainWindow *parent;
        };
      }
    }
  }
}

#endif // MAINWINDOWEVENTS_H
