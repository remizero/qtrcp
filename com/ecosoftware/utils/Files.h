#ifndef FILES_H
#define FILES_H

// Librerías Internas
#include "utils_global.h"

// Librerías Externas
#include "macros_global.h"

// Librerías Qt
#include <QCoreApplication>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QWidget>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_UTILS {

      class UTILSSHARED_EXPORT Files {

        public :
          static QFile *load ( QString fileName, bool readOnly = false );
      };
    }
  }
}

#endif // FILES_H
