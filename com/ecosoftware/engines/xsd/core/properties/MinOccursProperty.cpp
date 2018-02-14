#include "MinOccursProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

MinOccursProperty::MinOccursProperty ( bool value ) {

  this->value = value;
}

MinOccursProperty::MinOccursProperty ( const MinOccursProperty & ) : PropertyAbs () {}

MinOccursProperty::~MinOccursProperty () {}

bool MinOccursProperty::getValue () const {

  return this->value;
}

void MinOccursProperty::setValue ( bool value ) {

  this->value = value;
}
