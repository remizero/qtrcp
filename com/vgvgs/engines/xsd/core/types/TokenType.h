#ifndef TOKENTYPE_H
#define TOKENTYPE_H

// Librerías Internas
// Internal Libraries
#include "../../xsd_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "NormalizedStringType.h"

// Librerías Externas
// External Libraries
#include "Enumeration.h"

// Librerías Qt
// Qt Libraries
#include <QMetaEnum>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

        class XSDSHARED_EXPORT TokenType : public NormalizedStringType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            TokenType ();
            TokenType ( const TokenType& );
            ~TokenType ();

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
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::TokenType )

#endif // TOKENTYPE_H
