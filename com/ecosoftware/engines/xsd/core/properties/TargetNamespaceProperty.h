#ifndef TARGETNAMESPACEPROPERTY_H
#define TARGETNAMESPACEPROPERTY_H

// Librerías Internas
#include "xsd_global.h"

// Librerías Externas
#include "macros_global.h"
#include "core/PropertyAbs.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
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
Q_DECLARE_METATYPE ( Com::Vgvgs::Engines::Xsd::TargetNamespaceProperty )

#endif // TARGETNAMESPACEPROPERTY_H
