#include "ElementAbs.h"

using namespace Com::Ecosoftware::Engines::Xsd;

ElementAbs::ElementAbs () {}

ElementAbs::ElementAbs ( const ElementAbs & ) : QObject () {}

ElementAbs::~ElementAbs () {}

int ElementAbs::indexOfEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( ElementAbs::staticMetaObject, "elements", enumKey );
}

bool ElementAbs::inEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( ElementAbs::staticMetaObject, "elements", enumKey );
}

QString ElementAbs::enumToString ( ElementAbs::elements enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < ElementAbs::elements > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<ElementAbs::elements>::type> ( enumValue ) );
}
