#include "Facet.h"

using namespace Com::Ecosoftware::Engines::XsdEngine;

Facet::Facet () {}

QString Facet::getName () const {

  return this->name;
}

QString Facet::getValue () const {

  return this->value;
}

void Facet::setName ( const QString &value ) {

  this->name = value;
}

void Facet::setValue ( const QString &value ) {

  this->value = value;
}
