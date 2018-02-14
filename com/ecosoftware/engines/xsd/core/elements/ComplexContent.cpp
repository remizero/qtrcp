#include "ComplexContent.h"

using namespace Com::Ecosoftware::Engines::Xsd;

ComplexContent::ComplexContent () {}

ComplexContent::ComplexContent ( const ComplexContent & ) : ElementAbs () {}

ComplexContent::~ComplexContent () {}

int ComplexContent::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( ComplexContent::staticMetaObject, "content", enumKey );
}

bool ComplexContent::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( ComplexContent::staticMetaObject, "content", enumKey );
}

QString ComplexContent::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<ComplexContent::content>::type> ( enumValue ) );
}

int ComplexContent::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( ComplexContent::staticMetaObject, "properties", enumKey );
}

bool ComplexContent::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( ComplexContent::staticMetaObject, "properties", enumKey );
}

QString ComplexContent::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<ComplexContent::properties>::type> ( enumValue ) );
}
