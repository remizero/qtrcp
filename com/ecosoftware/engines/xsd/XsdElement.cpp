#include "XsdElement.h"

using namespace Com::Ecosoftware::Engines::Xsd;

XsdElement::XsdElement () {

  this->setParent ( nullptr );
  this->setElementLevel ( Xsd::levelEnum::EMPTY );
}

/*QList<XsdAttribute *> XsdElement::getAttributes () const {

  return this->attributes;
}*/

Xsd::indicatorEnum XsdElement::getElementIndicator () const {

  return this->elementIndicator;
}

Xsd::levelEnum XsdElement::getElementLevel () const {

  return this->elementLevel;
}

QList<XsdElement *> XsdElement::getElementsList () const {

  return this->elementsList;
}

QList<FacetAbs *> XsdElement::getFacets () const {

  return this->facets;
}

XsdElement *XsdElement::getParent () const {

  return this->parent;
}

QList<PropertyAbs *> XsdElement::getProperties () const {

  return this->properties;
}

PropertyAbs *XsdElement::getProperty ( QString property ) const {

  PropertyAbs *propertyObj = new PropertyAbs ();
  const int propertiesCount = this->properties.count ();
  for ( int i = 0; i < propertiesCount; i++ ) {

    property = "Com::Ecosoftware::Engines::Xsd::" + property;
    if ( property.compare ( this->properties.at ( i )->metaObject ()->className () ) == 0 ) {

      propertyObj = this->properties.at ( i );
      break;
    }
  }
  return propertyObj;
}

bool XsdElement::hasRestriction () const {

  return this->restriction;
}

bool XsdElement::isSimpleType () const {

  return this->simpleType;
}

/*void XsdElement::setAttribute ( XsdAttribute *value ) {

  this->attributes.append ( value );
}

void XsdElement::setAttributes ( const QList<XsdAttribute *> &value ) {

  this->attributes = value;
}*/

void XsdElement::setElementIndicator ( const Xsd::indicatorEnum &value ) {

  this->elementIndicator = value;
}

void XsdElement::setElementLevel ( const Xsd::levelEnum &value ) {

  this->elementLevel = value;
}

void XsdElement::setElement ( XsdElement *value ) {

  this->elementsList.append ( value );
}

void XsdElement::setElementsList ( const QList<XsdElement *> &value ) {

  this->elementsList = value;
}

void XsdElement::setFacet ( FacetAbs *value ) {

  this->facets.append ( value );
}

void XsdElement::setFacets ( const QList<FacetAbs *> &value ) {

  this->facets = value;
}

void XsdElement::setParent ( XsdElement *value ) {

  this->parent = value;
}

void XsdElement::setProperties ( const QList<PropertyAbs *> &value ) {

  this->properties = value;
}

void XsdElement::setProperty ( PropertyAbs *property ) {

  this->properties.append ( property );
}

void XsdElement::setRestriction ( bool value ) {

  this->restriction = value;
}

void XsdElement::setSimpleType ( bool value ) {

  this->simpleType = value;
}
