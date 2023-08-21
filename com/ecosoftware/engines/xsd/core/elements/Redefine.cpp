#include "Redefine.h"

using namespace NAMESPACE_LIBRARY_XSD;

Redefine::Redefine () {}

Redefine::Redefine ( const Redefine & ) : ElementAbs () {}

Redefine::~Redefine () {}

int Redefine::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Redefine::staticMetaObject, "content", enumKey );
}

bool Redefine::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Redefine::staticMetaObject, "content", enumKey );
}

QString Redefine::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Redefine::content>::type> ( enumValue ) );
}

int Redefine::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Redefine::staticMetaObject, "properties", enumKey );
}

bool Redefine::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Redefine::staticMetaObject, "properties", enumKey );
}

QString Redefine::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Redefine::properties>::type> ( enumValue ) );
}
