#include "AppliesToEmptyProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

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
