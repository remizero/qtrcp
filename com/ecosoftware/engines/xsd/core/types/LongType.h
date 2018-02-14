#ifndef LONGTYPE_H
#define LONGTYPE_H

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

        class XSDSHARED_EXPORT LongType : public IntegerType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public:
            LongType ();
            LongType ( const LongType& );
            ~LongType ();

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::LongType )

#endif // LONGTYPE_H
