#ifndef DOCUMENTATION_H
#define DOCUMENTATION_H

// Librerías Internas
#include "xsd_global.h"

// Librerías Externas
#include "macros_global.h"
#include "core/ElementAbs.h"


// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

        class XSDSHARED_EXPORT Documentation : public ElementAbs {

            Q_OBJECT
            Q_ENUMS ( content properties )

          public :
            Q_INVOKABLE Documentation ();
            Documentation ( const Documentation& );
            ~Documentation ();

            enum content {

              ANY = ElementAbs::elements::ANY
            };
            Q_ENUM ( content )

            enum properties {

              SOURCE = PropertyAbs::properties::SOURCE,
              XMLLANG = PropertyAbs::properties::XMLLANG
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
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::Documentation )

#endif // DOCUMENTATION_H
