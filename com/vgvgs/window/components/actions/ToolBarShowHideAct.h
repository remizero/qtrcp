#ifndef TOOLBARSHOWHIDEACT_H
#define TOOLBARSHOWHIDEACT_H

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
#include <QMainWindow>
#include <QToolBar>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_COMPONENTS {

        namespace NAMESPACE_ACTIONS {

          class ACTIONSSHARED_EXPORT ToolBarShowHideAct : public ActionAbs {

              Q_OBJECT

            public :
              Q_INVOKABLE ToolBarShowHideAct ( QString title, QWidget *parent );

            public slots :
              void execAct () override;
          };
        }
      }
    }
  }
}

#endif // TOOLBARSHOWHIDEACT_H
