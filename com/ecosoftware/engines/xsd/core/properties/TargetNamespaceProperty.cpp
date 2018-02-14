#include "TargetNamespaceProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

TargetNamespaceProperty::TargetNamespaceProperty ( bool value ) {

  this->value = value;
}

TargetNamespaceProperty::TargetNamespaceProperty ( const TargetNamespaceProperty & ) : PropertyAbs () {}

TargetNamespaceProperty::~TargetNamespaceProperty () {}

bool TargetNamespaceProperty::getValue () const {

  return this->value;
}

void TargetNamespaceProperty::setValue ( bool value ) {

  this->value = value;
}
