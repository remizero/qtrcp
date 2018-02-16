#include "Assert.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Assert::Assert () {}

Assert::Assert ( const Assert & ) : ElementAbs () {}

Assert::~Assert () {}

int Assert::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Assert::staticMetaObject, "content", enumKey );
}

bool Assert::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Assert::staticMetaObject, "content", enumKey );
}

QString Assert::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Assert::content>::type> ( enumValue ) );
}

int Assert::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Assert::staticMetaObject, "properties", enumKey );
}

bool Assert::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Assert::staticMetaObject, "properties", enumKey );
}

QString Assert::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Assert::properties>::type> ( enumValue ) );
}
