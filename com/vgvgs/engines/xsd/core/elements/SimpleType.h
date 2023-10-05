#ifndef SIMPLETYPE_H
#define SIMPLETYPE_H

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

        class XSDSHARED_EXPORT SimpleType : public ElementAbs {

            Q_OBJECT
            Q_ENUMS ( content properties )

          public :
            Q_INVOKABLE SimpleType ();
            SimpleType ( const SimpleType& );
            ~SimpleType ();

            enum content {

              ANNOTATION = ElementAbs::elements::ANNOTATION,
              LIST = ElementAbs::elements::LIST,
              RESTRICTION = ElementAbs::elements::RESTRICTION,
              UNION = ElementAbs::elements::UNION
            };
            Q_ENUM ( content )

            enum properties {

              FINAL = PropertyAbs::properties::FINAL,
              ID = PropertyAbs::properties::ID,
              NAME = PropertyAbs::properties::NAME
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
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::SimpleType )

#endif // SIMPLETYPE_H
