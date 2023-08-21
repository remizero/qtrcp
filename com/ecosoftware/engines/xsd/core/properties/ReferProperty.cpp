#include "ReferProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

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
