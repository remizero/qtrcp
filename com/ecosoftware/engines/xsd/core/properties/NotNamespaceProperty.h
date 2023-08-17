#ifndef NOTNAMESPACEPROPERTY_H
#define NOTNAMESPACEPROPERTY_H

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

        class XSDSHARED_EXPORT NotNamespaceProperty : public PropertyAbs {

            Q_OBJECT

          public :
            NotNamespaceProperty ( bool value = false );
            NotNamespaceProperty ( const NotNamespaceProperty& );
            ~NotNamespaceProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private :
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::NotNamespaceProperty )

#endif // NOTNAMESPACEPROPERTY_H
