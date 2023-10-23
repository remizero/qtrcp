#ifndef APPSETTINGS_H
#define APPSETTINGS_H

// Librerías Internas
// Internal Libraries
#include "app_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "AppPaths.h"

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QIODevice>
#include <QSettings>
#include <QString>
#include <QStringView>
#include <QStringList>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_APP {

      class APPSHARED_EXPORT AppSettings {

        public :
          //static QSettings loadSettingsXML ( QString fileName );
          static QSettings::Format getXmlFormat ();
          static bool readXmlFile ( QIODevice &device, QSettings::SettingsMap &map );
          static void saveRecentFile ( const QString &value );
          static void saveRecentProject ( const QString &value );
          static bool writeXmlFile ( QIODevice &device, const QSettings::SettingsMap &map );

        private :
          static void saveRecent ( const QString &recentGroup, int maxItemsRecentGroup, const QString &key, const QString &value );
      };
    }
  }
}

#endif // APPSETTINGS_H
