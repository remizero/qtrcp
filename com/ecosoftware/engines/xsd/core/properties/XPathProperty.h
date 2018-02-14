#ifndef XPATHPROPERTY_H
#define XPATHPROPERTY_H

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

        class XSDSHARED_EXPORT XPathProperty : public PropertyAbs {

            Q_OBJECT

          public:
            XPathProperty ( bool value = false );
            XPathProperty ( const XPathProperty& );
            ~XPathProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private:
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::XPathProperty )

#endif // XPATHPROPERTY_H
