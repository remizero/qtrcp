#include "SystemProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

SystemProperty::SystemProperty ( bool value ) {

  this->value = value;
}

SystemProperty::SystemProperty ( const SystemProperty & ) : PropertyAbs () {}

SystemProperty::~SystemProperty () {}

bool SystemProperty::getValue () const {

  return this->value;
}

void SystemProperty::setValue ( bool value ) {

  this->value = value;
}
