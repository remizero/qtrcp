#include "AssertionsFacet.h"

using namespace NAMESPACE_LIBRARY_XSD;

AssertionsFacet::AssertionsFacet ( QString value ) : FacetAbs ( value ) {}

AssertionsFacet::AssertionsFacet ( const AssertionsFacet & ) : FacetAbs () {}

AssertionsFacet::~AssertionsFacet () {}

int AssertionsFacet::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( AssertionsFacet::staticMetaObject, "properties", enumKey );
}

bool AssertionsFacet::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( AssertionsFacet::staticMetaObject, "properties", enumKey );
}

QString AssertionsFacet::enumToString ( AssertionsFacet::properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < AssertionsFacet::properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<AssertionsFacet::properties>::type> ( enumValue ) );
}
