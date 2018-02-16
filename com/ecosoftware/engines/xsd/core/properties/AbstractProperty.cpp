#include "AbstractProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

AbstractProperty::AbstractProperty ( bool value ) {

  this->value = value;
}

AbstractProperty::AbstractProperty ( const AbstractProperty & ) : PropertyAbs () {}

AbstractProperty::~AbstractProperty () {}

bool AbstractProperty::getValue () const {

  return this->value;
}

void AbstractProperty::setValue ( bool value ) {

  this->value = value;
}
