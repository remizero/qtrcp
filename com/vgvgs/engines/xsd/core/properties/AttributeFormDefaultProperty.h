#ifndef ATTRIBUTEFORMDEFAULTPROPERTY_H
#define ATTRIBUTEFORMDEFAULTPROPERTY_H

// Librerías Internas
#include "xsd_global.h"

// Librerías Externas
#include "macros_global.h"
#include "core/PropertyAbs.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

        class XSDSHARED_EXPORT AttributeFormDefaultProperty : public PropertyAbs {

            Q_OBJECT
            Q_ENUMS ( values )

          public :
            AttributeFormDefaultProperty ( QString value = "unqualified" );
            AttributeFormDefaultProperty ( const AttributeFormDefaultProperty& );
            ~AttributeFormDefaultProperty ();

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
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::AttributeFormDefaultProperty )

#endif // ATTRIBUTEFORMDEFAULTPROPERTY_H
