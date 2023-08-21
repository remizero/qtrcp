#include "NotQNameProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

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
