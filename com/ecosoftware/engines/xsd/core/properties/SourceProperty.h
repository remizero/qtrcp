#ifndef SOURCEPROPERTY_H
#define SOURCEPROPERTY_H

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

        class XSDSHARED_EXPORT SourceProperty : public PropertyAbs {

            Q_OBJECT

          public:
            SourceProperty ( bool value = false );
            SourceProperty ( const SourceProperty& );
            ~SourceProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private:
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::SourceProperty )

#endif // SOURCEPROPERTY_H
