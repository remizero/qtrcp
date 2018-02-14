#include "MinLengthFacet.h"

using namespace Com::Ecosoftware::Engines::Xsd;

MinLengthFacet::MinLengthFacet ( QString value ) : FacetAbs ( value ) {}

MinLengthFacet::MinLengthFacet ( const MinLengthFacet & ) : FacetAbs () {}

MinLengthFacet::~MinLengthFacet () {}

int MinLengthFacet::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( MinLengthFacet::staticMetaObject, "properties", enumKey );
}

bool MinLengthFacet::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( MinLengthFacet::staticMetaObject, "properties", enumKey );
}

QString MinLengthFacet::enumToString ( MinLengthFacet::properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < MinLengthFacet::properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<MinLengthFacet::properties>::type> ( enumValue ) );
}
