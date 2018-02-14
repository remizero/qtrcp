#include "Sequence.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Sequence::Sequence () {}

Sequence::Sequence ( const Sequence & ) : ElementAbs () {}

Sequence::~Sequence () {}

int Sequence::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Sequence::staticMetaObject, "content", enumKey );
}

bool Sequence::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Sequence::staticMetaObject, "content", enumKey );
}

QString Sequence::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Sequence::content>::type> ( enumValue ) );
}

int Sequence::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Sequence::staticMetaObject, "properties", enumKey );
}

bool Sequence::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Sequence::staticMetaObject, "properties", enumKey );
}

QString Sequence::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Sequence::properties>::type> ( enumValue ) );
}
