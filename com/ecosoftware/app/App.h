#ifndef APP_H
#define APP_H

// Librerías Internas
#include "app_global.h"

// Librerías Qt
#include <QApplication>

namespace Com {

  namespace Ecosoftware {

    namespace App {

      class APPSHARED_EXPORT App : public QApplication {

          Q_OBJECT

        public:
          App ( int &argc, char **argv );
          virtual ~App ();

          QCoreApplication *getApplication ();
          bool notify ( QObject* receiver, QEvent* event ) Q_DECL_OVERRIDE;

        private:
          QCoreApplication *application = nullptr;
      };
    }
  }
}

#endif // APP_H
