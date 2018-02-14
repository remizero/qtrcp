#ifndef PROPERTYABS_H
#define PROPERTYABS_H

// Librerías Internas
#include "xsd_global.h"
#include "FacetAbs.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaObject>
#include <QMetaType>
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT PropertyAbs : public QObject {

            Q_OBJECT
            Q_ENUMS ( properties )

          public:
            Q_INVOKABLE PropertyAbs ( QObject *parent = 0 );
            PropertyAbs ( const PropertyAbs& );
            ~PropertyAbs ();

            enum properties {

              ABSTRACT = 1,
              APPLIESTOEMPTY,
              ATTRIBUTEFORMDEFAULT,
              BASE,
              BLOCK,
              BLOCKDEFAULT,
              DEFAULT,
              DEFAULTATTRIBUTES,
              DEFAULTATTRIBUTESAPPLY,
              ELEMENTFORMDEFAULT,
              FINAL,
              FINALDEFAULT,
              FIXED,
              FORM,
              ID,
              INHERITABLE,
              ITEMTYPE,
              MAXOCCURS,
              MEMBERTYPES,
              MINOCCURS,
              MIXED,
              MODE,
              NAME,
              NAMESPACE,
              NILLABLE,
              NOTNAMESPACE,
              NOTQNAME,
              PROCESSCONTENTS,
              PUBLIC,
              REF,
              REFER,
              SCHEMALOCATION,
              SOURCE,
              SUBSTITUTIONGROUP,
              SYSTEM,
              TARGETNAMESPACE,
              TEST,
              TYPE,
              USE,
              VERSION,
              XMLLANG,
              XPATH,
              XPATHDEFAULTNAMESPACE
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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::PropertyAbs )

#endif // PROPERTYABS_H
