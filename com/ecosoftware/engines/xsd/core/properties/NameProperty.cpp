#include "NameProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

NameProperty::NameProperty ( QString value ) {

  this->value = value;
}

NameProperty::NameProperty ( const NameProperty & ) : PropertyAbs () {}

NameProperty::~NameProperty () {}

QString NameProperty::getValue () const {

  return this->value;
}

void NameProperty::setValue ( const QString &value ) {

  this->value = value;
}
