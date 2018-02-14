#include "AttributeFormDefaultProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

AttributeFormDefaultProperty::AttributeFormDefaultProperty ( QString value ) {

  this->value = value;
}

AttributeFormDefaultProperty::AttributeFormDefaultProperty ( const AttributeFormDefaultProperty & ) : PropertyAbs () {}

AttributeFormDefaultProperty::~AttributeFormDefaultProperty () {}

QString AttributeFormDefaultProperty::getValue () const {

  return this->value;
}

int AttributeFormDefaultProperty::indexOfValuesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( AttributeFormDefaultProperty::staticMetaObject, "values", enumKey );
}

bool AttributeFormDefaultProperty::inValuesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( AttributeFormDefaultProperty::staticMetaObject, "values", enumKey );
}

void AttributeFormDefaultProperty::setValue ( QString value ) {

  this->value = value;
}

QString AttributeFormDefaultProperty::valuesEnumToString ( AttributeFormDefaultProperty::values enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < AttributeFormDefaultProperty::values > ();
  return QString::fromLatin1 ( metaEnum.valueToKey ( static_cast<typename std::underlying_type<AttributeFormDefaultProperty::values>::type> ( enumValue ) ) ).toLower ();
  //return metaEnum.valueToKey ( static_cast<typename std::underlying_type<AttributeFormDefaultProperty::values>::type> ( enumValue ) );
}
