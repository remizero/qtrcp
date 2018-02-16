#ifndef ABSTRACTPROPERTY_H
#define ABSTRACTPROPERTY_H

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

        class XSDSHARED_EXPORT AbstractProperty : public PropertyAbs {

            Q_OBJECT

          public:
            AbstractProperty ( bool value = false );
            AbstractProperty ( const AbstractProperty& );
            ~AbstractProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private:
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::AbstractProperty )

#endif // ABSTRACTPROPERTY_H
