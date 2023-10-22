#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"
#include "actionsystem/ActionManager.h"
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

      class CORE_EXPORT PluginManager : public QObject, public NAMESPACE_LIBRARY_PATTERNIFY::Singleton<PluginManager> {

          Q_OBJECT

        public :
          void initialize ();
          //static void initializeStaticPlugins ( const QStringList &staticPlugins );
          void uninitialize ();
          void scan ( const QString &path );
          void load ( const QString &path );
          void unload ( const QString &path );
          QStringList plugins () const;
          bool validateLibraryDependencies ( QJsonObject object );
          bool validatePluginDependencies ( QJsonObject object );

        signals :

        private :
          QList<QObject *> loadedPlugins;
          QHash<QString, QPluginLoader *> loaders;
          //static bool initialized;
          PluginManager ( QObject *parent = nullptr );
          friend class NAMESPACE_LIBRARY_PATTERNIFY::Singleton<PluginManager>;
      };
    }
  }
}

#endif // PLUGINMANAGER_H
