#ifndef NAMESPACEPROPERTY_H
#define NAMESPACEPROPERTY_H

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

        class XSDSHARED_EXPORT NamespaceProperty : public PropertyAbs {

            Q_OBJECT
            // TODO: para any
            // namespace = ((##any | ##other) | List of (anyURI | (##targetNamespace | ##local)) )
            // TODO: para anyattribute
            // namespace = ((##any | ##other) | List of (anyURI | (##targetNamespace | ##local)) )
            // TODO: para import
            // namespace = anyURI

          public :
            NamespaceProperty ( QString value = "" );
            NamespaceProperty ( const NamespaceProperty& );
            ~NamespaceProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private :
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::NamespaceProperty )

#endif // NAMESPACEPROPERTY_H
