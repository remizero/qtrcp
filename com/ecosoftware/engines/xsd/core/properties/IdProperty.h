#ifndef IDPROPERTY_H
#define IDPROPERTY_H

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

        class XSDSHARED_EXPORT IdProperty : public PropertyAbs {

            Q_OBJECT

          public :
            IdProperty ( QString value = "" );
            IdProperty ( const IdProperty& );
            ~IdProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private :
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::IdProperty )

#endif // IDPROPERTY_H
