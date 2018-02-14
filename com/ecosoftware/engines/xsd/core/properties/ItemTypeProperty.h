#ifndef ITEMTYPEPROPERTY_H
#define ITEMTYPEPROPERTY_H

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

        class XSDSHARED_EXPORT ItemTypeProperty : public PropertyAbs {

            Q_OBJECT

          public:
            ItemTypeProperty ( QString value = "" );
            ItemTypeProperty ( const ItemTypeProperty& );
            ~ItemTypeProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private:
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::ItemTypeProperty )

#endif // ITEMTYPEPROPERTY_H
