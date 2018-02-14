#include "Keyref.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Keyref::Keyref () {}

Keyref::Keyref ( const Keyref & ) : ElementAbs () {}

Keyref::~Keyref () {}

int Keyref::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Keyref::staticMetaObject, "content", enumKey );
}

bool Keyref::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Keyref::staticMetaObject, "content", enumKey );
}

QString Keyref::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Keyref::content>::type> ( enumValue ) );
}

int Keyref::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Keyref::staticMetaObject, "properties", enumKey );
}

bool Keyref::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Keyref::staticMetaObject, "properties", enumKey );
}

QString Keyref::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Keyref::properties>::type> ( enumValue ) );
}
