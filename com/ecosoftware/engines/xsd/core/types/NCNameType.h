#ifndef NCNAMETYPE_H
#define NCNAMETYPE_H

// Librerías Internas
#include "../../xsd_global.h"
#include "NameType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT NCNameType : public NameType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            NCNameType ();
            NCNameType ( const NCNameType& );
            ~NCNameType ();

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::NCNameType )

#endif // NCNAMETYPE_H
