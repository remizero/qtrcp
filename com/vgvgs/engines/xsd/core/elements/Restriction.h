#ifndef RESTRICTION_H
#define RESTRICTION_H

// Librerías Internas
#include "xsd_global.h"

// Librerías Externas
#include "macros_global.h"
#include "core/ElementAbs.h"
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

        class XSDSHARED_EXPORT Restriction : public ElementAbs {

            Q_OBJECT
            Q_ENUMS ( content properties )

          public :
            Q_INVOKABLE Restriction ();
            Restriction ( const Restriction& );
            ~Restriction ();

            enum content {

              // TODO: Como hacer con ANNOTATION y ENUMERATION pues tienen el mismo valor
              ANNOTATION = ElementAbs::elements::ANNOTATION,
              ASSERTION = FacetAbs::facets::ASSERTIONS,
              ENUMERATION = FacetAbs::facets::ENUMERATION,
              EXPLICITTIMEZONE = FacetAbs::facets::EXPLICITTIMEZONE,
              FRACTIONDIGITS = FacetAbs::facets::FRACTIONDIGITS,
              LENGTH = FacetAbs::facets::LENGTH,
              MAXEXCLUSIVE = FacetAbs::facets::MAXEXCLUSIVE,
              MAXINCLUSIVE = FacetAbs::facets::MAXINCLUSIVE,
              MAXLENGTH = FacetAbs::facets::MAXLENGTH,
              MINEXCLUSIVE = FacetAbs::facets::MINEXCLUSIVE,
              MININCLUSIVE = FacetAbs::facets::MININCLUSIVE,
              MINLENGTH = FacetAbs::facets::MINLENGTH,
              PATTERN = FacetAbs::facets::PATTERN,
              SIMPLETYPE = ElementAbs::elements::SIMPLETYPE,
              TOTALDIGITS = FacetAbs::facets::TOTALDIGITS,
              WHITESPACE = FacetAbs::facets::WHITESPACE
            };
            Q_ENUM ( content )

            enum properties {

              BASE = PropertyAbs::properties::BASE,
              ID = PropertyAbs::properties::ID
            };
            Q_ENUM ( properties )

            Q_INVOKABLE static int indexOfContentEnum ( QString enumKey );
            Q_INVOKABLE static bool inContentEmun ( QString enumKey );
            Q_INVOKABLE static QString contentEnumToString ( content enumValue );
            Q_INVOKABLE static int indexOfPropertiesEnum ( QString enumKey );
            Q_INVOKABLE static bool inPropertiesEmun ( QString enumKey );
            Q_INVOKABLE static QString propertiesEnumToString ( properties enumValue );
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::Restriction )

#endif // RESTRICTION_H
