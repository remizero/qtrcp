#ifndef RESTARTACT_H
#define RESTARTACT_H

// Librerías Internas
#include "actions_global.h"

// Librerías Externas
#include "macros_global.h"
#include "ActionAbs.h"

// Librerías Externas
//#include "MainWindow.h"

// Librerías Qt
#include <QMainWindow>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_COMPONENTS {

        namespace NAMESPACE_ACTIONS {

          class ACTIONSSHARED_EXPORT RestartAct : public ActionAbs {

              Q_OBJECT

            public :
              Q_INVOKABLE RestartAct ( QString title, QWidget *parent );

            public slots :
              void execAct ();
          };
        }
      }
    }
  }
}

#endif // RESTARTACT_H
