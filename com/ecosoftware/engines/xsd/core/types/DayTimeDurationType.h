#ifndef DAYTIMEDURATIONTYPE_H
#define DAYTIMEDURATIONTYPE_H

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

        class XSDSHARED_EXPORT DayTimeDurationType : public DurationType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            DayTimeDurationType ();
            DayTimeDurationType ( const DayTimeDurationType& );
            ~DayTimeDurationType ();

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::DayTimeDurationType )

#endif // DAYTIMEDURATIONTYPE_H
