#ifndef CONSOLE_H
#define CONSOLE_H

// Librerías internas
#include "console_global.h"

// Librerías Qt
#include <QObject>
#include <QProcess>

namespace Com {

  namespace Ecosoftware {

    namespace Console {

      class CONSOLESHARED_EXPORT Console : public QObject {

          Q_OBJECT

        public:
          static Console *getInstance ( QObject *parent = 0 );
          void execute ( QString command, QStringList arguments );
          QString getOutputShell () const;
          QString getOutputShellError () const;

        private slots:
          void catchError ();
          void catchOutput ();

        private:
          explicit Console ( QObject *parent = 0 );
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
