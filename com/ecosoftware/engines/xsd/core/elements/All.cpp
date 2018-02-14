#include "All.h"

using namespace Com::Ecosoftware::Engines::Xsd;

All::All () {}

All::All ( const All & ) : ElementAbs () {}

All::~All () {}

int All::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( All::staticMetaObject, "content", enumKey );
}

bool All::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( All::staticMetaObject, "content", enumKey );
}

QString All::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<All::content>::type> ( enumValue ) );
}

int All::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( All::staticMetaObject, "properties", enumKey );
}

bool All::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( All::staticMetaObject, "properties", enumKey );
}

QString All::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<All::properties>::type> ( enumValue ) );
}
