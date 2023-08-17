#ifndef DATETIMESTAMPTYPE_H
#define DATETIMESTAMPTYPE_H

// Librerías Internas
#include "../../xsd_global.h"
#include "DateTimeType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT DateTimeStampType : public DateTimeType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            DateTimeStampType ();
            DateTimeStampType ( const DateTimeStampType& );
            ~DateTimeStampType ();

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::DateTimeStampType )

#endif // DATETIMESTAMPTYPE_H
