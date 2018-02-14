#ifndef MINOCCURSPROPERTY_H
#define MINOCCURSPROPERTY_H

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

          public:
            MinOccursProperty ( bool value = false );
            MinOccursProperty ( const MinOccursProperty& );
            ~MinOccursProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private:
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::MinOccursProperty )

#endif // MINOCCURSPROPERTY_H
