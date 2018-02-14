#include "ElementFormDefaultProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

ElementFormDefaultProperty::ElementFormDefaultProperty ( QString value ) {

  this->value = value;
}

ElementFormDefaultProperty::ElementFormDefaultProperty ( const ElementFormDefaultProperty & ) : PropertyAbs () {}

ElementFormDefaultProperty::~ElementFormDefaultProperty () {}

QString ElementFormDefaultProperty::getValue () const {

  return this->value;
}

int ElementFormDefaultProperty::indexOfValuesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( ElementFormDefaultProperty::staticMetaObject, "values", enumKey );
}

bool ElementFormDefaultProperty::inValuesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( ElementFormDefaultProperty::staticMetaObject, "values", enumKey );
}

void ElementFormDefaultProperty::setValue ( QString value ) {

  this->value = value;
}

QString ElementFormDefaultProperty::valuesEnumToString ( ElementFormDefaultProperty::values enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < ElementFormDefaultProperty::values > ();
  return QString::fromLatin1 ( metaEnum.valueToKey ( static_cast<typename std::underlying_type<ElementFormDefaultProperty::values>::type> ( enumValue ) ) ).toLower ();
  //return metaEnum.valueToKey ( static_cast<typename std::underlying_type<ElementFormDefaultProperty::values>::type> ( enumValue ) );
}
