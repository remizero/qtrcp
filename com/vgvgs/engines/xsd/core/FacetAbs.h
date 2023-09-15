#ifndef FACETSABS_H
#define FACETSABS_H

// Librerías Internas
#include "xsd_global.h"

// Librerías Externas
#include "macros_global.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

        class XSDSHARED_EXPORT FacetAbs : public QObject {

            Q_OBJECT
            Q_ENUMS ( content facets properties )

          public :
            Q_INVOKABLE FacetAbs ( QString value = "" );
            FacetAbs ( const FacetAbs& );
            ~FacetAbs ();

            enum content {

              ANNOTATION = 1
            };
            Q_ENUM ( content )

            enum facets {

              ASSERTIONS = 1,
              ENUMERATION, //	Defines a list of acceptable values
              EXPLICITTIMEZONE,
              FRACTIONDIGITS, //	Specifies the maximum number of decimal places allowed. Must be equal to or greater than zero
              LENGTH, //	Specifies the exact number of characters or list items allowed. Must be equal to or greater than zero
              MAXEXCLUSIVE, //	Specifies the upper bounds for numeric values (the value must be less than this value)
              MAXINCLUSIVE, //	Specifies the upper bounds for numeric values (the value must be less than or equal to this value)
              MAXLENGTH, //	Specifies the maximum number of characters or list items allowed. Must be equal to or greater than zero
              MINEXCLUSIVE, //	Specifies the lower bounds for numeric values (the value must be greater than this value)
              MININCLUSIVE, //	Specifies the lower bounds for numeric values (the value must be greater than or equal to this value)
              MINLENGTH, //	Specifies the minimum number of characters or list items allowed. Must be equal to or greater than zero
              PATTERN, //	Defines the exact sequence of characters that are acceptable
              TOTALDIGITS, //	Specifies the maximum number of digits allowed. Must be greater than zero
              WHITESPACE //	Specifies how white space (line feeds, tabs, spaces, and carriage returns) is handled
            };
            Q_ENUM ( facets )

            /*
             * whitespace
             *
             * preserve
             * replace
             * collapse
             */
            enum properties {

              FIXED = 1,
              ID,
              TEST,
              VALUE,
              XPATHDEFAULTNAMESPACE
            };
            Q_ENUM ( properties )

            Q_INVOKABLE static int indexOfContentEnum ( QString enumKey );
            Q_INVOKABLE static bool inContentEmun ( QString enumKey );
            Q_INVOKABLE static QString contentEnumToString ( facets enumValue );

            Q_INVOKABLE static int indexOfFacetsEnum ( QString enumKey );
            Q_INVOKABLE static bool inFacetsEmun ( QString enumKey );
            Q_INVOKABLE static QString facetsEnumToString ( facets enumValue );

            Q_INVOKABLE static int indexOfPropertiesEnum ( QString enumKey );
            Q_INVOKABLE static bool inPropertiesEmun ( QString enumKey );
            Q_INVOKABLE static QString propertiesEnumToString ( facets enumValue );

            QString getValue () const;
            void setValue ( const QString &value );

          protected :
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Vgvgs::Engines::Xsd::FacetAbs )

#endif // FACETSABS_H
