#include "DefaultProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

DefaultProperty::DefaultProperty ( QString value ) {

  this->value = value;
}

DefaultProperty::DefaultProperty ( const DefaultProperty &defaultProperty ) {

  this->value = defaultProperty.getValue ();
}

DefaultProperty::~DefaultProperty () {}

QString DefaultProperty::getValue () const {

  return this->value;
}

void DefaultProperty::setValue ( const QString &value ) {

  this->value = value;
}
