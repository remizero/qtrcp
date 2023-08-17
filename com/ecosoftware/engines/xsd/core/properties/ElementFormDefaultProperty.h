#ifndef ELEMENTFORMDEFAULTPROPERTY_H
#define ELEMENTFORMDEFAULTPROPERTY_H

// Librerías Internas
#include "xsd_global.h"
#include "core/PropertyAbs.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::ElementFormDefaultProperty )

#endif // ELEMENTFORMDEFAULTPROPERTY_H
