#ifndef XML_H
#define XML_H

// Librerías Internas
// Internal Libraries
#include "utils_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "Files.h"

// Librerías Qt
// Qt Libraries
#include <QDomDocument>
#include <QFile>
#include <QString>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_UTILS {

      class UTILSSHARED_EXPORT Xml {

        public :
          static QDomDocument load ( QString fileName, bool readOnly = false );
          static void save ( QDomDocument domDocument, QString fileName );
      };
    }
  }
}

#endif // XML_H
