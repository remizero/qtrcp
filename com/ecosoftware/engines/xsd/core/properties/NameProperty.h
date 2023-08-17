#ifndef NAMEPROPERTY_H
#define NAMEPROPERTY_H

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

        class XSDSHARED_EXPORT NameProperty : public PropertyAbs {

            Q_OBJECT

          public :
            Q_INVOKABLE NameProperty ( QString value = "" );
            Q_INVOKABLE NameProperty ( const NameProperty& );
            Q_INVOKABLE ~NameProperty ();

            Q_INVOKABLE QString getValue () const;
            Q_INVOKABLE void setValue ( const QString &value );

          private :
            Q_INVOKABLE QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::NameProperty )

#endif // NAMEPROPERTY_H
