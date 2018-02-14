#include "AttributeGroup.h"

using namespace Com::Ecosoftware::Engines::Xsd;

AttributeGroup::AttributeGroup () {}

AttributeGroup::AttributeGroup ( const AttributeGroup & ) : ElementAbs () {}

AttributeGroup::~AttributeGroup () {}

int AttributeGroup::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( AttributeGroup::staticMetaObject, "content", enumKey );
}

bool AttributeGroup::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( AttributeGroup::staticMetaObject, "content", enumKey );
}

QString AttributeGroup::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<AttributeGroup::content>::type> ( enumValue ) );
}

int AttributeGroup::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( AttributeGroup::staticMetaObject, "properties", enumKey );
}

bool AttributeGroup::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( AttributeGroup::staticMetaObject, "properties", enumKey );
}

QString AttributeGroup::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<AttributeGroup::properties>::type> ( enumValue ) );
}
