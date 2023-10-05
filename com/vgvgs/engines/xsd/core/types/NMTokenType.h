#ifndef NMTOKENTYPE_H
#define NMTOKENTYPE_H

// Librerías Internas
// Internal Libraries
#include "../../xsd_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "TokenType.h"

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
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::NMTokenType )

#endif // NMTOKENTYPE_H
