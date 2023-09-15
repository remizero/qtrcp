#include "TypeProperty.h"
#include <QDebug>

using namespace NAMESPACE_LIBRARY_XSD;

TypeProperty::TypeProperty ( QString value ) {

  this->setValue ( value );
}

TypeProperty::TypeProperty ( const TypeProperty & ) : PropertyAbs () {}

TypeProperty::~TypeProperty () {}

TypeAbs::types TypeProperty::getValue () const {

  return this->value;
}

void TypeProperty::setValue ( const QString value ) {

  if ( TypeAbs::inEmun ( value ) ) {

    this->value = static_cast<TypeAbs::types> ( TypeAbs::indexOfEnum ( value ) );

  } else {

    this->value = TypeAbs::types::USER;
  }
}

void TypeProperty::setValue ( TypeAbs::types value ) {

  this->value = value;
}

int TypeProperty::toInt () {

  return TypeAbs::indexOfEnum ( TypeAbs::enumToString ( this->value ) );
}

QString TypeProperty::toString () {

  return TypeAbs::enumToString ( this->value );
}
