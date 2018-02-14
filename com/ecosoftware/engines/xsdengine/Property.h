#ifndef PROPERTY_H
#define PROPERTY_H

// Librerías Internas
#include "xsdengine_global.h"

// Librerías Qt
#include <QList>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace XsdEngine {

        class XSDENGINESHARED_EXPORT Property : public QObject {

            Q_OBJECT

          public:
            Property ();

            QString getName () const;
            QString getValue () const;
            void setName ( const QString &value );
            void setValue ( const QString &value );

          private:
            QString name;
            QString value;
        };
      }
    }
  }
}

#endif // PROPERTY_H
