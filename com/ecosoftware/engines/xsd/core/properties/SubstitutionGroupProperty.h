#ifndef SUBSTITUTIONGROUPPROPERTY_H
#define SUBSTITUTIONGROUPPROPERTY_H

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

        class XSDSHARED_EXPORT SubstitutionGroupProperty : public PropertyAbs {

            Q_OBJECT

          public:
            SubstitutionGroupProperty ( bool value = false );
            SubstitutionGroupProperty ( const SubstitutionGroupProperty& );
            ~SubstitutionGroupProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private:
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::SubstitutionGroupProperty )

#endif // SUBSTITUTIONGROUPPROPERTY_H
