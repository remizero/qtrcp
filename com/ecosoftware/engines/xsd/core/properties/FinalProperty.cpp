#include "FinalProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

FinalProperty::FinalProperty ( QString value ) {

  this->value = value;
}

FinalProperty::FinalProperty ( const FinalProperty & ) : PropertyAbs () {}

FinalProperty::~FinalProperty () {}

QString FinalProperty::getValue () const {

  return this->value;
}

void FinalProperty::setValue ( const QString &value ) {

  this->value = value;
}
