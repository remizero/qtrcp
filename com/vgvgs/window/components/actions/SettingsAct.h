#ifndef SETTINGSACT_H
#define SETTINGSACT_H

// Librerías Internas
// Internal Libraries
#include "actions_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "ActionAbs.h"

// Librerías Externas
// External Libraries
#include "XsdDialog.h"

// Librerías Qt
// Qt Libraries
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
              void execAct () override;
          };
        }
      }
    }
  }
}

#endif // SETTINGSACT_H
