#include "SimpleContent.h"

using namespace Com::Ecosoftware::Engines::Xsd;

SimpleContent::SimpleContent () {}

SimpleContent::SimpleContent ( const SimpleContent & ) : ElementAbs () {}

SimpleContent::~SimpleContent () {}

int SimpleContent::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( SimpleContent::staticMetaObject, "content", enumKey );
}

bool SimpleContent::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( SimpleContent::staticMetaObject, "content", enumKey );
}

QString SimpleContent::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<SimpleContent::content>::type> ( enumValue ) );
}

int SimpleContent::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( SimpleContent::staticMetaObject, "properties", enumKey );
}

bool SimpleContent::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( SimpleContent::staticMetaObject, "properties", enumKey );
}

QString SimpleContent::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<SimpleContent::properties>::type> ( enumValue ) );
}
