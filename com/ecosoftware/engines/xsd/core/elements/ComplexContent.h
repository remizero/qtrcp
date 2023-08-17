#ifndef COMPLEXCONTENT_H
#define COMPLEXCONTENT_H

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

        class XSDSHARED_EXPORT ComplexContent : public ElementAbs {

            Q_OBJECT
            Q_ENUMS ( content properties )

          public :
            Q_INVOKABLE ComplexContent ();
            ComplexContent ( const ComplexContent& );
            ~ComplexContent ();

            enum content {

              ANNOTATION = ElementAbs::elements::ANNOTATION,
              EXTENSION = ElementAbs::elements::EXTENSION,
              RESTRICTION = ElementAbs::elements::RESTRICTION
            };
            Q_ENUM ( content )

            enum properties {

              ID = PropertyAbs::properties::ID,
              MIXED = PropertyAbs::properties::MIXED
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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::ComplexContent )

#endif // COMPLEXCONTENT_H
