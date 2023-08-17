#ifndef NONPOSITIVEINTEGERTYPE_H
#define NONPOSITIVEINTEGERTYPE_H

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

        class XSDSHARED_EXPORT NonPositiveIntegerType : public IntegerType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            NonPositiveIntegerType ();
            NonPositiveIntegerType ( const NonPositiveIntegerType& );
            ~NonPositiveIntegerType ();

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::NonPositiveIntegerType )

#endif // NONPOSITIVEINTEGERTYPE_H
