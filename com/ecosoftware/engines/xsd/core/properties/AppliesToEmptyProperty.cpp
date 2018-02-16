#include "AppliesToEmptyProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

AppliesToEmptyProperty::AppliesToEmptyProperty ( bool value ) {

  this->value = value;
}

AppliesToEmptyProperty::AppliesToEmptyProperty ( const AppliesToEmptyProperty & ) : PropertyAbs () {}

AppliesToEmptyProperty::~AppliesToEmptyProperty () {}

bool AppliesToEmptyProperty::getValue () const {

  return this->value;
}

void AppliesToEmptyProperty::setValue ( bool value ) {

  this->value = value;
}
