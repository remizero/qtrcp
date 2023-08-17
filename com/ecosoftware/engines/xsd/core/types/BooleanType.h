#ifndef BOOLEANTYPE_H
#define BOOLEANTYPE_H

// Librerías Internas
#include "../../xsd_global.h"
#include "../TypeAbs.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::BooleanType )

#endif // BOOLEANTYPE_H
