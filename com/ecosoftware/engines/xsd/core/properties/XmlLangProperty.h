#ifndef XMLLANGPROPERTY_H
#define XMLLANGPROPERTY_H

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

        class XSDSHARED_EXPORT XmlLangProperty : public PropertyAbs {

            Q_OBJECT

          public:
            XmlLangProperty ( bool value = false );
            XmlLangProperty ( const XmlLangProperty& );
            ~XmlLangProperty ();

            bool getValue () const;
            void setValue ( bool value );

          private:
            bool value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::XmlLangProperty )

#endif // XMLLANGPROPERTY_H
