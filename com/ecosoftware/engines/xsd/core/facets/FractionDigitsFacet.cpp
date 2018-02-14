#include "FractionDigitsFacet.h"

using namespace Com::Ecosoftware::Engines::Xsd;

FractionDigitsFacet::FractionDigitsFacet ( QString value ) : FacetAbs ( value ) {}

FractionDigitsFacet::FractionDigitsFacet ( const FractionDigitsFacet & ) : FacetAbs () {}

FractionDigitsFacet::~FractionDigitsFacet () {}

int FractionDigitsFacet::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( FractionDigitsFacet::staticMetaObject, "properties", enumKey );
}

bool FractionDigitsFacet::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( FractionDigitsFacet::staticMetaObject, "properties", enumKey );
}

QString FractionDigitsFacet::enumToString ( FractionDigitsFacet::properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < FractionDigitsFacet::properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<FractionDigitsFacet::properties>::type> ( enumValue ) );
}
