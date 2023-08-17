#ifndef DECIMALTYPE_H
#define DECIMALTYPE_H

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

        class XSDSHARED_EXPORT DecimalType : public TypeAbs {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            DecimalType ();
            DecimalType ( const DecimalType& );
            ~DecimalType ();

            enum facets {

              ASSERTIONS = FacetAbs::facets::ASSERTIONS,
              ENUMERATION = FacetAbs::facets::ENUMERATION,
              FRACTIONDIGITS = FacetAbs::facets::FRACTIONDIGITS,
              MAXEXCLUSIVE = FacetAbs::facets::MAXEXCLUSIVE,
              MAXINCLUSIVE = FacetAbs::facets::MAXINCLUSIVE,
              MINEXCLUSIVE = FacetAbs::facets::MINEXCLUSIVE,
              MININCLUSIVE = FacetAbs::facets::MININCLUSIVE,
              PATTERN = FacetAbs::facets::PATTERN,
              TOTALDIGITS = FacetAbs::facets::TOTALDIGITS
            };
            Q_ENUM ( facets )
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::DecimalType )

#endif // DECIMALTYPE_H
