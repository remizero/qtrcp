#include "SimpleType.h"

using namespace Com::Ecosoftware::Engines::Xsd;

SimpleType::SimpleType () {}

SimpleType::SimpleType ( const SimpleType & ) : ElementAbs () {}

SimpleType::~SimpleType () {}

int SimpleType::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( SimpleType::staticMetaObject, "content", enumKey );
}

bool SimpleType::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( SimpleType::staticMetaObject, "content", enumKey );
}

QString SimpleType::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<SimpleType::content>::type> ( enumValue ) );
}

int SimpleType::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( SimpleType::staticMetaObject, "properties", enumKey );
}

bool SimpleType::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( SimpleType::staticMetaObject, "properties", enumKey );
}

QString SimpleType::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<SimpleType::properties>::type> ( enumValue ) );
}
