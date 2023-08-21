#include "MinExclusiveFacet.h"

using namespace NAMESPACE_LIBRARY_XSD;

MinExclusiveFacet::MinExclusiveFacet ( QString value ) : FacetAbs ( value ) {}

MinExclusiveFacet::MinExclusiveFacet ( const MinExclusiveFacet & ) : FacetAbs () {}

MinExclusiveFacet::~MinExclusiveFacet () {}

int MinExclusiveFacet::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( MinExclusiveFacet::staticMetaObject, "properties", enumKey );
}

bool MinExclusiveFacet::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( MinExclusiveFacet::staticMetaObject, "properties", enumKey );
}

QString MinExclusiveFacet::enumToString ( MinExclusiveFacet::properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < MinExclusiveFacet::properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<MinExclusiveFacet::properties>::type> ( enumValue ) );
}
