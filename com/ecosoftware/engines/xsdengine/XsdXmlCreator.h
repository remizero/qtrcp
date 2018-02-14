#ifndef XSDXMLCREATOR_H
#define XSDXMLCREATOR_H

// Librerías Internas
#include "xsdengine_global.h"
#include "XsdEngine.h"

// Librerías Externas

// Librerías Qt
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace XsdEngine {

        class XSDENGINESHARED_EXPORT XsdXmlCreator : public QObject {

            Q_OBJECT

          public:
            XsdXmlCreator ();
        };
      }
    }
  }
}

#endif // XSDXMLCREATOR_H
