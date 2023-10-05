#ifndef MENUBAR_H
#define MENUBAR_H

// Librerías Internas
// Internal Libraries
#include "menubar_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías Externas
// External Libraries
#include "ExitAct.h"
#include "FullScreenAct.h"
#include "HelpTopicsAct.h"
#include "OnlineHelpAct.h"
#include "RestartAct.h"
#include "SettingsAct.h"
#include "StatusBarShowHideAct.h"
#include "ToolBarShowHideAct.h"

// Librerías Qt
// Qt Libraries
#include <QMenuBar>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_COMPONENTS {

        namespace NAMESPACE_MENUBAR {

          class MENUBARSHARED_EXPORT MenuBar : public QMenuBar {

              Q_OBJECT

            public :
              explicit MenuBar ( QWidget *parent = nullptr  );
              ~MenuBar ();
          };
        }
      }
    }
  }
}

#endif // MENUBAR_H
