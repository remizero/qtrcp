#include "MemberTypesProperty.h"

using namespace Com::Ecosoftware::Engines::Xsd;

MemberTypesProperty::MemberTypesProperty ( QString value ) {

  this->value = value;
}

MemberTypesProperty::MemberTypesProperty ( const MemberTypesProperty & ) : PropertyAbs () {}

MemberTypesProperty::~MemberTypesProperty () {}

QString MemberTypesProperty::getValue () const {

  return this->value;
}

void MemberTypesProperty::setValue ( const QString &value ) {

  this->value = value;
}
