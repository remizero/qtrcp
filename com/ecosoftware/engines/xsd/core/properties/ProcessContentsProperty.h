#ifndef PROCESSCONTENTSPROPERTY_H
#define PROCESSCONTENTSPROPERTY_H

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

        class XSDSHARED_EXPORT ProcessContentsProperty : public PropertyAbs {

            Q_OBJECT

          public :
            ProcessContentsProperty ( bool value = false );
            ProcessContentsProperty ( const ProcessContentsProperty& );
            ~ProcessContentsProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private :
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::ProcessContentsProperty )

#endif // PROCESSCONTENTSPROPERTY_H
