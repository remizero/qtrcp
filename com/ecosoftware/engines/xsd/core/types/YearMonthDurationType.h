#ifndef YEARMONTHDURATIONTYPE_H
#define YEARMONTHDURATIONTYPE_H

// Librerías Internas
#include "../../xsd_global.h"
#include "DurationType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT YearMonthDurationType : public DurationType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public:
            YearMonthDurationType ();
            YearMonthDurationType ( const YearMonthDurationType& );
            ~YearMonthDurationType ();

            enum facets {

              ASSERTIONS = FacetAbs::facets::ASSERTIONS,
              ENUMERATION = FacetAbs::facets::ENUMERATION,
              MAXEXCLUSIVE = FacetAbs::facets::MAXEXCLUSIVE,
              MAXINCLUSIVE = FacetAbs::facets::MAXINCLUSIVE,
              MINEXCLUSIVE = FacetAbs::facets::MINEXCLUSIVE,
              MININCLUSIVE = FacetAbs::facets::MININCLUSIVE
            };
            Q_ENUM ( facets )
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::YearMonthDurationType )

#endif // YEARMONTHDURATIONTYPE_H
