#include "ModeProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

ModeProperty::ModeProperty ( QString value ) {

  this->value = value;
}

ModeProperty::ModeProperty ( const ModeProperty & ) : PropertyAbs () {}

ModeProperty::~ModeProperty () {}

QString ModeProperty::getValue () const {

  return this->value;
}

int ModeProperty::indexOfValuesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( ModeProperty::staticMetaObject, "values", enumKey );
}

bool ModeProperty::inValuesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( ModeProperty::staticMetaObject, "values", enumKey );
}

void ModeProperty::setValue ( QString value ) {

  this->value = value;
}

QString ModeProperty::valuesEnumToString ( ModeProperty::values enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < ModeProperty::values > ();
  return QString::fromLatin1 ( metaEnum.valueToKey ( static_cast<typename std::underlying_type<ModeProperty::values>::type> ( enumValue ) ) ).toLower ();
  //return metaEnum.valueToKey ( static_cast<typename std::underlying_type<ModeProperty::values>::type> ( enumValue ) );
}
