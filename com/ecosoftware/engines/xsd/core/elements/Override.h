#ifndef OVERRIDE_H
#define OVERRIDE_H

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

        class XSDSHARED_EXPORT Override : public ElementAbs {

            Q_OBJECT
            Q_ENUMS ( content properties )

          public :
            Q_INVOKABLE Override ();
            Override ( const Override& );
            ~Override ();

            enum content {

              ANNOTATION = ElementAbs::elements::ANNOTATION,
              ATTRIBUTE = ElementAbs::elements::ATTRIBUTE,
              ATTRIBUTEGROUP = ElementAbs::elements::ATTRIBUTEGROUP,
              COMPLEXTYPE = ElementAbs::elements::COMPLEXTYPE,
              ELEMENT = ElementAbs::elements::ELEMENT,
              GROUP = ElementAbs::elements::GROUP,
              NOTATION = ElementAbs::elements::NOTATION,
              SIMPLETYPE = ElementAbs::elements::SIMPLETYPE
            };
            Q_ENUM ( content )

            enum properties {

              ID = PropertyAbs::properties::ID,
              SCHEMALOCATION = PropertyAbs::properties::SCHEMALOCATION
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
Q_DECLARE_METATYPE ( Com::Vgvgs::Engines::Xsd::Override )

#endif // OVERRIDE_H
