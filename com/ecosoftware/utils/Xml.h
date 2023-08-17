#ifndef XML_H
#define XML_H

// Librerías Internas
#include "utils_global.h"
#include "Files.h"

// Librerías Qt
#include <QDomDocument>
#include <QFile>
#include <QString>

namespace Com {

  namespace Ecosoftware {

    namespace Utils {

      class UTILSSHARED_EXPORT Xml {

        public :
          static QDomDocument load ( QString fileName, bool readOnly = false );
          static void save ( QDomDocument domDocument, QString fileName );
      };
    }
  }
}

#endif // XML_H
