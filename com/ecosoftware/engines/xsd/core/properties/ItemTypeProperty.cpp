#include "ItemTypeProperty.h"

using namespace NAMESPACE_LIBRARY_XSD;

ItemTypeProperty::ItemTypeProperty ( QString value ) {

  this->value = value;
}

ItemTypeProperty::ItemTypeProperty ( const ItemTypeProperty & ) : PropertyAbs () {}

ItemTypeProperty::~ItemTypeProperty () {}

QString ItemTypeProperty::getValue () const {

  return this->value;
}

void ItemTypeProperty::setValue ( const QString &value ) {

  this->value = value;
}
