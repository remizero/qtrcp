#include "Property.h"

using namespace Com::Ecosoftware::Engines::XsdEngine;

Property::Property () {}

QString Property::getName () const {

  return this->name;
}

QString Property::getValue () const {

  return this->value;
}

void Property::setName ( const QString &value ) {

  this->name = value;
}

void Property::setValue ( const QString &value ) {

  this->value = value;
}
