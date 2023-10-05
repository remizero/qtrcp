#ifndef EXTENSION_H
#define EXTENSION_H

// Librerías Internas
// Internal Libraries
#include "xsd_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "core/ElementAbs.h"


// Librerías Externas
// External Libraries
#include "Enumeration.h"

// Librerías Qt
// Qt Libraries
#include <QMetaEnum>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

        class XSDSHARED_EXPORT Extension : public ElementAbs {

            Q_OBJECT
            Q_ENUMS ( content properties )

          public :
            Q_INVOKABLE Extension ();
            Extension ( const Extension& );
            ~Extension ();

            enum content {

              ANNOTATION = ElementAbs::elements::ANNOTATION,
              ATTRIBUTE = ElementAbs::elements::ATTRIBUTE,
              ATTRIBUTEGROUP = ElementAbs::elements::ATTRIBUTEGROUP,
              ANYATTRIBUTE = ElementAbs::elements::ANYATTRIBUTE,
              ASSERT = ElementAbs::elements::ASSERT
            };
            Q_ENUM ( content )

            enum properties {

              BASE = PropertyAbs::properties::BASE,
              ID = PropertyAbs::properties::ID
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
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::Extension )

#endif // EXTENSION_H
