#ifndef STATUSBAR_H
#define STATUSBAR_H

// Librerías internas
#include "statusbar_global.h"

// Librerías Qt
#include <QStatusBar>
#include <QLabel>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace Components {

        namespace Statusbar {

          class STATUSBARSHARED_EXPORT StatusBar : public QStatusBar {

            public:
              explicit StatusBar ( QWidget *parent = 0 );
              ~StatusBar ();

              void addNewSection ();
              void hideSection ();
              void showSection ();

          };
        }
      }
    }
  }
}

#endif // STATUSBAR_H
