#ifndef APPUTILS_H
#define APPUTILS_H

// Librerías Internas
// Internal Libraries
#include "app_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QDir>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_APP {

      class APPSHARED_EXPORT AppUtils : public QObject {

          Q_OBJECT

        public :
          static QString normalizePath ( QString path );
          static QString pathTo ( QString path );
          static QString relativePath ( QString rootPath, QString path );
      };
    }
  }
}

#endif // APPUTILS_H
