#ifndef PATTERNFACET_H
#define PATTERNFACET_H

// Librerías Internas
#include "xsd_global.h"

// Librerías Externas
#include "macros_global.h"
#include "core/FacetAbs.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

        class XSDSHARED_EXPORT PatternFacet : public FacetAbs {

            Q_OBJECT
            Q_ENUMS ( properties )

          public :
            Q_INVOKABLE PatternFacet ( QString value = "" );
            PatternFacet ( const PatternFacet& );
            ~PatternFacet ();

            enum properties {

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
Q_DECLARE_METATYPE ( Com::Vgvgs::Engines::Xsd::PatternFacet )

#endif // PATTERNFACET_H
