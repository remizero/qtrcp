#include "Plugin_1.h"

using namespace NAMESPACE_LIBRARY_PLUGIN_1;

Q_PLUGIN_METADATA ( IID "com.vgvgs.Plugin_1" )

Plugin_1::Plugin_1 () {

  this->pluginInfo = new NAMESPACE_LIBRARY_CORE::PluginInfo ();
}

Plugin_1::~Plugin_1 () {}

void Plugin_1::initialize ( QJsonObject object ) {

  NAMESPACE_LIBRARY_CORE::PluginAbs::initializeMetadata ( this->pluginInfo, object );
  qDebug () << "PLUGIN INICIALIZADO";
}

void Plugin_1::finalize () {}

QAction Plugin_1::menuAction () const {}

QList<QAction *> Plugin_1::actions () const {}

NAMESPACE_LIBRARY_CORE::PluginInfo *Plugin_1::getPluginInfo () {

  return this->pluginInfo;
}
