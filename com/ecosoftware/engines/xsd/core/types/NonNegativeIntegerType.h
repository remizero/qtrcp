#ifndef NONNEGATIVEINTEGERTYPE_H
#define NONNEGATIVEINTEGERTYPE_H

// Librerías Internas
#include "../../xsd_global.h"
#include "IntegerType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT NonNegativeIntegerType : public IntegerType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public:
            NonNegativeIntegerType ();
            NonNegativeIntegerType ( const NonNegativeIntegerType& );
            ~NonNegativeIntegerType ();

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::NonNegativeIntegerType )

#endif // NONNEGATIVEINTEGERTYPE_H
