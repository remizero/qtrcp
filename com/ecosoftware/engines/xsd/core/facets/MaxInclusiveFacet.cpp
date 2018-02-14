#include "MaxInclusiveFacet.h"

using namespace Com::Ecosoftware::Engines::Xsd;

MaxInclusiveFacet::MaxInclusiveFacet ( QString value ) : FacetAbs ( value ) {}

MaxInclusiveFacet::MaxInclusiveFacet ( const MaxInclusiveFacet & ) : FacetAbs () {}

MaxInclusiveFacet::~MaxInclusiveFacet () {}

int MaxInclusiveFacet::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( MaxInclusiveFacet::staticMetaObject, "properties", enumKey );
}

bool MaxInclusiveFacet::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( MaxInclusiveFacet::staticMetaObject, "properties", enumKey );
}

QString MaxInclusiveFacet::enumToString ( MaxInclusiveFacet::properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < MaxInclusiveFacet::properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<MaxInclusiveFacet::properties>::type> ( enumValue ) );
}
