#include "EnumerationFacet.h"

using namespace Com::Ecosoftware::Engines::Xsd;

EnumerationFacet::EnumerationFacet ( QString value ) : FacetAbs ( value ) {}

EnumerationFacet::EnumerationFacet ( const EnumerationFacet & ) : FacetAbs () {}

EnumerationFacet::~EnumerationFacet () {}

int EnumerationFacet::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( EnumerationFacet::staticMetaObject, "properties", enumKey );
}

bool EnumerationFacet::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( EnumerationFacet::staticMetaObject, "properties", enumKey );
}

QString EnumerationFacet::enumToString ( EnumerationFacet::properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < EnumerationFacet::properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<EnumerationFacet::properties>::type> ( enumValue ) );
}
