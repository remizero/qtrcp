#ifndef STATUSBAR_H
#define STATUSBAR_H

// Librerías internas
#include "statusbar_global.h"

// Librerías Externas
#include "macros_global.h"

// Librerías Qt
#include <QStatusBar>
#include <QLabel>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_COMPONENTS {

        namespace NAMESPACE_STATUSBAR {

          class STATUSBARSHARED_EXPORT StatusBar : public QStatusBar {

            public :
              explicit StatusBar ( QWidget *parent = nullptr );
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
