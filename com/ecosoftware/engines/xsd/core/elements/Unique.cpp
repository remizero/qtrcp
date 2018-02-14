#include "Unique.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Unique::Unique () {}

Unique::Unique ( const Unique & ) : ElementAbs () {}

Unique::~Unique () {}

int Unique::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Unique::staticMetaObject, "content", enumKey );
}

bool Unique::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Unique::staticMetaObject, "content", enumKey );
}

QString Unique::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Unique::content>::type> ( enumValue ) );
}

int Unique::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Unique::staticMetaObject, "properties", enumKey );
}

bool Unique::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Unique::staticMetaObject, "properties", enumKey );
}

QString Unique::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Unique::properties>::type> ( enumValue ) );
}
