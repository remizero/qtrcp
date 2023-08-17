#ifndef HELPTOPICSACT_H
#define HELPTOPICSACT_H

// Librerías Internas
#include "actions_global.h"
#include "ActionAbs.h"

// Librerías Externas


// Librerías Qt
#include <QMainWindow>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace Components {

        namespace Actions {

          class ACTIONSSHARED_EXPORT HelpTopicsAct : public ActionAbs {

              Q_OBJECT

            public :
              Q_INVOKABLE HelpTopicsAct ( QString title, QWidget *parent );

            public slots :
              void execAct ();
          };
        }
      }
    }
  }
}

#endif // HELPTOPICSACT_H
