#ifndef FINALPROPERTY_H
#define FINALPROPERTY_H

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

        class XSDSHARED_EXPORT FinalProperty : public PropertyAbs {

            Q_OBJECT
            // TODO: para complextype
            // final = (#all | List of (extension | restriction))
            // TODO: para element
            // final = (#all | List of (extension | restriction))
            // TODO: para schema
            // finalDefault = (#all | List of (extension | restriction | list | union))  : ''
            // TODO: para simpletype
            // final = (#all | List of (list | union | restriction | extension))

          public :
            FinalProperty ( QString value = "" );
            FinalProperty ( const FinalProperty& );
            ~FinalProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private :
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_XSD::FinalProperty )

#endif // FINALPROPERTY_H
