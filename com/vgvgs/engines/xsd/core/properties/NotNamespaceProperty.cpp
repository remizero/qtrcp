#include "NotNamespaceProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

NotNamespaceProperty::NotNamespaceProperty ( bool value ) {

  this->value = value;
}

NotNamespaceProperty::NotNamespaceProperty ( const NotNamespaceProperty & ) : PropertyAbs () {}

NotNamespaceProperty::~NotNamespaceProperty () {}

bool NotNamespaceProperty::getValue () const {

  return this->value;
}

void NotNamespaceProperty::setValue ( bool value ) {

  this->value = value;
}
