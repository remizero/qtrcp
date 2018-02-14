#ifndef INTTYPE_H
#define INTTYPE_H

// Librerías Internas
#include "../../xsd_global.h"
#include "LongType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT IntType : public LongType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public:
            IntType ();
            IntType ( const IntType& );
            ~IntType ();

            enum facets {

              ASSERTIONS = FacetAbs::facets::ASSERTIONS,
              ENUMERATION = FacetAbs::facets::ENUMERATION,
              MAXEXCLUSIVE = FacetAbs::facets::MAXEXCLUSIVE,
              MINEXCLUSIVE = FacetAbs::facets::MINEXCLUSIVE,
              TOTALDIGITS = FacetAbs::facets::TOTALDIGITS
            };
            Q_ENUM ( facets )
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::IntType )

#endif // INTTYPE_H
