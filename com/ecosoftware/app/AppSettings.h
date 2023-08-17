#ifndef APPSETTINGS_H
#define APPSETTINGS_H

//http://blog.openshots.de/2011/03/qsettings-mit-xml-format/
// Librerías internas
#include "app_global.h"
#include "AppPaths.h"

// Librerías Qt
#include <QDebug>
#include <QIODevice>
#include <QSettings>
#include <QString>
#include <QStringView>
#include <QStringList>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

namespace Com {

  namespace Ecosoftware {

    namespace App {

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
