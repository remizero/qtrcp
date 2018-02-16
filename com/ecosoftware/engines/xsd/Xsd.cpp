#include "Xsd.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Xsd::Xsd () {}

int Xsd::indexOfLevelEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Xsd::staticMetaObject, "levelEnum", enumKey );
}

bool Xsd::inLevelEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Xsd::staticMetaObject, "levelEnum", enumKey );
}

QString Xsd::levelEnumToString ( Xsd::levelEnum enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < Xsd::levelEnum > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Xsd::levelEnum>::type> ( enumValue ) );
}
