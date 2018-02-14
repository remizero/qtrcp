#include "MaxLengthFacet.h"

using namespace Com::Ecosoftware::Engines::Xsd;

MaxLengthFacet::MaxLengthFacet ( QString value ) : FacetAbs ( value ) {}

MaxLengthFacet::MaxLengthFacet ( const MaxLengthFacet & ) : FacetAbs () {}

MaxLengthFacet::~MaxLengthFacet () {}

int MaxLengthFacet::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( MaxLengthFacet::staticMetaObject, "properties", enumKey );
}

bool MaxLengthFacet::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( MaxLengthFacet::staticMetaObject, "properties", enumKey );
}

QString MaxLengthFacet::enumToString ( MaxLengthFacet::properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < MaxLengthFacet::properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<MaxLengthFacet::properties>::type> ( enumValue ) );
}
