#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

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

        class XSDSHARED_EXPORT Attribute : public ElementAbs {

            Q_OBJECT
            Q_ENUMS ( content properties )

          public :
            Q_INVOKABLE Attribute ();
            Attribute ( const Attribute& );
            ~Attribute ();

            enum content {

              ANNOTATION = ElementAbs::elements::ANNOTATION,
              SIMPLETYPE = ElementAbs::elements::SIMPLETYPE
            };
            Q_ENUM ( content )

            enum properties {

              DEFAULT = PropertyAbs::properties::DEFAULT,
              FIXED = PropertyAbs::properties::FIXED,
              FORM = PropertyAbs::properties::FORM,
              ID = PropertyAbs::properties::ID,
              INHERITABLE = PropertyAbs::properties::INHERITABLE,
              NAME = PropertyAbs::properties::NAME,
              REF = PropertyAbs::properties::REF,
              TARGETNAMESPACE = PropertyAbs::properties::TARGETNAMESPACE,
              TYPE = PropertyAbs::properties::TYPE,
              USE = PropertyAbs::properties::USE
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
Q_DECLARE_METATYPE ( Com::Vgvgs::Engines::Xsd::Attribute )

#endif // ATTRIBUTE_H
