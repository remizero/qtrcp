#ifndef STATUSBARSHOWHIDEACT_H
#define STATUSBARSHOWHIDEACT_H

// Librerías Internas
#include "actions_global.h"
#include "ActionAbs.h"

// Librerías Externas


// Librerías Qt
#include <QMainWindow>
#include <QStatusBar>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace Components {

        namespace Actions {

          class ACTIONSSHARED_EXPORT StatusBarShowHideAct : public ActionAbs {

              Q_OBJECT

            public:
              Q_INVOKABLE StatusBarShowHideAct ( QString title, QWidget *parent );

            public slots:
              void execAct ();
          };
        }
      }
    }
  }
}

#endif // STATUSBARSHOWHIDEACT_H
