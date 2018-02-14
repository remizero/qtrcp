#ifndef POSITIVEINTEGERTYPE_H
#define POSITIVEINTEGERTYPE_H

// Librerías Internas
#include "../../xsd_global.h"
#include "NonNegativeIntegerType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT PositiveIntegerType : public NonNegativeIntegerType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public:
            PositiveIntegerType ();
            PositiveIntegerType ( const PositiveIntegerType& );
            ~PositiveIntegerType ();

            enum facets {

              ASSERTIONS = FacetAbs::facets::ASSERTIONS,
              ENUMERATION = FacetAbs::facets::ENUMERATION,
              MAXEXCLUSIVE = FacetAbs::facets::MAXEXCLUSIVE,
              MAXINCLUSIVE = FacetAbs::facets::MAXINCLUSIVE,
              MINEXCLUSIVE = FacetAbs::facets::MINEXCLUSIVE,
              TOTALDIGITS = FacetAbs::facets::TOTALDIGITS
            };
            Q_ENUM ( facets )
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::PositiveIntegerType )

#endif // POSITIVEINTEGERTYPE_H
