#include "ExplicitTimeZoneFacet.h"

using namespace Com::Ecosoftware::Engines::Xsd;

ExplicitTimeZoneFacet::ExplicitTimeZoneFacet ( QString value ) : FacetAbs ( value ) {}

ExplicitTimeZoneFacet::ExplicitTimeZoneFacet ( const ExplicitTimeZoneFacet & ) : FacetAbs () {}

ExplicitTimeZoneFacet::~ExplicitTimeZoneFacet () {}

int ExplicitTimeZoneFacet::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( ExplicitTimeZoneFacet::staticMetaObject, "properties", enumKey );
}

bool ExplicitTimeZoneFacet::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( ExplicitTimeZoneFacet::staticMetaObject, "properties", enumKey );
}

QString ExplicitTimeZoneFacet::enumToString ( ExplicitTimeZoneFacet::properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < ExplicitTimeZoneFacet::properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<ExplicitTimeZoneFacet::properties>::type> ( enumValue ) );
}
