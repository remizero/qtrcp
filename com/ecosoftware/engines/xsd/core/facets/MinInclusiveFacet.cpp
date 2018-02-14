#include "MinInclusiveFacet.h"

using namespace Com::Ecosoftware::Engines::Xsd;

MinInclusiveFacet::MinInclusiveFacet ( QString value ) : FacetAbs ( value ) {}

MinInclusiveFacet::MinInclusiveFacet ( const MinInclusiveFacet & ) : FacetAbs () {}

MinInclusiveFacet::~MinInclusiveFacet () {}

int MinInclusiveFacet::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( MinInclusiveFacet::staticMetaObject, "properties", enumKey );
}

bool MinInclusiveFacet::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( MinInclusiveFacet::staticMetaObject, "properties", enumKey );
}

QString MinInclusiveFacet::enumToString ( MinInclusiveFacet::properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < MinInclusiveFacet::properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<MinInclusiveFacet::properties>::type> ( enumValue ) );
}
