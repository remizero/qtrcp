#include "VersionProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

VersionProperty::VersionProperty ( bool value ) {

  this->value = value;
}

VersionProperty::VersionProperty ( const VersionProperty & ) : PropertyAbs () {}

VersionProperty::~VersionProperty () {}

bool VersionProperty::getValue () const {

  return this->value;
}

void VersionProperty::setValue ( bool value ) {

  this->value = value;
}
