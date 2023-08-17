#ifndef BLOCKPROPERTY_H
#define BLOCKPROPERTY_H

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
Q_DECLARE_METATYPE ( Com::Ecosoftware::Engines::Xsd::BlockProperty )

#endif // BLOCKPROPERTY_H
