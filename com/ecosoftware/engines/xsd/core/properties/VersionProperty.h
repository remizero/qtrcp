#ifndef VERSIONPROPERTY_H
#define VERSIONPROPERTY_H

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

        class XSDSHARED_EXPORT VersionProperty : public PropertyAbs {

            Q_OBJECT

          public :
            VersionProperty ( bool value = false );
            VersionProperty ( const VersionProperty& );
            ~VersionProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private :
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::VersionProperty )

#endif // VERSIONPROPERTY_H
