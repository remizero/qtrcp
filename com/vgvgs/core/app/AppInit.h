#ifndef APPINIT_H
#define APPINIT_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"
#include "app/AppPaths.h"
#include "app/AppSettings.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "creational/Singleton.h"

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

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT AppInit : public QObject, public NAMESPACE_LIBRARY_PATTERNIFY::Singleton<AppInit> {

        public :

          bool checkVersion ();
          QSettings *getSettings () const;
          void loadSettings ();
          static bool restoreDockWidget ( QMainWindow *parent, QDockWidget *dockWidget );
          static bool restoreGeometry ( QMainWindow *parent );
          static bool restoreState ( QMainWindow *parent );
          static void saveSettings ();
          static void saveState ( QMainWindow *parent );

        private :
               QSettings *settings;
          AppInit ( QObject *parent = nullptr );
          friend class NAMESPACE_LIBRARY_PATTERNIFY::Singleton<AppInit>;

      };
    }
  }
}

#endif // APPINIT_H
