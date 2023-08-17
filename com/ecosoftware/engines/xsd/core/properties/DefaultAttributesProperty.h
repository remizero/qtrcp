#ifndef DEFAULTATTRIBUTESPROPERTY_H
#define DEFAULTATTRIBUTESPROPERTY_H

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

        class XSDSHARED_EXPORT DefaultAttributesProperty : public PropertyAbs {

            Q_OBJECT

          public :
            DefaultAttributesProperty ( QString value = "" );
            DefaultAttributesProperty ( const DefaultAttributesProperty& );
            ~DefaultAttributesProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private :
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::DefaultAttributesProperty )

#endif // DEFAULTATTRIBUTESPROPERTY_H
