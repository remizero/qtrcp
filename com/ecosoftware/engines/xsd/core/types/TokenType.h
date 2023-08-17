#ifndef TOKENTYPE_H
#define TOKENTYPE_H

// Librerías Internas
#include "../../xsd_global.h"
#include "NormalizedStringType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::TokenType )

#endif // TOKENTYPE_H
