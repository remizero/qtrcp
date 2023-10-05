#ifndef APP_H
#define APP_H

// Librerías Internas
// Internal Libraries
#include "app_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías Qt
// Qt Libraries
#include <QApplication>
#include <QDebug>
#include <QMessageLogger>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_APP {

      class APPSHARED_EXPORT App : public QApplication {

          Q_OBJECT

        public :
          App ( int &argc, char **argv );
          virtual ~App ();

          static int const EXIT_CODE_REBOOT = -123456789;

          QCoreApplication *getApplication ();
          bool notify ( QObject *receiver, QEvent *event ) Q_DECL_OVERRIDE;

        private :
          QCoreApplication *application = nullptr;
      };
    }
  }
}

#endif // APP_H
