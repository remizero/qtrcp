#ifndef FACET_H
#define FACET_H

// Librerías Internas
#include "xsdengine_global.h"

// Librerías Qt
#include <QList>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace XsdEngine {

        class XSDENGINESHARED_EXPORT Facet : public QObject {

            Q_OBJECT

          public:
            Facet ();

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

#endif // FACET_H
