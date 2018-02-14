#ifndef DEFAULTATTRIBUTESAPPLYPROPERTY_H
#define DEFAULTATTRIBUTESAPPLYPROPERTY_H

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

        class XSDSHARED_EXPORT DefaultAttributesApplyProperty : public PropertyAbs {

            Q_OBJECT

          public:
            DefaultAttributesApplyProperty ( bool value = false );
            DefaultAttributesApplyProperty ( const DefaultAttributesApplyProperty& );
            ~DefaultAttributesApplyProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private:
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::DefaultAttributesApplyProperty )

#endif // DEFAULTATTRIBUTESAPPLYPROPERTY_H
