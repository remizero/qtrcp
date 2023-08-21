#ifndef NORMALIZEDSTRINGTYPE_H
#define NORMALIZEDSTRINGTYPE_H

// Librerías Internas
#include "../../xsd_global.h"

// Librerías Externas
#include "macros_global.h"
#include "StringType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

        class XSDSHARED_EXPORT NormalizedStringType : public StringType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            NormalizedStringType ();
            NormalizedStringType ( const NormalizedStringType& );
            ~NormalizedStringType ();

            enum facets {

              ASSERTIONS = FacetAbs::facets::ASSERTIONS,
              ENUMERATION = FacetAbs::facets::ENUMERATION,
              LENGTH = FacetAbs::facets::LENGTH,
              MAXLENGTH = FacetAbs::facets::MAXLENGTH,
              MINLENGTH = FacetAbs::facets::MINLENGTH,
              PATTERN = FacetAbs::facets::PATTERN
            };
            Q_ENUM ( facets )
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Vgvgs::Engines::Xsd::NormalizedStringType )

#endif // NORMALIZEDSTRINGTYPE_H
