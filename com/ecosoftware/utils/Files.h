#ifndef FILES_H
#define FILES_H

// Librerías Internas
#include "utils_global.h"

// Librerías Qt
#include <QCoreApplication>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QWidget>

namespace Com {

  namespace Ecosoftware {

    namespace Utils {

      class UTILSSHARED_EXPORT Files {

        public :
          static QFile *load ( QString fileName, bool readOnly = false );
      };
    }
  }
}

#endif // FILES_H
