#include "MixedProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

MixedProperty::MixedProperty ( bool value ) {

  this->value = value;
}

MixedProperty::MixedProperty ( const MixedProperty & ) : PropertyAbs () {}

MixedProperty::~MixedProperty () {}

bool MixedProperty::getValue () const {

  return this->value;
}

void MixedProperty::setValue ( bool value ) {

  this->value = value;
}
