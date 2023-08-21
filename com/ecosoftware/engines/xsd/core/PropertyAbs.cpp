#include "PropertyAbs.h"

using namespace NAMESPACE_LIBRARY_XSD;

PropertyAbs::PropertyAbs ( QObject *parent ) : QObject ( parent ) {}

PropertyAbs::PropertyAbs ( const PropertyAbs & ) : QObject () {}

PropertyAbs::~PropertyAbs () {}

int PropertyAbs::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( PropertyAbs::staticMetaObject, "properties", enumKey );
}

bool PropertyAbs::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( PropertyAbs::staticMetaObject, "properties", enumKey );
}

QString PropertyAbs::enumToString ( PropertyAbs::properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < PropertyAbs::properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<PropertyAbs::properties>::type> ( enumValue ) );
}
