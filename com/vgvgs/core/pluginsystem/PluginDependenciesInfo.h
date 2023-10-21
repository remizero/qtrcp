#ifndef PLUGINDEPENDENCIESINFO_H
#define PLUGINDEPENDENCIESINFO_H

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
#include <QString>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT PluginDependenciesInfo {

        public :

          const QString &getName () const;
          void setName ( const QString &newName );

          const QString &getVersion () const;
          void setVersion ( const QString &newVersion );

        private :
          QString name;
          QString version;

      };
    }
  }
}

#endif // PLUGINDEPENDENCIESINFO_H
