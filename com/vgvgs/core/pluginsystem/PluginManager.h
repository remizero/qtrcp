#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"
#include "PluginData.h"
#include "PluginInterface.h"

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
#include <QLibrary>
#include <QObject>
#include <QPluginLoader>
#include <QStringList>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT PluginManager : public QObject, public NAMESPACE_LIBRARY_PATTERNIFY::Singleton<PluginManager> {

          Q_OBJECT

        public :
          void initialize ();
          static void initializeStaticPlugins ( const QStringList &staticPlugins );
          void uninitialize ();
          void scan ( const QString &path );
          void load ( const QString &path );
          void unload ( const QString &path );
          QStringList plugins () const;

        signals :

        private :
          QList<QObject *> loadedPlugins;
          PluginData *d;
          PluginManager ( QObject *parent = nullptr );
          friend class NAMESPACE_LIBRARY_PATTERNIFY::Singleton<PluginManager>;
      };
    }
  }
}

#endif // PLUGINMANAGER_H
