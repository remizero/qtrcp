#ifndef MAXOCCURSPROPERTY_H
#define MAXOCCURSPROPERTY_H

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

          public:
            MaxOccursProperty ( bool value = false );
            MaxOccursProperty ( const MaxOccursProperty& );
            ~MaxOccursProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private:
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::MaxOccursProperty )

#endif // MAXOCCURSPROPERTY_H
