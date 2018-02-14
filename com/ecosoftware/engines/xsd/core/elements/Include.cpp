#include "Include.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Include::Include () {}

Include::Include ( const Include & ) : ElementAbs () {}

Include::~Include () {}

int Include::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Include::staticMetaObject, "content", enumKey );
}

bool Include::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Include::staticMetaObject, "content", enumKey );
}

QString Include::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Include::content>::type> ( enumValue ) );
}

int Include::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Include::staticMetaObject, "properties", enumKey );
}

bool Include::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Include::staticMetaObject, "properties", enumKey );
}

QString Include::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Include::properties>::type> ( enumValue ) );
}
