#ifndef NEGATIVEINTEGERTYPE_H
#define NEGATIVEINTEGERTYPE_H

// Librerías Internas
#include "../../xsd_global.h"
#include "NonPositiveIntegerType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT NegativeIntegerType : public NonPositiveIntegerType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            NegativeIntegerType ();
            NegativeIntegerType ( const NegativeIntegerType& );
            ~NegativeIntegerType ();

            enum facets {

              ASSERTIONS = FacetAbs::facets::ASSERTIONS,
              ENUMERATION = FacetAbs::facets::ENUMERATION,
              MAXEXCLUSIVE = FacetAbs::facets::MAXEXCLUSIVE,
              MINEXCLUSIVE = FacetAbs::facets::MINEXCLUSIVE,
              MININCLUSIVE = FacetAbs::facets::MININCLUSIVE,
              TOTALDIGITS = FacetAbs::facets::TOTALDIGITS
            };
            Q_ENUM ( facets )
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::NegativeIntegerType )

#endif // NEGATIVEINTEGERTYPE_H
