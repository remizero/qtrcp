#ifndef UNSIGNEDINTTYPE_H
#define UNSIGNEDINTTYPE_H

// Librerías Internas
#include "../../xsd_global.h"
#include "UnsignedLongType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT UnsignedIntType : public UnsignedLongType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            UnsignedIntType ();
            UnsignedIntType ( const UnsignedIntType& );
            ~UnsignedIntType ();

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::UnsignedIntType )

#endif // UNSIGNEDINTTYPE_H
