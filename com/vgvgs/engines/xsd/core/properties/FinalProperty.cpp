#include "FinalProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

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
