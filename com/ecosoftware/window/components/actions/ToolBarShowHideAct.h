#ifndef TOOLBARSHOWHIDEACT_H
#define TOOLBARSHOWHIDEACT_H

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

          class ACTIONSSHARED_EXPORT ToolBarShowHideAct : public ActionAbs {

              Q_OBJECT

            public :
              Q_INVOKABLE ToolBarShowHideAct ( QString title, QWidget *parent );

            public slots :
              void execAct ();
          };
        }
      }
    }
  }
}

#endif // TOOLBARSHOWHIDEACT_H
