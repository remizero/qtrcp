#include "Import.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Import::Import () {}

Import::Import ( const Import & ) : ElementAbs () {}

Import::~Import () {}

int Import::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Import::staticMetaObject, "content", enumKey );
}

bool Import::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Import::staticMetaObject, "content", enumKey );
}

QString Import::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Import::content>::type> ( enumValue ) );
}

int Import::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Import::staticMetaObject, "properties", enumKey );
}

bool Import::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Import::staticMetaObject, "properties", enumKey );
}

QString Import::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Import::properties>::type> ( enumValue ) );
}
