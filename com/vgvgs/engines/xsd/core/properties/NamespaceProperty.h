#ifndef NAMESPACEPROPERTY_H
#define NAMESPACEPROPERTY_H

// Librerías Internas
// Internal Libraries
#include "xsd_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "core/PropertyAbs.h"

// Librerías Externas
// External Libraries
#include "Enumeration.h"

// Librerías Qt
// Qt Libraries
#include <QMetaEnum>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

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
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::NamespaceProperty )

#endif // NAMESPACEPROPERTY_H
