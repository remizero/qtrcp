#ifndef USEPROPERTY_H
#define USEPROPERTY_H

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

        class XSDSHARED_EXPORT UseProperty : public PropertyAbs {

            Q_OBJECT

          public :
            UseProperty ( bool value = false );
            UseProperty ( const UseProperty& );
            ~UseProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private :
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::UseProperty )

#endif // USEPROPERTY_H
