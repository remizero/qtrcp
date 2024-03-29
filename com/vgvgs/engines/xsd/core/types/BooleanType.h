#ifndef BOOLEANTYPE_H
#define BOOLEANTYPE_H

// Librerías Internas
// Internal Libraries
#include "../../xsd_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "../TypeAbs.h"

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

        class XSDSHARED_EXPORT BooleanType : public TypeAbs {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            BooleanType ();
            BooleanType ( const BooleanType& );
            ~BooleanType ();

            enum facets {

              ASSERTIONS = FacetAbs::facets::ASSERTIONS,
              PATTERN = FacetAbs::facets::PATTERN
            };
            Q_ENUM ( facets )
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::BooleanType )

#endif // BOOLEANTYPE_H
