#include "SourceProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

SourceProperty::SourceProperty ( bool value ) {

  this->value = value;
}

SourceProperty::SourceProperty ( const SourceProperty & ) : PropertyAbs () {}

SourceProperty::~SourceProperty () {}

bool SourceProperty::getValue () const {

  return this->value;
}

void SourceProperty::setValue ( bool value ) {

  this->value = value;
}
