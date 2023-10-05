#ifndef SUBSTITUTIONGROUPPROPERTY_H
#define SUBSTITUTIONGROUPPROPERTY_H

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

        class XSDSHARED_EXPORT SubstitutionGroupProperty : public PropertyAbs {

            Q_OBJECT

          public :
            SubstitutionGroupProperty ( bool value = false );
            SubstitutionGroupProperty ( const SubstitutionGroupProperty& );
            ~SubstitutionGroupProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private :
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::SubstitutionGroupProperty )

#endif // SUBSTITUTIONGROUPPROPERTY_H
