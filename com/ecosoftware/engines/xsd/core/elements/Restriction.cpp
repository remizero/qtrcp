#include "Restriction.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Restriction::Restriction () {}

Restriction::Restriction ( const Restriction & ) : ElementAbs () {}

Restriction::~Restriction () {}

int Restriction::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Restriction::staticMetaObject, "content", enumKey );
}

bool Restriction::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Restriction::staticMetaObject, "content", enumKey );
}

QString Restriction::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Restriction::content>::type> ( enumValue ) );
}

int Restriction::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Restriction::staticMetaObject, "properties", enumKey );
}

bool Restriction::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Restriction::staticMetaObject, "properties", enumKey );
}

QString Restriction::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Restriction::properties>::type> ( enumValue ) );
}
