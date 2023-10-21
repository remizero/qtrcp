#include "PluginActionLocationInfo.h"


using namespace NAMESPACE_LIBRARY_CORE;


const QString &PluginActionLocationInfo::getContextual () const {

  return this->contextual;
}

void PluginActionLocationInfo::setContextual ( const QString &newContextual ) {

  this->contextual = newContextual;
}

const QString &PluginActionLocationInfo::getMenu () const {

  return this->menu;
}

void PluginActionLocationInfo::setMenu ( const QString &newMenu ) {

  this->menu = newMenu;
}

const QString &PluginActionLocationInfo::getToolbar () const {

  return this->toolbar;
}

void PluginActionLocationInfo::setToolbar ( const QString &newToolbar ) {

  this->toolbar = newToolbar;
}
