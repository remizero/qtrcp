#ifndef XSD_H
#define XSD_H

// Librerías Internas
#include "xsd_global.h"

// Librerías Externas
#include "macros_global.h"
#include "core/ElementAbs.h"
#include "core/PropertyAbs.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

        class XSDSHARED_EXPORT Xsd: public QObject {

            Q_OBJECT
            Q_ENUMS ( indicatorEnum levelEnum )

          public :
            Xsd ();

            enum indicatorEnum {

              ALL = ElementAbs::elements::ALL,
              ATTRIBUTEGROUP = ElementAbs::elements::ATTRIBUTEGROUP,
              CHOICE = ElementAbs::elements::CHOICE,
              GROUP = ElementAbs::elements::GROUP,
              MAXOCCURS = PropertyAbs::properties::MAXOCCURS,
              MINOCCURS = PropertyAbs::properties::MINOCCURS,
              SEQUENCE = ElementAbs::elements::SEQUENCE

              // Aparentan ser otros indicadores
              //xs:union
              //xs:list
              //xs:mixed
            };
            Q_ENUM ( indicatorEnum )

            enum levelEnum {

              EMPTY = 0,
              ROOTFORM,
              TABFORM,
              GROUPFORM,
              PARAMFORM,
              TYPEFORM,
              VALUEFORM
            };
            Q_ENUM ( levelEnum )

            static int indexOfLevelEnum ( QString enumKey );
            static bool inLevelEmun ( QString enumKey );
            static QString levelEnumToString ( Xsd::levelEnum enumValue );
        };
      }
    }
  }
}

#endif // XSD_H
