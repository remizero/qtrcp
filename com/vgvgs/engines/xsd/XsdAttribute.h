#ifndef XSDATTRIBUTE_H
#define XSDATTRIBUTE_H

// Librerías Internas
#include "xsd_global.h"

// Librerías Externas
#include "macros_global.h"
#include "core/FacetAbs.h"

// Librerías Qt
#include <QList>
#include <QObject>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_ENGINES {

      namespace NAMESPACE_XSD {

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
