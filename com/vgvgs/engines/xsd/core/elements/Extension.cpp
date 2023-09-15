#include "Extension.h"

using namespace NAMESPACE_LIBRARY_XSD;

Extension::Extension () {}

Extension::Extension ( const Extension & ) : ElementAbs () {}

Extension::~Extension () {}

int Extension::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Extension::staticMetaObject, "content", enumKey );
}

bool Extension::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Extension::staticMetaObject, "content", enumKey );
}

QString Extension::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Extension::content>::type> ( enumValue ) );
}

int Extension::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Extension::staticMetaObject, "properties", enumKey );
}

bool Extension::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Extension::staticMetaObject, "properties", enumKey );
}

QString Extension::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Extension::properties>::type> ( enumValue ) );
}
