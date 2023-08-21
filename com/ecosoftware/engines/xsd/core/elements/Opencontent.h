#ifndef OPENCONTENT_H
#define OPENCONTENT_H

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

        class XSDSHARED_EXPORT Opencontent : public ElementAbs {

            Q_OBJECT
            Q_ENUMS ( content properties )

          public :
            Q_INVOKABLE Opencontent ();
            Opencontent ( const Opencontent& );
            ~Opencontent ();

            enum content {

              ANNOTATION = ElementAbs::elements::ANNOTATION,
              ANY = ElementAbs::elements::ANY
            };
            Q_ENUM ( content )

            enum properties {

              ID = PropertyAbs::properties::ID,
              MODE = PropertyAbs::properties::MODE
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
Q_DECLARE_METATYPE ( Com::Vgvgs::Engines::Xsd::Opencontent )

#endif // OPENCONTENT_H
