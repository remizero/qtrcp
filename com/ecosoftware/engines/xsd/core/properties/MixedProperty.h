#ifndef MIXEDPROPERTY_H
#define MIXEDPROPERTY_H

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

        class XSDSHARED_EXPORT MixedProperty : public PropertyAbs {

            Q_OBJECT

          public :
            MixedProperty ( bool value = false );
            MixedProperty ( const MixedProperty& );
            ~MixedProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private :
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::MixedProperty )

#endif // MIXEDPROPERTY_H
