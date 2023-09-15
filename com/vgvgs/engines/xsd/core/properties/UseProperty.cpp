#include "UseProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

UseProperty::UseProperty ( bool value ) {

  this->value = value;
}

UseProperty::UseProperty ( const UseProperty & ) : PropertyAbs () {}

UseProperty::~UseProperty () {}

bool UseProperty::getValue () const {

  return this->value;
}

void UseProperty::setValue ( bool value ) {

  this->value = value;
}
