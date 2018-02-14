#include "Selector.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Selector::Selector () {}

Selector::Selector ( const Selector & ) : ElementAbs () {}

Selector::~Selector () {}

int Selector::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Selector::staticMetaObject, "content", enumKey );
}

bool Selector::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Selector::staticMetaObject, "content", enumKey );
}

QString Selector::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Selector::content>::type> ( enumValue ) );
}

int Selector::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Selector::staticMetaObject, "properties", enumKey );
}

bool Selector::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Selector::staticMetaObject, "properties", enumKey );
}

QString Selector::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Selector::properties>::type> ( enumValue ) );
}
