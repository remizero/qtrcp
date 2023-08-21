#ifndef ENTITIESTYPE_H
#define ENTITIESTYPE_H

// Librerías Internas
#include "../../xsd_global.h"

// Librerías Externas
#include "macros_global.h"
#include "../TypeAbs.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

        class XSDSHARED_EXPORT EntitiesType : public TypeAbs {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            EntitiesType ();
            EntitiesType ( const EntitiesType& );
            ~EntitiesType ();

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
Q_DECLARE_METATYPE ( Com::Vgvgs::Engines::Xsd::EntitiesType )

#endif // ENTITIESTYPE_H
