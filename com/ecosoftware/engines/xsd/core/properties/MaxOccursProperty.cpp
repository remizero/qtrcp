#include "MaxOccursProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

MaxOccursProperty::MaxOccursProperty ( bool value ) {

  this->value = value;
}

MaxOccursProperty::MaxOccursProperty ( const MaxOccursProperty & ) : PropertyAbs () {}

MaxOccursProperty::~MaxOccursProperty () {}

bool MaxOccursProperty::getValue () const {

  return this->value;
}

void MaxOccursProperty::setValue ( bool value ) {

  this->value = value;
}
