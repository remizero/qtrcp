#ifndef UNSIGNEDBYTETYPE_H
#define UNSIGNEDBYTETYPE_H

// Librerías Internas
#include "../../xsd_global.h"
#include "UnsignedShortType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT UnsignedByteType : public UnsignedShortType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            UnsignedByteType ();
            UnsignedByteType ( const UnsignedByteType& );
            ~UnsignedByteType ();

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::UnsignedByteType )

#endif // UNSIGNEDBYTETYPE_H
