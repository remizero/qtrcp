#ifndef BLOCKDEFAULTPROPERTY_H
#define BLOCKDEFAULTPROPERTY_H

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

        class XSDSHARED_EXPORT BlockDefaultProperty : public PropertyAbs {

            Q_OBJECT
            // TODO: blockDefault = (#all | List of (extension | restriction | substitution))  : ''
            // Como manejar este tipo de valor.

          public:
            BlockDefaultProperty ( QString value = "" );
            BlockDefaultProperty ( const BlockDefaultProperty& );
            ~BlockDefaultProperty ();

            QString getValue () const;
            void setValue ( const QString &value );

          private:
            QString value;
        };
      }
    }
  }
}
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::BlockDefaultProperty )

#endif // BLOCKDEFAULTPROPERTY_H
