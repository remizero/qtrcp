#ifndef INHERITABLEPROPERTY_H
#define INHERITABLEPROPERTY_H

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

        class XSDSHARED_EXPORT InheritableProperty : public PropertyAbs {

            Q_OBJECT

          public :
            InheritableProperty ( bool value = false );
            InheritableProperty ( const InheritableProperty& );
            ~InheritableProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private :
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Vgvgs::Engines::Xsd::InheritableProperty )

#endif // INHERITABLEPROPERTY_H
