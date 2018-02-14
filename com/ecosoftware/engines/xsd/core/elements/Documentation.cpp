#include "Documentation.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Documentation::Documentation () {}

Documentation::Documentation ( const Documentation & ) : ElementAbs () {}

Documentation::~Documentation () {}

int Documentation::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Documentation::staticMetaObject, "content", enumKey );
}

bool Documentation::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Documentation::staticMetaObject, "content", enumKey );
}

QString Documentation::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Documentation::content>::type> ( enumValue ) );
}

int Documentation::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Documentation::staticMetaObject, "properties", enumKey );
}

bool Documentation::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Documentation::staticMetaObject, "properties", enumKey );
}

QString Documentation::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Documentation::properties>::type> ( enumValue ) );
}
