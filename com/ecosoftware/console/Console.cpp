#include "Console.h"

using namespace Com::Ecosoftware::Console;

Console *Console::instance = nullptr;

Console::Console ( QObject *parent ) : QObject ( parent ) {

  this->exec = new QProcess ( this );
  connect ( this->exec, SIGNAL ( readyReadStandardOutput () ), this, SLOT ( catchOutput () ) );
  connect ( this->exec, SIGNAL ( readyReadStandardError () ), this, SLOT ( catchError () ) );
}

Console::~Console () {}

Console *Console::getInstance ( QObject *parent ) {

  if ( Console::instance == nullptr ) {

    Console::instance = new Console ( parent );
  }
  return Console::instance;
}

void Console::execute ( QString command, QStringList arguments ) {

  this->clear ();
  this->exec->start ( command, arguments );
  this->exec->waitForFinished ();
}

void Console::catchError () {

  this->outputShellError.append ( this->exec->readAllStandardError () );
}

void Console::catchOutput () {

  this->outputShell.append ( this->exec->readAllStandardOutput () );
}

void Console::clear () {

  this->outputShell.clear ();
  this->outputShellError.clear ();
}

QString Console::getOutputShell () const {

  return this->outputShell;
}

QString Console::getOutputShellError () const {

  return this->outputShellError;
}
