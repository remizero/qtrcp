#ifndef EXCEPTION_H
#define EXCEPTION_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QException>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT Exception : public QException {

        public :
          Exception ( QString const &text, const QString &file, int line, const QString &function ) noexcept;
          Exception ( const Exception &exception );
          ~Exception () override;

          Exception *clone () const override;
          QString getFile () const;
          int getLine () const;
          QString getFunction () const;
          void raise () const override;
          const char *what () const noexcept override;

        private :
          QString message;
          QString file;
          int line;
          QString function;
      };
    }
  }
}

#endif // EXCEPTION_H
