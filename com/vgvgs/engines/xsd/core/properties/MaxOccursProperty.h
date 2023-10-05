#ifndef MAXOCCURSPROPERTY_H
#define MAXOCCURSPROPERTY_H

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

        class XSDSHARED_EXPORT MaxOccursProperty : public PropertyAbs {

            Q_OBJECT
            // TODO: para all
            // maxOccurs = (0 | 1) : 1
            // TODO: para any
            // maxOccurs = (nonNegativeInteger | unbounded)  : 1
            // TODO: para choice
            // maxOccurs = (nonNegativeInteger | unbounded)  : 1
            // TODO: para element
            // maxOccurs = (nonNegativeInteger | unbounded)  : 1
            // TODO: para group
            // maxOccurs = (nonNegativeInteger | unbounded)  : 1
            // TODO: para sequence
            // maxOccurs = (nonNegativeInteger | unbounded)  : 1

          public :
            MaxOccursProperty ( bool value = false );
            MaxOccursProperty ( const MaxOccursProperty& );
            ~MaxOccursProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private :
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::MaxOccursProperty )

#endif // MAXOCCURSPROPERTY_H
