#ifndef REFERPROPERTY_H
#define REFERPROPERTY_H

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

        class XSDSHARED_EXPORT ReferProperty : public PropertyAbs {

            Q_OBJECT

          public :
            ReferProperty ( QString value = "" );
            ReferProperty ( const ReferProperty& );
            ~ReferProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private :
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::ReferProperty )

#endif // REFERPROPERTY_H
