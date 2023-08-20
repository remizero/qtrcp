#ifndef APPINFO_H
#define APPINFO_H

// Librerías Internas
#include "app_global.h"
#include "AppInit.h"

// Librerías Qt
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace App {

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
