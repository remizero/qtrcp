#ifndef NAMESPACEPROPERTY_H
#define NAMESPACEPROPERTY_H

// Librerías Internas
#include "xsd_global.h"

// Librerías Externas
#include "macros_global.h"
#include "core/PropertyAbs.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
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
Q_DECLARE_METATYPE ( Com::Vgvgs::Engines::Xsd::NamespaceProperty )

#endif // NAMESPACEPROPERTY_H
