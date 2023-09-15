#include "DefaultOpenContent.h"

using namespace NAMESPACE_LIBRARY_XSD;

DefaultOpenContent::DefaultOpenContent () {}

DefaultOpenContent::DefaultOpenContent ( const DefaultOpenContent & ) : ElementAbs () {}

DefaultOpenContent::~DefaultOpenContent () {}

int DefaultOpenContent::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( DefaultOpenContent::staticMetaObject, "content", enumKey );
}

bool DefaultOpenContent::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( DefaultOpenContent::staticMetaObject, "content", enumKey );
}

QString DefaultOpenContent::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<DefaultOpenContent::content>::type> ( enumValue ) );
}

int DefaultOpenContent::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( DefaultOpenContent::staticMetaObject, "properties", enumKey );
}

bool DefaultOpenContent::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( DefaultOpenContent::staticMetaObject, "properties", enumKey );
}

QString DefaultOpenContent::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<DefaultOpenContent::properties>::type> ( enumValue ) );
}
