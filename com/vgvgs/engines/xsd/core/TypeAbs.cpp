#include "TypeAbs.h"

using namespace NAMESPACE_LIBRARY_XSD;

TypeAbs::TypeAbs () {}

TypeAbs::TypeAbs ( const TypeAbs & ) : QObject () {}

TypeAbs::~TypeAbs () {}

int TypeAbs::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( TypeAbs::staticMetaObject, "types", enumKey );
}

bool TypeAbs::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( TypeAbs::staticMetaObject, "types", enumKey );
}

QString TypeAbs::enumToString ( TypeAbs::types enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < TypeAbs::types > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<TypeAbs::types>::type> ( enumValue ) );
}
