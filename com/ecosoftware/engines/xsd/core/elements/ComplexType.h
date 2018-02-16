#ifndef COMPLEXTYPE_H
#define COMPLEXTYPE_H

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

        class XSDSHARED_EXPORT ComplexType : public ElementAbs {

            Q_OBJECT
            Q_ENUMS ( content properties )

          public:
            Q_INVOKABLE ComplexType ();
            ComplexType ( const ComplexType& );
            ~ComplexType ();

            enum content {

              ALL = ElementAbs::elements::ALL,
              ANNOTATION = ElementAbs::elements::ANNOTATION,
              ANYATTRIBUTE = ElementAbs::elements::ANYATTRIBUTE,
              ATTRIBUTE = ElementAbs::elements::ATTRIBUTE,
              ATTRIBUTEGROUP = ElementAbs::elements::ATTRIBUTEGROUP,
              ASSERT = ElementAbs::elements::ASSERT,
              CHOICE = ElementAbs::elements::CHOICE,
              COMPLEXCONTENT = ElementAbs::elements::COMPLEXCONTENT,
              GROUP = ElementAbs::elements::GROUP,
              OPENCONTENT = ElementAbs::elements::OPENCONTENT,
              SEQUENCE = ElementAbs::elements::SEQUENCE,
              SIMPLECONTENT = ElementAbs::elements::SIMPLECONTENT
            };
            Q_ENUM ( content )

            enum properties {

              ABSTRACT = PropertyAbs::properties::ABSTRACT,
              DEFAULTATTRIBUTESAPPLY = PropertyAbs::properties::DEFAULTATTRIBUTESAPPLY,
              BLOCK = PropertyAbs::properties::BLOCK,
              FINAL = PropertyAbs::properties::FINAL,
              ID = PropertyAbs::properties::ID,
              MIXED = PropertyAbs::properties::MIXED,
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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::ComplexType )

#endif // COMPLEXTYPE_H
