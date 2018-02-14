#ifndef ASSERT_H
#define ASSERT_H

// Librerías Internas
#include "xsd_global.h"
#include "core/ElementAbs.h"


// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT Assert : public ElementAbs {

            Q_OBJECT
            Q_ENUMS ( content properties )

          public:
            Q_INVOKABLE Assert ();
            Assert ( const Assert& );
            ~Assert ();

            enum content {

              ANNOTATION = ElementAbs::elements::ANNOTATION
            };
            Q_ENUM ( content )

            enum properties {

              ID = PropertyAbs::properties::ID,
              TEST = PropertyAbs::properties::TEST,
              XPATHDEFAULTNAMESPACE = PropertyAbs::properties::XPATHDEFAULTNAMESPACE
            };
            Q_ENUM ( properties )

            Q_INVOKABLE static int indexOfContentEnum ( QString enumKey );
            Q_INVOKABLE static bool inContentEmun ( QString enumKey );
            Q_INVOKABLE static QString contentEnumToString ( content enumValue );
            Q_INVOKABLE static int indexOfPropertiesEnum ( QString enumKey );
            Q_INVOKABLE static bool inPropertiesEmun ( QString enumKey );
            Q_INVOKABLE static QString propertiesEnumToString ( properties enumValue );
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::Assert )

#endif // ASSERT_H
