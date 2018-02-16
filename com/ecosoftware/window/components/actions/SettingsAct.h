#ifndef SETTINGSACT_H
#define SETTINGSACT_H

// Librerías Internas
#include "actions_global.h"
#include "ActionAbs.h"

// Librerías Externas
//#include "XsdFormCreator.h"
//#include "XsdFormEngine.h"
#include "XsdEngine.h"
#include "Element.h"

// Librerías Qt
#include <QMainWindow>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace Components {

        namespace Actions {

          class ACTIONSSHARED_EXPORT SettingsAct: public ActionAbs {

              Q_OBJECT

            public:
              Q_INVOKABLE SettingsAct ( QString title, QWidget *parent );

            public slots:
              void execAct ();
          };
        }
      }
    }
  }
}

#endif // SETTINGSACT_H
