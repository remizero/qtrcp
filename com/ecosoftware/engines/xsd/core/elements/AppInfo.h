#ifndef APPINFO_H
#define APPINFO_H

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

        class XSDSHARED_EXPORT AppInfo : public ElementAbs {

            Q_OBJECT
            Q_ENUMS ( content properties )

          public:
            Q_INVOKABLE AppInfo ();
            AppInfo ( const AppInfo& );
            ~AppInfo ();

            enum content {

              ANY = ElementAbs::elements::ANY
            };
            Q_ENUM ( content )

            enum properties {

              SOURCE = PropertyAbs::properties::SOURCE
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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::AppInfo )

#endif // APPINFO_H
