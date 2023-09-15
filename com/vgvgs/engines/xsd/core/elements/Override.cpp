#include "Override.h"

using namespace NAMESPACE_LIBRARY_XSD;

Override::Override () {}

Override::Override ( const Override & ) : ElementAbs () {}

Override::~Override () {}

int Override::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Override::staticMetaObject, "content", enumKey );
}

bool Override::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Override::staticMetaObject, "content", enumKey );
}

QString Override::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Override::content>::type> ( enumValue ) );
}

int Override::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Override::staticMetaObject, "properties", enumKey );
}

bool Override::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Override::staticMetaObject, "properties", enumKey );
}

QString Override::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Override::properties>::type> ( enumValue ) );
}
