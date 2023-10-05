#ifndef BLOCKPROPERTY_H
#define BLOCKPROPERTY_H

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

        class XSDSHARED_EXPORT BlockProperty : public PropertyAbs {

            Q_OBJECT
            // TODO: Para Element
            // block = (#all | List of (extension | restriction | substitution))
            // TODO: Para ComplexType
            // block = (#all | List of (extension | restriction))

          public :
            BlockProperty ( QString value = "" );
            BlockProperty ( const BlockProperty& );
            ~BlockProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private :
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::BlockProperty )

#endif // BLOCKPROPERTY_H
