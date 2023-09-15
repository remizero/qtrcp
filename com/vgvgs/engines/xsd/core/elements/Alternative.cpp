#include "Alternative.h"

using namespace NAMESPACE_LIBRARY_XSD;

Alternative::Alternative () {}

Alternative::Alternative ( const Alternative & ) : ElementAbs () {}

Alternative::~Alternative () {}

int Alternative::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Alternative::staticMetaObject, "content", enumKey );
}

bool Alternative::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Alternative::staticMetaObject, "content", enumKey );
}

QString Alternative::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Alternative::content>::type> ( enumValue ) );
}

int Alternative::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( Alternative::staticMetaObject, "properties", enumKey );
}

bool Alternative::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( Alternative::staticMetaObject, "properties", enumKey );
}

QString Alternative::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<Alternative::properties>::type> ( enumValue ) );
}
