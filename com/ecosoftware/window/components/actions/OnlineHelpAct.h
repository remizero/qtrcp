#ifndef ONLINEHELPACT_H
#define ONLINEHELPACT_H

// Librerías Internas
#include "actions_global.h"
#include "ActionAbs.h"

// Librerías Externas


// Librerías Qt
#include <QDesktopServices>
#include <QUrl>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace Components {

        namespace Actions {

          class ACTIONSSHARED_EXPORT OnlineHelpAct : public ActionAbs {

              Q_OBJECT

            public:
              Q_INVOKABLE OnlineHelpAct ( QString title, QWidget *parent );

            public slots:
              void execAct ();
          };
        }
      }
    }
  }
}

#endif // ONLINEHELPACT_H
