#include "Element.h"

using namespace Com::Ecosoftware::Engines::XsdEngine;

Element::Element () {}

QList<Attribute *> Element::getAttributes () const {

  return this->attributes;
}

QString Element::getDescription () const {

  return this->description;
}

QList<Element *> Element::getElementsList () const {

  return this->elementsList;
}

QString Element::getName () const {

  return this->name;
}

Type *Element::getType () const {

  return this->type;
}

Element *Element::getParent () const {

  return this->parent;
}

QList<Facet *> Element::getProperties () const {

  return this->properties;
}

void Element::setAttribute ( Attribute *value ) {

  this->attributes.append ( value );
}

void Element::setAttributes ( const QList<Attribute *> &value ) {

  this->attributes = value;
}

void Element::setDescription ( const QString &value ) {

  this->description = value;
}

void Element::setElementsList ( const QList<Element *> &value ) {

  this->elementsList = value;
}

void Element::setName ( const QString &value ) {

  this->name = value;
}

void Element::setType ( Type *value ) {

  this->type = value;
}

void Element::setParent ( Element *value ) {

  this->parent = value;
}

void Element::setProperty ( Facet *value ) {

  this->properties.append ( value );
}

void Element::setProperties ( const QList<Facet *> &value ) {

  this->properties = value;
}
