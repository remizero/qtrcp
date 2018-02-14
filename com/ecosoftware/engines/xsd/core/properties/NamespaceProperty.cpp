#include "NamespaceProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

NamespaceProperty::NamespaceProperty ( QString value ) {

  this->value = value;
}

NamespaceProperty::NamespaceProperty ( const NamespaceProperty & ) : PropertyAbs () {}

NamespaceProperty::~NamespaceProperty () {}

QString NamespaceProperty::getValue () const {

  return this->value;
}

void NamespaceProperty::setValue ( const QString &value ) {

  this->value = value;
}
