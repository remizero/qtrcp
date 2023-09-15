#include "AnyAttribute.h"

using namespace NAMESPACE_LIBRARY_XSD;

AnyAttribute::AnyAttribute () {}

AnyAttribute::AnyAttribute ( const AnyAttribute & ) : ElementAbs () {}

AnyAttribute::~AnyAttribute () {}

int AnyAttribute::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( AnyAttribute::staticMetaObject, "content", enumKey );
}

bool AnyAttribute::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( AnyAttribute::staticMetaObject, "content", enumKey );
}

QString AnyAttribute::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<AnyAttribute::content>::type> ( enumValue ) );
}

int AnyAttribute::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( AnyAttribute::staticMetaObject, "properties", enumKey );
}

bool AnyAttribute::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( AnyAttribute::staticMetaObject, "properties", enumKey );
}

QString AnyAttribute::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<AnyAttribute::properties>::type> ( enumValue ) );
}
