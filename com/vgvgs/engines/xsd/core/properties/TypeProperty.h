#ifndef TYPEPROPERTY_H
#define TYPEPROPERTY_H

// Librerías Internas
#include "xsd_global.h"

// Librerías Externas
#include "macros_global.h"
#include "core/PropertyAbs.h"
#include "core/TypeAbs.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

        class XSDSHARED_EXPORT TypeProperty : public PropertyAbs {

            Q_OBJECT

          public :
            Q_INVOKABLE TypeProperty ( QString value = "" );
            Q_INVOKABLE TypeProperty ( const TypeProperty& );
            Q_INVOKABLE ~TypeProperty ();

            Q_INVOKABLE TypeAbs::types getValue () const;
            Q_INVOKABLE void setValue ( const QString value );
            Q_INVOKABLE void setValue ( TypeAbs::types value );
            Q_INVOKABLE int toInt ();
            Q_INVOKABLE QString toString ();

          private :
            TypeAbs::types value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Vgvgs::Engines::Xsd::TypeProperty )

#endif // TYPEPROPERTY_H
