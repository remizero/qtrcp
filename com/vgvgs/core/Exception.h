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
          QString message;
          QString file;
          int line;
          QString function;
          Exception ( QString const &text, const QString &file, int line, const QString &function ) noexcept : message ( text ), file ( file ), line ( line ), function ( function ) {}
          Exception ( const Exception &re ) { this->message = re.message; }
          ~Exception () override {}

          void raise () const override { throw *this; }
          Exception *clone () const override { return new Exception ( *this ); }
          // const char *what () const noexcept override { return this->message.toStdString ().c_str (); }
          const char *what () const noexcept override { return this->message.toUtf8().constData(); }

        private :
      };
    }
  }
}

#endif // EXCEPTION_H
