#ifndef APPUTILS_H
#define APPUTILS_H

// Librerías internas
#include "app_global.h"

// Librerías Qt
#include <QDir>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace App {

      class APPSHARED_EXPORT AppUtils : public QObject {

          Q_OBJECT

        public:
          static QString normalizePath ( QString path );
          static QString pathTo ( QString path );
          static QString relativePath ( QString rootPath, QString path );
      };
    }
  }
}

#endif // APPUTILS_H
