#ifndef NORMALIZEDSTRINGTYPE_H
#define NORMALIZEDSTRINGTYPE_H

// Librerías Internas
#include "../../xsd_global.h"
#include "StringType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::NormalizedStringType )

#endif // NORMALIZEDSTRINGTYPE_H
