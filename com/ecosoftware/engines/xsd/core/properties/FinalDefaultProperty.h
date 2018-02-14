#ifndef FINALDEFAULTPROPERTY_H
#define FINALDEFAULTPROPERTY_H

// Librerías Internas
#include "xsd_global.h"
#include "core/PropertyAbs.h"

// Librerías Externas
#include "Enumeration.h"

// Librerías Qt
#include <QMetaEnum>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT FinalDefaultProperty : public PropertyAbs {

            Q_OBJECT
            // TODO: finalDefault = (#all | List of (extension | restriction | list | union))  : ''

          public:
            FinalDefaultProperty ( QString value = "" );
            FinalDefaultProperty ( const FinalDefaultProperty& );
            ~FinalDefaultProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private:
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::FinalDefaultProperty )

#endif // FINALDEFAULTPROPERTY_H
