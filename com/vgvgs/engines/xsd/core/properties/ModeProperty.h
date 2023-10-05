#ifndef MODEPROPERTY_H
#define MODEPROPERTY_H

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

        class XSDSHARED_EXPORT ModeProperty : public PropertyAbs {

            Q_OBJECT
            Q_ENUMS ( values )
            // TODO: para defaultopencontent
            // mode = (interleave | suffix) : interleave
            // TODO: para opencontent
            // mode = (none | interleave | suffix) : interleave
          public :
            ModeProperty ( QString value = "interleave" );
            ModeProperty ( const ModeProperty& );
            ~ModeProperty ();

            enum values {

              INTERLEAVE = 1,
              SUFFIX
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
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::ModeProperty )

#endif // MODEPROPERTY_H
