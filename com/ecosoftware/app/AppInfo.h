#ifndef APPINFO_H
#define APPINFO_H

// Librerías Internas
#include "app_global.h"

// Librerías Qt
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace App {

      class APPSHARED_EXPORT AppInfo : public QObject {

          Q_OBJECT

        public:
          explicit AppInfo ( QObject *parent = 0 );

        signals:

        public slots:
      };
    }
  }
}

#endif // APPINFO_H
