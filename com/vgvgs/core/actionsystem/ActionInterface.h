#ifndef ACTIONINTERFACE_H
#define ACTIONINTERFACE_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QWidget>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT ActionInterface {

        public slots :
          virtual void execAct () = 0;
      };
    }
  }
}

Q_DECLARE_INTERFACE ( NAMESPACE_LIBRARY_CORE::ActionInterface, "com.vgvgs.core.ActionInterface" )

#endif // ACTIONINTERFACE_H
