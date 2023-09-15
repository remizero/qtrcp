#ifndef FINALDEFAULTPROPERTY_H
#define FINALDEFAULTPROPERTY_H

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
Q_DECLARE_METATYPE ( Com::Vgvgs::Engines::Xsd::FinalDefaultProperty )

#endif // FINALDEFAULTPROPERTY_H
