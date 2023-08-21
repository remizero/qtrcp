#include "BlockProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

BlockProperty::BlockProperty ( QString value ) {

  this->value = value;
}

BlockProperty::BlockProperty ( const BlockProperty & ) : PropertyAbs () {}

BlockProperty::~BlockProperty () {}

QString BlockProperty::getValue () const {

  return this->value;
}

void BlockProperty::setValue ( const QString &value ) {

  this->value = value;
}
