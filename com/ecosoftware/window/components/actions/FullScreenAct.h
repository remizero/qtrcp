#ifndef FULLSCREENACT_H
#define FULLSCREENACT_H

// Librerías Internas
#include "actions_global.h"
#include "ActionAbs.h"

// Librerías Externas


// Librerías Qt
#include <QMainWindow>
#include <QToolBar>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace Components {

        namespace Actions {

          class ACTIONSSHARED_EXPORT FullScreenAct : public ActionAbs {

              Q_OBJECT

            public:
              Q_INVOKABLE FullScreenAct ( QString title, QWidget *parent );

            public slots:
              void execAct ();
          };
        }
      }
    }
  }
}

#endif // FULLSCREENACT_H
