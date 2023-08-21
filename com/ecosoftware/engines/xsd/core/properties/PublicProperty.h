#ifndef PUBLICPROPERTY_H
#define PUBLICPROPERTY_H

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

        class XSDSHARED_EXPORT PublicProperty : public PropertyAbs {

            Q_OBJECT

          public :
            PublicProperty ( QString value = "" );
            PublicProperty ( const PublicProperty& );
            ~PublicProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private :
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Vgvgs::Engines::Xsd::PublicProperty )

#endif // PUBLICPROPERTY_H
