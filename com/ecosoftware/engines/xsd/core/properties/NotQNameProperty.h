#ifndef NOTQNAMEPROPERTY_H
#define NOTQNAMEPROPERTY_H

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

        class XSDSHARED_EXPORT NotQNameProperty : public PropertyAbs {

            Q_OBJECT

          public :
            NotQNameProperty ( bool value = false );
            NotQNameProperty ( const NotQNameProperty& );
            ~NotQNameProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private :
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::NotQNameProperty )

#endif // NOTQNAMEPROPERTY_H
