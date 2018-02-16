#ifndef ASSERTIONSFACET_H
#define ASSERTIONSFACET_H

// Librerías Internas
#include "xsd_global.h"
#include "core/FacetAbs.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT AssertionsFacet : public FacetAbs {

            Q_OBJECT
            Q_ENUMS ( properties )

          public:
            Q_INVOKABLE AssertionsFacet ( QString value = "" );
            AssertionsFacet ( const AssertionsFacet& );
            ~AssertionsFacet ();

            enum properties {

              ID = FacetAbs::properties::ID,
              TEST = FacetAbs::properties::TEST,
              XPATHDEFAULTNAMESPACE = FacetAbs::properties::XPATHDEFAULTNAMESPACE
            };
            Q_ENUM ( properties )

            Q_INVOKABLE static int indexOfEnum ( QString enumKey );
            Q_INVOKABLE static bool inEmun ( QString enumKey );
            Q_INVOKABLE static QString enumToString ( properties enumValue );
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::AssertionsFacet )

#endif // ASSERTIONSFACET_H
