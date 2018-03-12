#ifndef SYSTEMTRAYICON_H
#define SYSTEMTRAYICON_H

// Librerías Internas
#include "systemtrayicon_global.h"

// Librerías Externas
#include "AppInit.h"

// Librerías Qt
#include <QAction>
#include <QCoreApplication>
#include <QIcon>
#include <QMainWindow>
#include <QMenu>
#include <QSystemTrayIcon>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace Components {

        namespace SystemTrayIcon {

          class SYSTEMTRAYICONSHARED_EXPORT SystemTrayIcon : public QSystemTrayIcon {

              Q_OBJECT

            public:
              explicit SystemTrayIcon ( QObject *parent = 0 );

            private:
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
