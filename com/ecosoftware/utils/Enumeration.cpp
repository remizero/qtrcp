#include "Enumeration.h"
#include <QDebug>

using namespace Com::Ecosoftware::Utils;

const QMetaEnum Enumeration::getMetaEnum ( const QMetaObject staticMetaObject, QString enumerate ) {

  int index = staticMetaObject.indexOfEnumerator ( enumerate.toUtf8 ().data () );
  return staticMetaObject.enumerator ( index );
}

int Enumeration::indexOf ( const QMetaObject staticMetaObject, QString enumerate, QString enumKey ) {

  #ifdef Q_OS_WIN
    const QMetaEnum metaEnum = Enumeration::getMetaEnum ( staticMetaObject, enumerate );
  #endif
  #ifdef Q_OS_LINUX
    int index = staticMetaObject.indexOfEnumerator ( enumerate.toUtf8 ().data () );
    const QMetaEnum metaEnum = staticMetaObject.enumerator ( index );
  #endif
  return metaEnum.keyToValue ( Enumeration::normalizeEnumValue ( enumKey ).toUtf8 ().data () );
}

bool Enumeration::inEnum ( const QMetaObject staticMetaObject, QString enumerate, QString enumKey ) {

  #ifdef Q_OS_WIN
    return ( Enumeration::indexOf ( staticMetaObject, enumerate, enumKey ) != -1 );
  #endif
  #ifdef Q_OS_LINUX
    int index = staticMetaObject.indexOfEnumerator ( enumerate.toUtf8 ().data () );
    const QMetaEnum metaEnum = staticMetaObject.enumerator ( index );
    return ( metaEnum.keyToValue ( Enumeration::normalizeEnumValue ( enumKey ).toUtf8 ().data () ) != -1 );
  #endif
}

bool Enumeration::inEnum  ( const QMetaObject staticMetaObject, QString enumerate, int enumValue ) {

  #ifdef Q_OS_WIN
    const QMetaEnum metaEnum = Enumeration::getMetaEnum ( staticMetaObject, enumerate );
  #endif
  #ifdef Q_OS_LINUX
    int index = staticMetaObject.indexOfEnumerator ( enumerate.toUtf8 ().data () );
    const QMetaEnum metaEnum = staticMetaObject.enumerator ( index );
  #endif
  return ( metaEnum.value ( enumValue ) != -1 );
}

QString Enumeration::normalizeEnumValue ( QString enumKey ) {

  int pos = enumKey.indexOf ( ":" );
  return enumKey.remove ( 0, pos + 1 ).toUpper ();
}
