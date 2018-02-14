#include "Key.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Key::Key () {}

Key::Key ( const Key & ) : ElementAbs () {}

Key::~Key () {}

int Key::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Key::staticMetaObject, "content", enumKey );
}

bool Key::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Key::staticMetaObject, "content", enumKey );
}

QString Key::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Key::content>::type> ( enumValue ) );
}

int Key::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Key::staticMetaObject, "properties", enumKey );
}

bool Key::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Key::staticMetaObject, "properties", enumKey );
}

QString Key::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Key::properties>::type> ( enumValue ) );
}
