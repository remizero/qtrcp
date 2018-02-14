#ifndef FIXEDPROPERTY_H
#define FIXEDPROPERTY_H

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

        class XSDSHARED_EXPORT FixedProperty : public PropertyAbs {

            Q_OBJECT

          public:
            FixedProperty ( QString value = "" );
            FixedProperty ( const FixedProperty& );
            ~FixedProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private:
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::FixedProperty )

#endif // FIXEDPROPERTY_H
