#ifndef SINGLEINSTANCE_H
#define SINGLEINSTANCE_H

// Librerías Internas
// Internal Libraries
#include "singleinstance_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías Qt
// Qt Libraries
#include <QObject>
#include <QSharedMemory>
#include <QSystemSemaphore>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_SINGLEINSTANCE {

      class SINGLEINSTANCESHARED_EXPORT SingleInstance {

        public :
          SingleInstance ( const QString &key );
          ~SingleInstance ();

          bool isAnotherRunning ();
          bool tryToRun ();
          void release ();

        private :
          const QString key;
          const QString memLockKey;
          const QString sharedmemKey;
          QSharedMemory sharedMem;
          QSystemSemaphore memLock;

          Q_DISABLE_COPY( SingleInstance )
      };
    }
  }
}

#endif // SINGLEINSTANCE_H
