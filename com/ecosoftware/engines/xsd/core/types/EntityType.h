#ifndef ENTITYTYPE_H
#define ENTITYTYPE_H

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

        class XSDSHARED_EXPORT EntityType : public NCNameType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public:
            EntityType ();
            EntityType ( const EntityType& );
            ~EntityType ();

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::EntityType )

#endif // ENTITYTYPE_H
