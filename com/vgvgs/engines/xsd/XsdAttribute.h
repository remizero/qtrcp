#ifndef XSDATTRIBUTE_H
#define XSDATTRIBUTE_H

// Librerías Internas
// Internal Libraries
#include "xsd_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "core/FacetAbs.h"

// Librerías Qt
// Qt Libraries
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
