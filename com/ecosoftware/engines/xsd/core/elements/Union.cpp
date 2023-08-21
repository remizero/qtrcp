#include "Union.h"

using namespace NAMESPACE_LIBRARY_XSD;

Union::Union () {}

Union::Union ( const Union & ) : ElementAbs () {}

Union::~Union () {}

int Union::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Union::staticMetaObject, "content", enumKey );
}

bool Union::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Union::staticMetaObject, "content", enumKey );
}

QString Union::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Union::content>::type> ( enumValue ) );
}

int Union::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Union::staticMetaObject, "properties", enumKey );
}

bool Union::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Union::staticMetaObject, "properties", enumKey );
}

QString Union::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Union::properties>::type> ( enumValue ) );
}
