#ifndef FINALDEFAULTPROPERTY_H
#define FINALDEFAULTPROPERTY_H

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

        class XSDSHARED_EXPORT FinalDefaultProperty : public PropertyAbs {

            Q_OBJECT
            // TODO: finalDefault = (#all | List of (extension | restriction | list | union))  : ''

          public :
            FinalDefaultProperty ( QString value = "" );
            FinalDefaultProperty ( const FinalDefaultProperty& );
            ~FinalDefaultProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private :
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::FinalDefaultProperty )

#endif // FINALDEFAULTPROPERTY_H
