#include "DefaultAttributesProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

DefaultAttributesProperty::DefaultAttributesProperty ( QString value ) {

  this->value = value;
}

DefaultAttributesProperty::DefaultAttributesProperty ( const DefaultAttributesProperty & ) : PropertyAbs () {}

DefaultAttributesProperty::~DefaultAttributesProperty () {}

QString DefaultAttributesProperty::getValue () const {

  return this->value;
}

void DefaultAttributesProperty::setValue ( const QString &value ) {

  this->value = value;
}
