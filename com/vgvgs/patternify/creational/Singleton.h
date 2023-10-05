#ifndef SINGLETON_H
#define SINGLETON_H

// Librerías Internas
// Internal Libraries
#include "patternify_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>

// Librerías C++
// C++ Libraries
#include <iostream>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_PATTERNIFY {

      template <typename T>
      class PATTERNIFY_EXPORT Singleton {

          Q_DISABLE_COPY ( Singleton )

        public :
          virtual ~Singleton () {

            if ( instance != nullptr ) {

              delete instance;
              instance = nullptr;
            }
          }
          static T *getInstance () {

            QMutexLocker lock ( mutex );
            if ( instance == nullptr ) {

              instance = new T ();
            }
            return instance;
          }

        protected :
          static QMutex *mutex;
          Singleton () {}

        private :
          static T *instance;
      };
      template <typename T>
      QMutex *Singleton<T>::mutex;
      template <typename T>
      T *Singleton<T>::instance = nullptr;
    }
  }
}

#endif // SINGLETON_H
