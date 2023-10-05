#ifndef CONSOLE_H
#define CONSOLE_H

// Librerías Internas
// Internal Libraries
#include "console_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías Qt
// Qt Libraries
#include <QObject>
#include <QProcess>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CONSOLE {

      class CONSOLESHARED_EXPORT Console : public QObject {

          Q_OBJECT

        public :
          static Console *getInstance ( QObject *parent = nullptr );
          void execute ( QString command, QStringList arguments );
          QString getOutputShell () const;
          QString getOutputShellError () const;

        private slots:
          void catchError ();
          void catchOutput ();

        private :
          explicit Console ( QObject *parent = nullptr );
          ~Console ();
          void clear ();
          static Console *instance;
                QProcess *exec;
                 QString outputShell;
                 QString outputShellError;
      };
    }
  }
}

#endif // CONSOLE_H
