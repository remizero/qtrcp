#ifndef ONLINEHELPACT_H
#define ONLINEHELPACT_H

// Librerías Internas
// Internal Libraries
#include "actions_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "ActionAbs.h"

// Librerías Externas
// External Libraries


// Librerías Qt
// Qt Libraries
#include <QDesktopServices>
#include <QUrl>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_COMPONENTS {

        namespace NAMESPACE_ACTIONS {

          class ACTIONSSHARED_EXPORT OnlineHelpAct : public ActionAbs {

              Q_OBJECT

            public :
              Q_INVOKABLE OnlineHelpAct ( QString title, QWidget *parent );

            public slots :
              void execAct () override;
          };
        }
      }
    }
  }
}

#endif // ONLINEHELPACT_H
