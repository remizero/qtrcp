#include "Field.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Field::Field () {}

Field::Field ( const Field & ) : ElementAbs () {}

Field::~Field () {}

int Field::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Field::staticMetaObject, "content", enumKey );
}

bool Field::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Field::staticMetaObject, "content", enumKey );
}

QString Field::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Field::content>::type> ( enumValue ) );
}

int Field::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Field::staticMetaObject, "properties", enumKey );
}

bool Field::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Field::staticMetaObject, "properties", enumKey );
}

QString Field::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Field::properties>::type> ( enumValue ) );
}
