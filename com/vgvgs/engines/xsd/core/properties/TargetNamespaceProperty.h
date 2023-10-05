#ifndef TARGETNAMESPACEPROPERTY_H
#define TARGETNAMESPACEPROPERTY_H

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

        class XSDSHARED_EXPORT TargetNamespaceProperty : public PropertyAbs {

            Q_OBJECT

          public :
            TargetNamespaceProperty ( bool value = false );
            TargetNamespaceProperty ( const TargetNamespaceProperty& );
            ~TargetNamespaceProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private :
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::TargetNamespaceProperty )

#endif // TARGETNAMESPACEPROPERTY_H
