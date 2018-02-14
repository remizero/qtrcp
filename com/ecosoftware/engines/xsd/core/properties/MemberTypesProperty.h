#ifndef MEMBERTYPESPROPERTY_H
#define MEMBERTYPESPROPERTY_H

// Librerías Internas
#include "xsd_global.h"
#include "core/PropertyAbs.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT MemberTypesProperty : public PropertyAbs {

            Q_OBJECT

          public:
            MemberTypesProperty ( QString value = "" );
            MemberTypesProperty ( const MemberTypesProperty& );
            ~MemberTypesProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private:
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::MemberTypesProperty )

#endif // MEMBERTYPESPROPERTY_H
