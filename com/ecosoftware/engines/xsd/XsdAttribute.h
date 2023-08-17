#ifndef XSDATTRIBUTE_H
#define XSDATTRIBUTE_H

// Librerías Internas
#include "xsd_global.h"
#include "core/FacetAbs.h"

// Librerías Qt
#include <QList>
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace Xsd {

        class XSDSHARED_EXPORT XsdAttribute : public QObject {

            Q_OBJECT

          public :
            XsdAttribute ();

          private :
            QString name;
            QList<FacetAbs *> facetsList;
        };
      }
    }
  }
}

#endif // XSDATTRIBUTE_H
