#include "BaseProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

BaseProperty::BaseProperty ( QString value ) {

  this->value = value;
}

BaseProperty::BaseProperty ( const BaseProperty & ) : PropertyAbs () {}

BaseProperty::~BaseProperty () {}

QString BaseProperty::getValue () const {

  return this->value;
}

void BaseProperty::setValue ( const QString &value ) {

  this->value = value;
}
