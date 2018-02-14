#include "NotQNameProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

NotQNameProperty::NotQNameProperty ( bool value ) {

  this->value = value;
}

NotQNameProperty::NotQNameProperty ( const NotQNameProperty & ) : PropertyAbs () {}

NotQNameProperty::~NotQNameProperty () {}

bool NotQNameProperty::getValue () const {

  return this->value;
}

void NotQNameProperty::setValue ( bool value ) {

  this->value = value;
}
