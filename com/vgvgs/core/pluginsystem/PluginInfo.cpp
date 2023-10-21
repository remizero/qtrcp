#include "PluginInfo.h"


using namespace NAMESPACE_LIBRARY_CORE;


const QString &PluginInfo::getNameToShow () const {

  return this->nameToShow;
}

void PluginInfo::setNameToShow ( const QString &newNameToShow ) {

  this->nameToShow = newNameToShow;
}

const QString &PluginInfo::getLogicalName () const {

  return this->logicalName;
}

void PluginInfo::setLogicalName ( const QString &newLogicalName ) {

  this->logicalName = newLogicalName;
}

const QString &PluginInfo::getVersion () const {

  return this->version;
}

void PluginInfo::setVersion ( const QString &newVersion ) {

  this->version = newVersion;
}

const QString &PluginInfo::getCompatVersion () const {

  return this->compatVersion;
}

void PluginInfo::setCompatVersion ( const QString &newCompatVersion ) {

  this->compatVersion = newCompatVersion;
}

const QString &PluginInfo::getVendor () const {

  return this->vendor;
}

void PluginInfo::setVendor ( const QString &newVendor ) {

  this->vendor = newVendor;
}

const QString &PluginInfo::getCopyright () const {

  return this->copyright;
}

void PluginInfo::setCopyright ( const QString &newCopyright ) {

  this->copyright = newCopyright;
}

const QString &PluginInfo::getLicense () const {

  return this->license;
}

void PluginInfo::setLicense ( const QString &newLicense ) {

  this->license = newLicense;
}

const QString &PluginInfo::getDescription () const {

  return this->description;
}

void PluginInfo::setDescription ( const QString &newDescription ) {

  this->description = newDescription;
}

const QString &PluginInfo::getUrl () const {

  return this->url;
}

void PluginInfo::setUrl ( const QString &newUrl ) {

  this->url = newUrl;
}

const QList<PluginDependenciesInfo *> &PluginInfo::getLibDependencies () const {

  return this->libDependencies;
}

void PluginInfo::setLibDependencies ( PluginDependenciesInfo *newLibDependency ) {

  this->libDependencies.append ( newLibDependency );
}

const QList<PluginDependenciesInfo *> &PluginInfo::getPluginDependencies () const {

  return this->pluginDependencies;
}

void PluginInfo::setPluginDependencies ( PluginDependenciesInfo *newPluginDependencies ) {

  this->pluginDependencies.append ( newPluginDependencies );
}

const QList<PluginActionInfo *> &PluginInfo::getActions () const {

  return this->actions;
}

void PluginInfo::setActions ( PluginActionInfo *newActions ) {

  this->actions.append ( newActions );
}
