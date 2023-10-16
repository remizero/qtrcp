#ifndef PLUGINDATA_H
#define PLUGINDATA_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QHash>
#include <QPluginLoader>
#include <QString>
#include <QVariant>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT PluginData {

        public :
          bool check ( const QString &path );
          QHash<QString, QVariant> names;
          QHash<QString, QVariant> versions;
          QHash<QString, QVariantList> dependencies;
          QHash<QString, QPluginLoader *> loaders;
      };
    }
  }
}

#endif // PLUGINDATA_H
