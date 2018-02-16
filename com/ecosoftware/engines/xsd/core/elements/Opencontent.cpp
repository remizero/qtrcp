#include "Opencontent.h"

using namespace Com::Ecosoftware::Engines::Xsd;

Opencontent::Opencontent () {}

Opencontent::Opencontent ( const Opencontent & ) : ElementAbs () {}

Opencontent::~Opencontent () {}

int Opencontent::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Opencontent::staticMetaObject, "content", enumKey );
}

bool Opencontent::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Opencontent::staticMetaObject, "content", enumKey );
}

QString Opencontent::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Opencontent::content>::type> ( enumValue ) );
}

int Opencontent::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Opencontent::staticMetaObject, "properties", enumKey );
}

bool Opencontent::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Opencontent::staticMetaObject, "properties", enumKey );
}

QString Opencontent::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Opencontent::properties>::type> ( enumValue ) );
}
