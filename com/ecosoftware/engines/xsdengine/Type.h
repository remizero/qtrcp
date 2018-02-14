#ifndef TYPE_H
#define TYPE_H

// Librerías Internas
#include "xsdengine_global.h"

// Librerías Qt
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace XsdEngine {

        class XSDENGINESHARED_EXPORT Type : public QObject {

            Q_OBJECT

          public:
            Type ();

          private:
            QString name;
        };
      }
    }
  }
}

#endif // TYPE_H
