#include "Element.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Element::Element () {}

Element::Element ( const Element & ) : ElementAbs () {}

Element::~Element () {}

int Element::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Element::staticMetaObject, "content", enumKey );
}

bool Element::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Element::staticMetaObject, "content", enumKey );
}

QString Element::contentEnumToString ( content enumValue ) {

  /*QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Element::content>::type> ( enumValue ) );*/

  //QMetaEnum metaEnum = QMetaEnum::fromType < ElementAbs::elements > ();
  //QMetaEnum metaEnum = QMetaObject::enumerator ( QMetaObject::indexOfEnumerator ( "content" ) );
  //QMetaEnum metaEnum = this->metaObject ()->enumerator ( this->metaObject ()->indexOfEnumerator ( "content" ) );
  //QMetaEnum metaEnum = this->metaObject ()->enumerator ( this->metaObject ()->indexOfEnumerator ( "content" ) );
  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Element::content>::type> ( enumValue ) );
}

int Element::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Element::staticMetaObject, "properties", enumKey );
}

bool Element::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Element::staticMetaObject, "properties", enumKey );
}

QString Element::propertiesEnumToString ( properties enumValue ) {

  /*QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Element::content>::type> ( enumValue ) );*/

  //QMetaEnum metaEnum = QMetaEnum::fromType < ElementAbs::elements > ();
  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Element::properties>::type> ( enumValue ) );
}
