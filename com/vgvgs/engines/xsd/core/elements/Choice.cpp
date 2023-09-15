#include "Choice.h"

using namespace NAMESPACE_LIBRARY_XSD;

Choice::Choice () {}

Choice::Choice ( const Choice & ) : ElementAbs () {}

Choice::~Choice () {}

int Choice::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Choice::staticMetaObject, "content", enumKey );
}

bool Choice::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Choice::staticMetaObject, "content", enumKey );
}

QString Choice::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Choice::content>::type> ( enumValue ) );
}

int Choice::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Choice::staticMetaObject, "properties", enumKey );
}

bool Choice::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Choice::staticMetaObject, "properties", enumKey );
}

QString Choice::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Choice::properties>::type> ( enumValue ) );
}
