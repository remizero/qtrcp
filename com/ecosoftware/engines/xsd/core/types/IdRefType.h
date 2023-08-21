#ifndef IDREFTYPE_H
#define IDREFTYPE_H

// Librerías Internas
#include "../../xsd_global.h"

// Librerías Externas
#include "macros_global.h"
#include "NCNameType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

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
Q_DECLARE_METATYPE ( Com::Vgvgs::Engines::Xsd::IdRefType )

#endif // IDREFTYPE_H
