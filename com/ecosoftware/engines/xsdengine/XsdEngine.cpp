#include "XsdEngine.h"

using namespace Com::Ecosoftware::Engines::XsdEngine;

XsdEngine::XsdEngine () {}

int XsdEngine::indexOf ( QString type, QString enumName ) {

  // TODO: Este método indexOf debe ir en una clase utils que sea accesible a
  // todas las demás clases y librerías.
  const QMetaObject metaObject = this->staticMetaObject;
  int index = metaObject.indexOfEnumerator ( enumName.toUtf8 () );
  const QMetaEnum metaEnum = metaObject.enumerator ( index );
  int i = metaEnum.keyToValue ( type.toUpper ().toLatin1 () );
  return i;
}

int XsdEngine::indexOfXsdTypeEnum ( QString type ) {

  return this->indexOf ( type, "xsdTypeEnum" );
}

QString XsdEngine::xsdTypeEnumToString ( xsdLevelEnum enumType ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < XsdEngine::xsdLevelEnum > ();
  return metaEnum.valueToKey ( enumType );
}
