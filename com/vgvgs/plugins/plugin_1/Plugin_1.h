#ifndef PLUGIN_1_H
#define PLUGIN_1_H

// Librerías Internas
// Internal Libraries
#include "plugin_1_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "pluginsystem/PluginAbs.h"
#include "pluginsystem/PluginInfo.h"
#include "pluginsystem/PluginInterface.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_PLUGIN_1 {

      class PLUGIN_1_EXPORT Plugin_1 : public NAMESPACE_LIBRARY_CORE::PluginInterface {

          Q_INTERFACES ( NAMESPACE_LIBRARY_CORE::PluginInterface )
          Q_OBJECT
          Q_PLUGIN_METADATA ( IID "com.vgvgs.Plugin_1" FILE "Plugin_1.json" )

        public :
          Plugin_1 ();
          ~Plugin_1 () override;

          void initialize ( QJsonObject object ) override;
          void finalize () override;
          QAction menuAction () const override;
          QList<QAction *> actions () const override;
          NAMESPACE_LIBRARY_CORE::PluginInfo *getPluginInfo () override;

        private :
          NAMESPACE_LIBRARY_CORE::PluginInfo *pluginInfo;
      };
    }
  }
}

#endif // PLUGIN_1_H
