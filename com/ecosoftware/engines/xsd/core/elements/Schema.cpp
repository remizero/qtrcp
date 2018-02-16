#include "Schema.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Schema::Schema () {}

Schema::Schema ( const Schema & ) : ElementAbs () {}

Schema::~Schema () {}

int Schema::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Schema::staticMetaObject, "content", enumKey );
}

bool Schema::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Schema::staticMetaObject, "content", enumKey );
}

QString Schema::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Schema::content>::type> ( enumValue ) );
}

int Schema::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Schema::staticMetaObject, "properties", enumKey );
}

bool Schema::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Schema::staticMetaObject, "properties", enumKey );
}

QString Schema::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Schema::properties>::type> ( enumValue ) );
}
