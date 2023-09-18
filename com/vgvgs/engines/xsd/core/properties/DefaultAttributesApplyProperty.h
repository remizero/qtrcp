#ifndef DEFAULTATTRIBUTESAPPLYPROPERTY_H
#define DEFAULTATTRIBUTESAPPLYPROPERTY_H

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

        class XSDSHARED_EXPORT DefaultAttributesApplyProperty : public PropertyAbs {

            Q_OBJECT

          public :
            DefaultAttributesApplyProperty ( bool value = false );
            DefaultAttributesApplyProperty ( const DefaultAttributesApplyProperty& );
            ~DefaultAttributesApplyProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private :
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::DefaultAttributesApplyProperty )

#endif // DEFAULTATTRIBUTESAPPLYPROPERTY_H