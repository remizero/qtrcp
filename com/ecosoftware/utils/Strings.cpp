#include "Strings.h"

using namespace Com::Ecosoftware::Utils;

QString Strings::capitalize ( QString string ) {

  return string.replace ( 0, 1, string [ 0 ].toUpper () );
}

QString Strings::normalizeClassName ( QString string ) {

  int pos = string.indexOf ( ":" );
  return string.remove ( 0, pos + 1 );
}
