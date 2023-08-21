#include "PatternFacet.h"

using namespace NAMESPACE_LIBRARY_XSD;

PatternFacet::PatternFacet ( QString value ) : FacetAbs ( value ) {}

PatternFacet::PatternFacet ( const PatternFacet & ) : FacetAbs () {}

PatternFacet::~PatternFacet () {}

int PatternFacet::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( PatternFacet::staticMetaObject, "properties", enumKey );
}

bool PatternFacet::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( PatternFacet::staticMetaObject, "properties", enumKey );
}

QString PatternFacet::enumToString ( PatternFacet::properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < PatternFacet::properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<PatternFacet::properties>::type> ( enumValue ) );
}
