#ifndef BLOCKDEFAULTPROPERTY_H
#define BLOCKDEFAULTPROPERTY_H

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

        class XSDSHARED_EXPORT BlockDefaultProperty : public PropertyAbs {

            Q_OBJECT
            // TODO: blockDefault = (#all | List of (extension | restriction | substitution))  : ''
            // Como manejar este tipo de valor.

          public :
            BlockDefaultProperty ( QString value = "" );
            BlockDefaultProperty ( const BlockDefaultProperty& );
            ~BlockDefaultProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private :
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::BlockDefaultProperty )

#endif // BLOCKDEFAULTPROPERTY_H
