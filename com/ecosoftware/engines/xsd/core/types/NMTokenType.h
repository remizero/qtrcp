#ifndef NMTOKENTYPE_H
#define NMTOKENTYPE_H

// Librerías Internas
#include "../../xsd_global.h"
#include "TokenType.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT NMTokenType : public TokenType {

            Q_OBJECT
            Q_ENUMS ( facets )

          public :
            NMTokenType ();
            NMTokenType ( const NMTokenType& );
            ~NMTokenType ();

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::NMTokenType )

#endif // NMTOKENTYPE_H
