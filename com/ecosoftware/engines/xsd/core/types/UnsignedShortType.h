#ifndef UNSIGNEDSHORTTYPE_H
#define UNSIGNEDSHORTTYPE_H

// Librerías Internas
#include "../../xsd_global.h"
#include "UnsignedIntType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT UnsignedShortType : public UnsignedIntType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public:
            UnsignedShortType ();
            UnsignedShortType ( const UnsignedShortType& );
            ~UnsignedShortType ();

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::UnsignedShortType )

#endif // UNSIGNEDSHORTTYPE_H
