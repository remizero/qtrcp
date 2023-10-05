#ifndef APPINIT_H
#define APPINIT_H

// Librerías Internas
// Internal Libraries
#include "app_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "AppPaths.h"
#include "AppSettings.h"

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QDockWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <QMap>
#include <QString>
#include <QVariant>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_APP {

      class APPSHARED_EXPORT AppInit {

        public :
          static AppInit &getInstance ();

          bool checkVersion ();
          QSettings *getSettings () const;
          void loadSettings ();
          static bool restoreDockWidget ( QMainWindow *parent, QDockWidget *dockWidget );
          static bool restoreGeometry ( QMainWindow *parent );
          static bool restoreState ( QMainWindow *parent );
          static void saveSettings ();
          static void saveState ( QMainWindow *parent );

        private :
          AppInit ();
          ~AppInit ();

          static AppInit instance;
               QSettings *settings;

      };
    }
  }
}

#endif // APPINIT_H
