#include "BlockDefaultProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

BlockDefaultProperty::BlockDefaultProperty ( QString value ) {

  this->value = value;
}

BlockDefaultProperty::BlockDefaultProperty ( const BlockDefaultProperty & ) : PropertyAbs () {}

BlockDefaultProperty::~BlockDefaultProperty () {}

QString BlockDefaultProperty::getValue () const {

  return this->value;
}

void BlockDefaultProperty::setValue ( const QString &value ) {

  this->value = value;
}
