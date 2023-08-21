#include "NameProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

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
