#ifndef DOUBLETYPE_H
#define DOUBLETYPE_H

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

        class XSDSHARED_EXPORT DoubleType : public TypeAbs {

            Q_OBJECT
            Q_ENUMS ( facets )

          public:
            DoubleType ();
            DoubleType ( const DoubleType& );
            ~DoubleType ();

            enum facets {

              ASSERTIONS = FacetAbs::facets::ASSERTIONS,
              ENUMERATION = FacetAbs::facets::ENUMERATION,
              MAXEXCLUSIVE = FacetAbs::facets::MAXEXCLUSIVE,
              MAXINCLUSIVE = FacetAbs::facets::MAXINCLUSIVE,
              MINEXCLUSIVE = FacetAbs::facets::MINEXCLUSIVE,
              MININCLUSIVE = FacetAbs::facets::MININCLUSIVE,
              PATTERN = FacetAbs::facets::PATTERN
            };
            Q_ENUM ( facets )
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::DoubleType )

#endif // DOUBLETYPE_H
