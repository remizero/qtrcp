#ifndef MAXEXCLUSIVEFACET_H
#define MAXEXCLUSIVEFACET_H

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

        class XSDSHARED_EXPORT MaxExclusiveFacet : public FacetAbs {

            Q_OBJECT
            Q_ENUMS ( properties )

          public:
            Q_INVOKABLE MaxExclusiveFacet ( QString value = "" );
            MaxExclusiveFacet ( const MaxExclusiveFacet& );
            ~MaxExclusiveFacet ();

            enum properties {

              FIXED = FacetAbs::properties::FIXED,
              ID = FacetAbs::properties::ID,
              VALUE = FacetAbs::properties::VALUE
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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::MaxExclusiveFacet )

#endif // MAXEXCLUSIVEFACET_H
