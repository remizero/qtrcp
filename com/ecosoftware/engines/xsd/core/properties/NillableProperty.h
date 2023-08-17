#ifndef NILLABLEPROPERTY_H
#define NILLABLEPROPERTY_H

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

        class XSDSHARED_EXPORT NillableProperty : public PropertyAbs {

            Q_OBJECT

          public :
            NillableProperty ( bool value = false );
            NillableProperty ( const NillableProperty& );
            ~NillableProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private :
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::NillableProperty )

#endif // NILLABLEPROPERTY_H
