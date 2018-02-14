#include "TotalDigitsFacet.h"

using namespace Com::Ecosoftware::Engines::Xsd;

TotalDigitsFacet::TotalDigitsFacet ( QString value ) : FacetAbs ( value ) {}

TotalDigitsFacet::TotalDigitsFacet ( const TotalDigitsFacet & ) : FacetAbs () {}

TotalDigitsFacet::~TotalDigitsFacet () {}

int TotalDigitsFacet::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( TotalDigitsFacet::staticMetaObject, "properties", enumKey );
}

bool TotalDigitsFacet::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( TotalDigitsFacet::staticMetaObject, "properties", enumKey );
}

QString TotalDigitsFacet::enumToString ( TotalDigitsFacet::properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < TotalDigitsFacet::properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<TotalDigitsFacet::properties>::type> ( enumValue ) );
}
