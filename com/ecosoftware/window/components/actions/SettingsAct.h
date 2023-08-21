#ifndef SETTINGSACT_H
#define SETTINGSACT_H

// Librerías Internas
#include "actions_global.h"

// Librerías Externas
#include "macros_global.h"
#include "ActionAbs.h"

// Librerías Externas
#include "XsdDialog.h"

// Librerías Qt
#include <QMainWindow>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_COMPONENTS {

        namespace NAMESPACE_ACTIONS {

          class ACTIONSSHARED_EXPORT SettingsAct: public ActionAbs {

              Q_OBJECT

            public :
              Q_INVOKABLE SettingsAct ( QString title, QWidget *parent );

            public slots :
              void execAct ();
          };
        }
      }
    }
  }
}

#endif // SETTINGSACT_H
