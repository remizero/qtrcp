#ifndef ELEMENTFORMDEFAULTPROPERTY_H
#define ELEMENTFORMDEFAULTPROPERTY_H

// Librerías Internas
// Internal Libraries
#include "xsd_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "core/PropertyAbs.h"

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

        class XSDSHARED_EXPORT ElementFormDefaultProperty : public PropertyAbs {

            Q_OBJECT
            Q_ENUMS ( values )

          public :
            ElementFormDefaultProperty ( QString value = "unqualified" );
            ElementFormDefaultProperty ( const ElementFormDefaultProperty& );
            ~ElementFormDefaultProperty ();

            enum values {

              QUALIFIED = 1,
              UNQUALIFIED
            };
            Q_ENUM ( values )

            QString getValue () const;
            static int indexOfValuesEnum ( QString enumKey );
            static bool inValuesEmun ( QString enumKey );
            void setValue ( QString value );
            static QString valuesEnumToString ( values enumValue );

          private :
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::ElementFormDefaultProperty )

#endif // ELEMENTFORMDEFAULTPROPERTY_H
