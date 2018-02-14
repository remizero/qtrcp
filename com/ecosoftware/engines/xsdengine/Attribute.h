#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

// Librerías Internas
#include "xsdengine_global.h"

// Librerías Qt
#include <QObject>

namespace Com {

  namespace Ecosoftware {

    namespace Engines {

      namespace XsdEngine {

        class XSDENGINESHARED_EXPORT Attribute : public QObject {

            Q_OBJECT

          public:
            Attribute ();

          private:
            QString name;
        };
      }
    }
  }
}

#endif // ATTRIBUTE_H
