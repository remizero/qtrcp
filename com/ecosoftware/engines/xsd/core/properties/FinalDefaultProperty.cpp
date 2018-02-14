#include "FinalDefaultProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

FinalDefaultProperty::FinalDefaultProperty ( QString value ) {

  this->value = value;
}

FinalDefaultProperty::FinalDefaultProperty ( const FinalDefaultProperty & ) : PropertyAbs () {}

FinalDefaultProperty::~FinalDefaultProperty () {}

QString FinalDefaultProperty::getValue () const {

  return this->value;
}

void FinalDefaultProperty::setValue ( const QString &value ) {

  this->value = value;
}
