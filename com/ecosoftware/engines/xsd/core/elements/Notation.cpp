#include "Notation.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Notation::Notation () {}

Notation::Notation ( const Notation & ) : ElementAbs () {}

Notation::~Notation () {}

int Notation::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Notation::staticMetaObject, "content", enumKey );
}

bool Notation::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Notation::staticMetaObject, "content", enumKey );
}

QString Notation::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Notation::content>::type> ( enumValue ) );
}

int Notation::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Notation::staticMetaObject, "properties", enumKey );
}

bool Notation::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Notation::staticMetaObject, "properties", enumKey );
}

QString Notation::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Notation::properties>::type> ( enumValue ) );
}
