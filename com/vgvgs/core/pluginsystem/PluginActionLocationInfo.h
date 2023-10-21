#ifndef PLUGINACTIONLOCATIONINFO_H
#define PLUGINACTIONLOCATIONINFO_H

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
#include <QAction>
#include <QDebug>
#include <QFont>
#include <QIcon>
#include <QKeySequence>
#include <QString>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT PluginActionLocationInfo {

        public :

          const QString &getContextual () const;
          void setContextual ( const QString &newContextual );
          const QString &getMenu () const;
          void setMenu ( const QString &newMenu );
          const QString &getToolbar () const;
          void setToolbar ( const QString &newToolbar );

        private :
          QString contextual;
          QString menu;
          QString toolbar;
      };
    }
  }
}

#endif // PLUGINACTIONLOCATIONINFO_H
