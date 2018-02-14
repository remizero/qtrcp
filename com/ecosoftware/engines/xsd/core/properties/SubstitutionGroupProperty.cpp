#include "SubstitutionGroupProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

SubstitutionGroupProperty::SubstitutionGroupProperty ( bool value ) {

  this->value = value;
}

SubstitutionGroupProperty::SubstitutionGroupProperty ( const SubstitutionGroupProperty & ) : PropertyAbs () {}

SubstitutionGroupProperty::~SubstitutionGroupProperty () {}

bool SubstitutionGroupProperty::getValue () const {

  return this->value;
}

void SubstitutionGroupProperty::setValue ( bool value ) {

  this->value = value;
}
