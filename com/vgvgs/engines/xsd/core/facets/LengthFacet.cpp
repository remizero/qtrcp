#include "LengthFacet.h"

using namespace NAMESPACE_LIBRARY_XSD;

LengthFacet::LengthFacet ( QString value ) : FacetAbs ( value ) {}

LengthFacet::LengthFacet ( const LengthFacet & ) : FacetAbs () {}

LengthFacet::~LengthFacet () {}

int LengthFacet::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( LengthFacet::staticMetaObject, "properties", enumKey );
}

bool LengthFacet::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( LengthFacet::staticMetaObject, "properties", enumKey );
}

QString LengthFacet::enumToString ( LengthFacet::properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < LengthFacet::properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<LengthFacet::properties>::type> ( enumValue ) );
}
