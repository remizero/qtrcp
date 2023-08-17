#ifndef REFPROPERTY_H
#define REFPROPERTY_H

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

        class XSDSHARED_EXPORT RefProperty : public PropertyAbs {

            Q_OBJECT

          public :
            RefProperty ( QString value = "" );
            RefProperty ( const RefProperty& );
            ~RefProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private :
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::RefProperty )

#endif // REFPROPERTY_H
