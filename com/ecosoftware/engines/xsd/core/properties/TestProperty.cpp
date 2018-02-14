#include "TestProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

TestProperty::TestProperty ( bool value ) {

  this->value = value;
}

TestProperty::TestProperty ( const TestProperty & ) : PropertyAbs () {}

TestProperty::~TestProperty () {}

bool TestProperty::getValue () const {

  return this->value;
}

void TestProperty::setValue ( bool value ) {

  this->value = value;
}
