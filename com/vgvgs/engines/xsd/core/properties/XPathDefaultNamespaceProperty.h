#ifndef XPATHDEFAULTNAMESPACEPROPERTY_H
#define XPATHDEFAULTNAMESPACEPROPERTY_H

// Librerías Internas
// Internal Libraries
#include "xsd_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "core/PropertyAbs.h"

// Librerías Externas
// External Libraries
#include "Enumeration.h"

// Librerías Qt
// Qt Libraries
#include <QMetaEnum>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

        class XSDSHARED_EXPORT XPathDefaultNamespaceProperty : public PropertyAbs {

            Q_OBJECT

          public :
            XPathDefaultNamespaceProperty ( bool value = false );
            XPathDefaultNamespaceProperty ( const XPathDefaultNamespaceProperty& );
            ~XPathDefaultNamespaceProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private :
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::XPathDefaultNamespaceProperty )

#endif // XPATHDEFAULTNAMESPACEPROPERTY_H
