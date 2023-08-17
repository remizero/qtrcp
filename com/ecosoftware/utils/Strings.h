#ifndef STRINGS_H
#define STRINGS_H

// Librerías Internas
#include "utils_global.h"

// Librerías Qt
#include <QMetaEnum>
#include <QMetaObject>

namespace Com {

  namespace Ecosoftware {

    namespace Utils {

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
