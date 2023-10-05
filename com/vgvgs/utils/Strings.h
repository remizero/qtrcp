#ifndef STRINGS_H
#define STRINGS_H

// Librerías Internas
// Internal Libraries
#include "utils_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías Qt
// Qt Libraries
#include <QMetaEnum>
#include <QMetaObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_UTILS {

      class UTILSSHARED_EXPORT Strings {

        public :
          static QString capitalize ( QString string );
          static QString normalizeClassName ( QString string );
          //static
      };
    }
  }
}

#endif // STRINGS_H
