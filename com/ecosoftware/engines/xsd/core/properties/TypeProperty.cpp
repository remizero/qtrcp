#include "TypeProperty.h"
#include <QDebug>

using namespace Com::Ecosoftware::Engines::Xsd;

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

    qDebug () << "El valor STRING que trae es: " << value;
    qDebug () << "El valor ENTERO que trae es: " << TypeAbs::indexOfEnum ( value );
    qDebug () << "El valor CONVERTIDO que trae es: " << static_cast<TypeAbs::types> ( TypeAbs::indexOfEnum ( value ) );
    this->value = static_cast<TypeAbs::types> ( TypeAbs::indexOfEnum ( value ) );
    qDebug () << "El valor directo del TypeProperty: " << this->value;

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
