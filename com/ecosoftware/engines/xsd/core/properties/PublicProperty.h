#ifndef PUBLICPROPERTY_H
#define PUBLICPROPERTY_H

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

        class XSDSHARED_EXPORT PublicProperty : public PropertyAbs {

            Q_OBJECT

          public:
            PublicProperty ( QString value = "" );
            PublicProperty ( const PublicProperty& );
            ~PublicProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private:
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::PublicProperty )

#endif // PUBLICPROPERTY_H
