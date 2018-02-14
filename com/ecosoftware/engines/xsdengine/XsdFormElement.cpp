#include "XsdFormElement.h"

using namespace Com::Ecosoftware::Engines::XsdEngine;

XsdFormElement::XsdFormElement ( XsdFormElement *xsdFormElement ) {

  this->setFormElementType ( XsdEngine::EMPTY );
  this->setParent ( xsdFormElement );
}

QString XsdFormElement::getElementComment () const {

  return this->elementComment;
}

QList<XsdFormElement *> XsdFormElement::getElementsList () const {

  return this->elementsList;
}

QString XsdFormElement::getElementName () const {

  return this->elementName;
}

QString XsdFormElement::getElementType () const {

  return this->elementType;
}

QString XsdFormElement::getElementValue () const {

  return this->elementValue;
}

XsdEngine::xsdLevelEnum XsdFormElement::getFormElementType () const {

  return this->formElementType;
}

XsdFormElement *XsdFormElement::getParent () const {

  return this->parent;
}

void XsdFormElement::setElementComment ( const QString &value ) {

  this->elementComment = value;
}

void XsdFormElement::setElementList ( XsdFormElement *value ) {

  this->elementsList.append ( value );
}

void XsdFormElement::setElementsList ( const QList<XsdFormElement *> &value ) {

  this->elementsList = value;
}

void XsdFormElement::setElementName ( const QString &value ) {

  this->elementName = value;
}

void XsdFormElement::setElementType ( const QString &value ) {

  this->elementType = value;
}

void XsdFormElement::setElementValue ( const QString &value ) {

  this->elementValue = value;
}

void XsdFormElement::setFormElementType  (const XsdEngine::xsdLevelEnum &value ) {

  this->formElementType = value;
}

void XsdFormElement::setParent ( XsdFormElement *value ) {

  this->parent = value;
}
