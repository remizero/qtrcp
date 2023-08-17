#ifndef SCHEMALOCATIONPROPERTY_H
#define SCHEMALOCATIONPROPERTY_H

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

        class XSDSHARED_EXPORT SchemaLocationProperty : public PropertyAbs {

            Q_OBJECT

          public :
            SchemaLocationProperty ( bool value = false );
            SchemaLocationProperty ( const SchemaLocationProperty& );
            ~SchemaLocationProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private :
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::SchemaLocationProperty )

#endif // SCHEMALOCATIONPROPERTY_H
