#ifndef MINOCCURSPROPERTY_H
#define MINOCCURSPROPERTY_H

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

        class XSDSHARED_EXPORT MinOccursProperty : public PropertyAbs {

            Q_OBJECT
            // TODO: para all
            // minOccurs = (0 | 1) : 1
            // TODO: para any
            // minOccurs = nonNegativeInteger : 1
            // TODO: para choice
            // minOccurs = nonNegativeInteger : 1
            // TODO: para element
            // minOccurs = nonNegativeInteger : 1
            // TODO: para group
            // minOccurs = nonNegativeInteger : 1
            // TODO: para sequence
            // minOccurs = nonNegativeInteger : 1

          public :
            MinOccursProperty ( bool value = false );
            MinOccursProperty ( const MinOccursProperty& );
            ~MinOccursProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private :
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::MinOccursProperty )

#endif // MINOCCURSPROPERTY_H
