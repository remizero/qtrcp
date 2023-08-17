#ifndef RESTARTACT_H
#define RESTARTACT_H

// Librerías Internas
#include "actions_global.h"
#include "ActionAbs.h"

// Librerías Externas
//#include "MainWindow.h"

// Librerías Qt
#include <QMainWindow>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace Components {

        namespace Actions {

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
