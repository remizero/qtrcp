#ifndef IDREFSTYPE_H
#define IDREFSTYPE_H

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

        class XSDSHARED_EXPORT IdRefsType : public TypeAbs {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            IdRefsType ();
            IdRefsType ( const IdRefsType& );
            ~IdRefsType ();

            enum facets {

              ASSERTIONS = FacetAbs::facets::ASSERTIONS,
              ENUMERATION = FacetAbs::facets::ENUMERATION,
              LENGTH = FacetAbs::facets::LENGTH,
              MAXLENGTH = FacetAbs::facets::MAXLENGTH,
              PATTERN = FacetAbs::facets::PATTERN
            };
            Q_ENUM ( facets )
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::IdRefsType )

#endif // IDREFSTYPE_H
