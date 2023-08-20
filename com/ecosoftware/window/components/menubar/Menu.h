#ifndef MENU_H
#define MENU_H

#include <QMenu>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace Components {

        namespace Menubar {

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
