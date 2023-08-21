#include "VersionProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

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
