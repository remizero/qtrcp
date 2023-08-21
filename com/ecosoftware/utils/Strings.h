#ifndef STRINGS_H
#define STRINGS_H

// Librerías Internas
#include "utils_global.h"

// Librerías Externas
#include "macros_global.h"

// Librerías Qt
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
