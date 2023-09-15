#ifndef FINALPROPERTY_H
#define FINALPROPERTY_H

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
Q_DECLARE_METATYPE ( Com::Vgvgs::Engines::Xsd::FinalProperty )

#endif // FINALPROPERTY_H
