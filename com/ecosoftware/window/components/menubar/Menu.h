#ifndef MENU_H
#define MENU_H

// Librerías Internas
#include "menubar_global.h"

// Librerías Externas
#include "macros_global.h"

// Librerías Qt
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
