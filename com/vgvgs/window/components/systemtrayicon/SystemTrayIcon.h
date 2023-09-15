#ifndef SYSTEMTRAYICON_H
#define SYSTEMTRAYICON_H

// Librerías Internas
#include "systemtrayicon_global.h"

// Librerías Externas
#include "macros_global.h"

// Librerías Externas
#include "AppInit.h"
#include "AppPaths.h"

// Librerías Qt
#include <QAction>
#include <QCoreApplication>
#include <QIcon>
#include <QMainWindow>
#include <QMenu>
#include <QSystemTrayIcon>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_COMPONENTS {

        namespace NAMESPACE_SYSTEMTRAYICON {

          class SYSTEMTRAYICONSHARED_EXPORT SystemTrayIcon : public QSystemTrayIcon {

              Q_OBJECT

            public :
              explicit SystemTrayIcon ( QObject *parent = nullptr );

              void setVisible ( bool visible );

            private :
                  QAction *maximizeAction;
                  QAction *minimizeAction;
              QMainWindow *parent;
                  QAction *quitAction;
                  QAction *restoreAction;
                    QMenu *trayIconMenu;

              void createActions ();
              void createMenu ();
          };
        }
      }
    }
  }
}

#endif // SYSTEMTRAYICON_H
