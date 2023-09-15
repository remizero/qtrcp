#include "FormProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

FormProperty::FormProperty ( QString value ) {

  this->value = value;
}

FormProperty::FormProperty ( const FormProperty & ) : PropertyAbs () {}

FormProperty::~FormProperty () {}

QString FormProperty::getValue () const {

  return this->value;
}

int FormProperty::indexOfValuesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( FormProperty::staticMetaObject, "values", enumKey );
}

bool FormProperty::inValuesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( FormProperty::staticMetaObject, "values", enumKey );
}

void FormProperty::setValue ( QString value ) {

  this->value = value;
}

QString FormProperty::valuesEnumToString ( FormProperty::values enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < FormProperty::values > ();
  return QString::fromLatin1 ( metaEnum.valueToKey ( static_cast<typename std::underlying_type<FormProperty::values>::type> ( enumValue ) ) ).toLower ();
  //return metaEnum.valueToKey ( static_cast<typename std::underlying_type<FormProperty::values>::type> ( enumValue ) );
}
