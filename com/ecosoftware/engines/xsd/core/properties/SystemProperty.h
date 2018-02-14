#ifndef SYSTEMPROPERTY_H
#define SYSTEMPROPERTY_H

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

        class XSDSHARED_EXPORT SystemProperty : public PropertyAbs {

            Q_OBJECT

          public:
            SystemProperty ( bool value = false );
            SystemProperty ( const SystemProperty& );
            ~SystemProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private:
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::SystemProperty )

#endif // SYSTEMPROPERTY_H
