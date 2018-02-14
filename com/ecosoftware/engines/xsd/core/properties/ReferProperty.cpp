#include "ReferProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

ReferProperty::ReferProperty ( QString value ) {

  this->value = value;
}

ReferProperty::ReferProperty ( const ReferProperty & ) : PropertyAbs () {}

ReferProperty::~ReferProperty () {}

QString ReferProperty::getValue () const {

  return this->value;
}

void ReferProperty::setValue ( const QString &value ) {

  this->value = value;
}
