#include "InheritableProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

InheritableProperty::InheritableProperty ( bool value ) {

  this->value = value;
}

InheritableProperty::InheritableProperty ( const InheritableProperty & ) : PropertyAbs () {}

InheritableProperty::~InheritableProperty () {}

bool InheritableProperty::getValue () const {

  return this->value;
}

void InheritableProperty::setValue ( bool value ) {

  this->value = value;
}
