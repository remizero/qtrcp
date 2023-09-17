#ifndef SHORTTYPE_H
#define SHORTTYPE_H

// Librerías Internas
#include "../../xsd_global.h"

// Librerías Externas
#include "macros_global.h"
#include "IntType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

        class XSDSHARED_EXPORT ShortType : public IntType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            ShortType ();
            ShortType ( const ShortType& );
            ~ShortType ();

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
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::ShortType )

#endif // SHORTTYPE_H
