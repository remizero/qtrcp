#include "AppInfo.h"

using namespace Com::Ecosoftware::Engines::Xsd;

AppInfo::AppInfo () {}

AppInfo::AppInfo ( const AppInfo & ) : ElementAbs () {}

AppInfo::~AppInfo () {}

int AppInfo::indexOfContentEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( AppInfo::staticMetaObject, "content", enumKey );
}

bool AppInfo::inContentEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( AppInfo::staticMetaObject, "content", enumKey );
}

QString AppInfo::contentEnumToString ( content enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < content > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<AppInfo::content>::type> ( enumValue ) );
}

int AppInfo::indexOfPropertiesEnum ( QString enumKey ) {

  return Utils::Enumeration::indexOf ( AppInfo::staticMetaObject, "properties", enumKey );
}

bool AppInfo::inPropertiesEmun ( QString enumKey ) {

  return Utils::Enumeration::inEnum ( AppInfo::staticMetaObject, "properties", enumKey );
}

QString AppInfo::propertiesEnumToString ( properties enumValue ) {

  QMetaEnum metaEnum = QMetaEnum::fromType < properties > ();
  return metaEnum.valueToKey ( static_cast<typename std::underlying_type<AppInfo::properties>::type> ( enumValue ) );
}
