#ifndef ANNOTATION_H
#define ANNOTATION_H

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

        class XSDSHARED_EXPORT Annotation : public ElementAbs {

            Q_OBJECT
            Q_ENUMS ( content properties )

          public :
            Q_INVOKABLE Annotation();
            Annotation ( const Annotation& );
            ~Annotation ();

            enum content {

              APPINFO = ElementAbs::elements::APPINFO,
              DOCUMENTATION = ElementAbs::elements::DOCUMENTATION
            };
            Q_ENUM ( content )

            enum properties {

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
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::Annotation )

#endif // ANNOTATION_H
