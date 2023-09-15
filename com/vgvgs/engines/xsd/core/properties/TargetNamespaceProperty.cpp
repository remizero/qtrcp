#include "TargetNamespaceProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

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
