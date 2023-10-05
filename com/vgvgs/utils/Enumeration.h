#ifndef ENUMERATION_H
#define ENUMERATION_H

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

      class UTILSSHARED_EXPORT Enumeration {

        public :
          static int indexOf ( const QMetaObject staticMetaObject, QString enumerate, QString enumKey );// LISTO
          static bool inEnum ( const QMetaObject staticMetaObject, QString enumerate, QString enumKey );
          static bool inEnum ( const QMetaObject staticMetaObject, QString enumerate, int enumValue );
          static QString normalizeEnumValue ( QString enumKey );

        private :
          static const QMetaEnum getMetaEnum ( const QMetaObject staticMetaObject, QString enumerate );
      };
    }
  }
}

#endif // ENUMERATION_H
