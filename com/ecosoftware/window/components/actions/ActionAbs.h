#ifndef ACTIONABS_H
#define ACTIONABS_H

// Librerías Internas
#include "actions_global.h"

// Librerías Qt
#include <QAction>
#include <QDebug>
#include <QIcon>
#include <QKeySequence>
#include <QMetaType>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace Components {

        namespace Actions {

          class ACTIONSSHARED_EXPORT ActionAbs : public QAction {

              Q_OBJECT

            public:
              explicit ActionAbs ( QString title, QWidget *parent = 0 );

            public slots:
              virtual void execAct () = 0;

            protected:
              QWidget *myParent;
          };
        }
      }
    }
  }
}

Q_DECLARE_METATYPE ( Com::Ecosoftware::Window::Components::Actions::ActionAbs * )

#endif // ACTIONABS_H
