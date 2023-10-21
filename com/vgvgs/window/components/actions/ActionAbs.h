#ifndef ACTIONABS_H
#define ACTIONABS_H

// Librerías Internas
// Internal Libraries
#include "actions_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "actionmanager/ActionInterface.h"

// Librerías Qt
// Qt Libraries
#include <QAction>
#include <QDebug>
#include <QIcon>
#include <QKeySequence>
#include <QMetaType>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_COMPONENTS {

        namespace NAMESPACE_ACTIONS {

          class ACTIONSSHARED_EXPORT ActionAbs : public QAction, public NAMESPACE_LIBRARY_CORE::ActionInterface {

              Q_OBJECT
              Q_INTERFACES ( NAMESPACE_LIBRARY_CORE::ActionInterface )

            public :
              explicit ActionAbs ( QString title, QWidget *parent = nullptr );

            public slots :
              virtual void execAct () override = 0;

            protected :
              QWidget *myParent;
          };
        }
      }
    }
  }
}

Q_DECLARE_METATYPE ( NAMESPACE_LIBRARY_ACTONS::ActionAbs * )

#endif // ACTIONABS_H
