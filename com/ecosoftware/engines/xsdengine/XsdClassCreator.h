#ifndef XSDCLASSCREATOR_H
#define XSDCLASSCREATOR_H

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

        class XSDENGINESHARED_EXPORT XsdClassCreator : public QObject {

            Q_OBJECT

          public:
            XsdClassCreator ();
        };
      }
    }
  }
}

#endif // XSDCLASSCREATOR_H
