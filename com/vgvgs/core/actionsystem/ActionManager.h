#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"
#include "pluginsystem/PluginAbs.h"
#include "pluginsystem/PluginActionInfo.h"
#include "pluginsystem/PluginActionLocationInfo.h"
#include "pluginsystem/PluginDependenciesInfo.h"
#include "pluginsystem/PluginInfo.h"
#include "pluginsystem/PluginInterface.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "AppPaths.h"
#include "creational/Singleton.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QAction>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QLibrary>
#include <QMetaObject>
#include <QMetaMethod>
#include <QObject>
#include <QPluginLoader>
#include <QStringList>

// Librerías C++
// C++ Libraries
#include <exception>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT ActionManager : public QObject, public NAMESPACE_LIBRARY_PATTERNIFY::Singleton<ActionManager> {

          Q_OBJECT

        public :
          void createStaticActions ();
          void createDynamicActions ( PluginInterface *plugin );
          const QList<QAction *> &getActionList () const;
          void setActionList ( QAction *newAction );

        private :
          QList < QAction * > actionList;
          ActionManager ();
          friend class NAMESPACE_LIBRARY_PATTERNIFY::Singleton<ActionManager>;
      };
    }
  }
}

#endif // ACTIONMANAGER_H
