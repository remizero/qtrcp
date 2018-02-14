#ifndef TYPEPROPERTY_H
#define TYPEPROPERTY_H

// Librerías Internas
#include "xsd_global.h"
#include "core/PropertyAbs.h"
#include "core/TypeAbs.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT TypeProperty : public PropertyAbs {

            Q_OBJECT

          public:
            Q_INVOKABLE TypeProperty ( QString value = "" );
            Q_INVOKABLE TypeProperty ( const TypeProperty& );
            Q_INVOKABLE ~TypeProperty ();

            Q_INVOKABLE TypeAbs::types getValue () const;
            Q_INVOKABLE void setValue ( const QString value );
            Q_INVOKABLE void setValue ( TypeAbs::types value );
            Q_INVOKABLE int toInt ();
            Q_INVOKABLE QString toString ();

          private:
            TypeAbs::types value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::TypeProperty )

#endif // TYPEPROPERTY_H
