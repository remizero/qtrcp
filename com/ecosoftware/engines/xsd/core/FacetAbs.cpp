#include "FacetAbs.h"

using namespace NAMESPACE_LIBRARY_XSD;

FacetAbs::FacetAbs ( QString value ) {

  this->value = value;
}

FacetAbs::FacetAbs ( const FacetAbs & ) : QObject () {}

FacetAbs::~FacetAbs () {}

int FacetAbs::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( FacetAbs::staticMetaObject, "content", enumKey );
}

bool FacetAbs::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( FacetAbs::staticMetaObject, "content", enumKey );
}

QString FacetAbs::contentEnumToString ( FacetAbs::facets enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < FacetAbs::facets > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<FacetAbs::facets>::type> ( enumValue ) );
}

int FacetAbs::indexOfFacetsEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( FacetAbs::staticMetaObject, "facets", enumKey );
}

bool FacetAbs::inFacetsEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( FacetAbs::staticMetaObject, "facets", enumKey );
}

QString FacetAbs::facetsEnumToString ( FacetAbs::facets enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < FacetAbs::facets > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<FacetAbs::facets>::type> ( enumValue ) );
}

int FacetAbs::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( FacetAbs::staticMetaObject, "properties", enumKey );
}

bool FacetAbs::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( FacetAbs::staticMetaObject, "properties", enumKey );
}

QString FacetAbs::propertiesEnumToString ( FacetAbs::facets enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < FacetAbs::facets > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<FacetAbs::facets>::type> ( enumValue ) );
}

QString FacetAbs::getValue () const {

  return this->value;
}

void FacetAbs::setValue ( const QString &value ) {

  this->value = value;
}
