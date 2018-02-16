#ifndef MAINWINDOWEVENTS_H
#define MAINWINDOWEVENTS_H

#include "mainwindow_global.h"

#include <QCloseEvent>
#include <QEvent>
#include <QMainWindow>
#include <QResizeEvent>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace MainWindow {

        class MAINWINDOWSHARED_EXPORT MainWindowEvents {

          public:
            MainWindowEvents ( QMainWindow *parent );

            void adjustMaximizedSize ( QMainWindow *parent );
            void adjustMinimizedSize ( QMainWindow *parent );
            void changeEvent( QEvent *event );
            void closeEvent ( QCloseEvent *event );
            void resizeEvent ( QResizeEvent *event );

          private:
            QMainWindow *parent;
        };
      }
    }
  }
}

#endif // MAINWINDOWEVENTS_H
