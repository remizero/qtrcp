#ifndef ENUMERATION_H
#define ENUMERATION_H

// Librerías Internas
#include "utils_global.h"

// Librerías Qt
#include <QMetaEnum>
#include <QMetaObject>

namespace Com {

  namespace Ecosoftware {

    namespace Utils {

      class UTILSSHARED_EXPORT Enumeration {

        public:
          static int indexOf ( const QMetaObject staticMetaObject, QString enumerate, QString enumKey );// LISTO
          static bool inEnum ( const QMetaObject staticMetaObject, QString enumerate, QString enumKey );
          static bool inEnum ( const QMetaObject staticMetaObject, QString enumerate, int enumValue );
          static QString normalizeEnumValue ( QString enumKey );

        private:
          static const QMetaEnum getMetaEnum ( const QMetaObject staticMetaObject, QString enumerate );
      };
    }
  }
}

#endif // ENUMERATION_H
