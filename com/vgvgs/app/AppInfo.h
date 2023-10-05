#ifndef APPINFO_H
#define APPINFO_H

// Librerías Internas
// Internal Libraries
#include "app_global.h"
#include "AppInit.h"
#include "AppSettings.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QIODevice>
#include <QObject>
#include <QSettings>
#include <QtXml>

// Librerías C++
// C++ Libraries
#include <stdlib.h>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_APP {

      class APPSHARED_EXPORT AppInfo : public QObject {

          Q_OBJECT

        public :
          explicit AppInfo ( QObject *parent = nullptr );

          static QString getOrganizationDomain ();
          static QString getOrganizationName ();
          static QString getApplicationDisplayName ();
          static QString getApplicationName ();
          static QString getApplicationVersion ();

        signals:

        public slots :
      };
    }
  }
}

#endif // APPINFO_H
