#include "ComplexType.h"

using namespace NAMESPACE_LIBRARY_XSD;

ComplexType::ComplexType () {}

ComplexType::ComplexType ( const ComplexType & ) : ElementAbs () {}

ComplexType::~ComplexType () {}

int ComplexType::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( ComplexType::staticMetaObject, "content", enumKey );
}

bool ComplexType::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( ComplexType::staticMetaObject, "content", enumKey );
}

QString ComplexType::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<ComplexType::content>::type> ( enumValue ) );
}

int ComplexType::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( ComplexType::staticMetaObject, "properties", enumKey );
}

bool ComplexType::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( ComplexType::staticMetaObject, "properties", enumKey );
}

QString ComplexType::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<ComplexType::properties>::type> ( enumValue ) );
}
