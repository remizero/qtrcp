#include "Group.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Group::Group () {}

Group::Group ( const Group & ) : ElementAbs () {}

Group::~Group () {}

int Group::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Group::staticMetaObject, "content", enumKey );
}

bool Group::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Group::staticMetaObject, "content", enumKey );
}

QString Group::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Group::content>::type> ( enumValue ) );
}

int Group::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Group::staticMetaObject, "properties", enumKey );
}

bool Group::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Group::staticMetaObject, "properties", enumKey );
}

QString Group::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Group::properties>::type> ( enumValue ) );
}
