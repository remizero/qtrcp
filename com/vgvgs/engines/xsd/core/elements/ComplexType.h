#ifndef COMPLEXTYPE_H
#define COMPLEXTYPE_H

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

        class XSDSHARED_EXPORT ComplexType : public ElementAbs {

            Q_OBJECT
            Q_ENUMS ( content properties )

          public :
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
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::ComplexType )

#endif // COMPLEXTYPE_H
