#ifndef APPLIESTOEMPTYPROPERTY_H
#define APPLIESTOEMPTYPROPERTY_H

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

        class XSDSHARED_EXPORT AppliesToEmptyProperty : public PropertyAbs {

            Q_OBJECT

          public:
            AppliesToEmptyProperty ( bool value = false );
            AppliesToEmptyProperty ( const AppliesToEmptyProperty& );
            ~AppliesToEmptyProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private:
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::AppliesToEmptyProperty )

#endif // APPLIESTOEMPTYPROPERTY_H
