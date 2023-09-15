#include "WhitespaceFacet.h"

using namespace NAMESPACE_LIBRARY_XSD;

WhitespaceFacet::WhitespaceFacet ( QString value ) : FacetAbs ( value ) {}

WhitespaceFacet::WhitespaceFacet ( const WhitespaceFacet & ) : FacetAbs () {}

WhitespaceFacet::~WhitespaceFacet () {}

int WhitespaceFacet::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( WhitespaceFacet::staticMetaObject, "properties", enumKey );
}

bool WhitespaceFacet::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( WhitespaceFacet::staticMetaObject, "properties", enumKey );
}

QString WhitespaceFacet::enumToString ( WhitespaceFacet::properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < WhitespaceFacet::properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<WhitespaceFacet::properties>::type> ( enumValue ) );
}
