#include "List.h"

using namespace Com::Ecosoftware::Engines::Xsd;

List::List () {}

List::List ( const List & ) : ElementAbs () {}

List::~List () {}

int List::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( List::staticMetaObject, "content", enumKey );
}

bool List::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( List::staticMetaObject, "content", enumKey );
}

QString List::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<List::content>::type> ( enumValue ) );
}

int List::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( List::staticMetaObject, "properties", enumKey );
}

bool List::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( List::staticMetaObject, "properties", enumKey );
}

QString List::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<List::properties>::type> ( enumValue ) );
}
