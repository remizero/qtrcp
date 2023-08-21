#include "FixedProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

FixedProperty::FixedProperty ( QString value ) {

  this->value = value;
}

FixedProperty::FixedProperty ( const FixedProperty & ) : PropertyAbs () {}

FixedProperty::~FixedProperty () {}

QString FixedProperty::getValue () const {

  return this->value;
}

void FixedProperty::setValue ( const QString &value ) {

  this->value = value;
}
