#include "Any.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Any::Any () {}

Any::Any ( const Any & ) : ElementAbs () {}

Any::~Any () {}

int Any::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Any::staticMetaObject, "content", enumKey );
}

bool Any::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Any::staticMetaObject, "content", enumKey );
}

QString Any::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Any::content>::type> ( enumValue ) );
}

int Any::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Any::staticMetaObject, "properties", enumKey );
}

bool Any::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Any::staticMetaObject, "properties", enumKey );
}

QString Any::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Any::properties>::type> ( enumValue ) );
}
