#ifndef MENU_H
#define MENU_H

// Librerías Internas
// Internal Libraries
#include "menubar_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías Qt
// Qt Libraries
#include <QMenu>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_COMPONENTS {

        namespace NAMESPACE_MENUBAR {

          class Menu : public QMenu {

              Q_OBJECT

            public :
              explicit Menu ( QWidget *parent = nullptr );

              void createStyle ();
          };
        }
      }
    }
  }
}

#endif // MENU_H
