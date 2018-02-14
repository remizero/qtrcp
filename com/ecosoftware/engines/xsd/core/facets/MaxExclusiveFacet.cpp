#include "MaxExclusiveFacet.h"

using namespace Com::Ecosoftware::Engines::Xsd;

MaxExclusiveFacet::MaxExclusiveFacet ( QString value ) : FacetAbs ( value ) {}

MaxExclusiveFacet::MaxExclusiveFacet ( const MaxExclusiveFacet & ) : FacetAbs () {}

MaxExclusiveFacet::~MaxExclusiveFacet () {}

int MaxExclusiveFacet::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( MaxExclusiveFacet::staticMetaObject, "properties", enumKey );
}

bool MaxExclusiveFacet::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( MaxExclusiveFacet::staticMetaObject, "properties", enumKey );
}

QString MaxExclusiveFacet::enumToString ( MaxExclusiveFacet::properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < MaxExclusiveFacet::properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<MaxExclusiveFacet::properties>::type> ( enumValue ) );
}
