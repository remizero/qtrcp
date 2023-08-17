#ifndef IDREFTYPE_H
#define IDREFTYPE_H

// Librerías Internas
#include "../../xsd_global.h"
#include "NCNameType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT IdRefType : public NCNameType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            IdRefType ();
            IdRefType ( const IdRefType& );
            ~IdRefType ();

            enum facets {

              ASSERTIONS = FacetAbs::facets::ASSERTIONS,
              ENUMERATION = FacetAbs::facets::ENUMERATION,
              LENGTH = FacetAbs::facets::LENGTH,
              MAXLENGTH = FacetAbs::facets::MAXLENGTH,
              MINLENGTH = FacetAbs::facets::MINLENGTH
            };
            Q_ENUM ( facets )
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::IdRefType )

#endif // IDREFTYPE_H
