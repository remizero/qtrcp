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

            public:
              explicit Menu ( QWidget *parent = 0 );

              void createStyle ();
          };
        }
      }
    }
  }
}

#endif // MENU_H
