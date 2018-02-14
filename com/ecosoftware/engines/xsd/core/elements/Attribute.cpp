#include "Attribute.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Attribute::Attribute () {}

Attribute::Attribute ( const Attribute & ) : ElementAbs () {}

Attribute::~Attribute () {}

int Attribute::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Attribute::staticMetaObject, "content", enumKey );
}

bool Attribute::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Attribute::staticMetaObject, "content", enumKey );
}

QString Attribute::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Attribute::content>::type> ( enumValue ) );
}

int Attribute::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Attribute::staticMetaObject, "properties", enumKey );
}

bool Attribute::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Attribute::staticMetaObject, "properties", enumKey );
}

QString Attribute::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Attribute::properties>::type> ( enumValue ) );
}
