#include "Exception.h"

using namespace NAMESPACE_LIBRARY_CORE;

Exception::Exception ( const QString &text, const QString &file, int line, const QString &function) noexcept :
  message ( text ),
  file ( file ),
  line ( line ),
  function ( function )
{}

Exception::Exception ( const Exception &exception ) {

  this->message = exception.message;
}

Exception::~Exception () {}

Exception *Exception::clone () const {

  return new Exception ( *this );
}

QString Exception::getFile () const {

  return this->file;
}

int Exception::getLine () const {

  return this->line;
}

QString Exception::getFunction () const {

  return this->function;
}

void Exception::raise () const {

  throw *this;
}

const char *Exception::what () const noexcept {

  return this->message.toUtf8 ().constData ();
}
