#include "Annotation.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Annotation::Annotation () {}

Annotation::Annotation ( const Annotation & ) : ElementAbs () {}

Annotation::~Annotation () {}

int Annotation::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Annotation::staticMetaObject, "content", enumKey );
}

bool Annotation::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Annotation::staticMetaObject, "content", enumKey );
}

QString Annotation::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Annotation::content>::type> ( enumValue ) );
}

int Annotation::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Annotation::staticMetaObject, "properties", enumKey );
}

bool Annotation::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Annotation::staticMetaObject, "properties", enumKey );
}

QString Annotation::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Annotation::properties>::type> ( enumValue ) );
}
