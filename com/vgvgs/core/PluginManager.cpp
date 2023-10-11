#include "PluginManager.h"

using namespace NAMESPACE_LIBRARY_CORE;

PluginManager::PluginManager ( QObject *parent )
  : QObject ( parent )
{}

void PluginManager::initialize () {
    // Puedes realizar cualquier inicialización necesaria aquí
//  QDir path = QDir ( qApp->applicationDirPath () );
//  path.cdUp ();
//  path.cd ( "plugins" );
//  foreach ( QFileInfo info, path.entryInfoList ( QDir::Files | QDir::NoDotAndDotDot ) ) {

//    this→scan ( info.absoluteFilePath () );
//  }
//  foreach ( QFileInfo info, path.entryInfoList ( QDir::Files | QDir::NoDotAndDotDot ) ) {

//    this->load ( info.absoluteFilePath () );
//  }
}

void PluginManager::uninitialize () {
    // Puedes realizar cualquier limpieza necesaria aquí
}

void PluginManager::scan ( const QString &path ) {

  QDir dir ( path );
#ifdef Q_OS_WIN
  dir.setNameFilters ( QStringList () << "*.dll" );
#elif defined(Q_OS_LINUX)
  dir.setNameFilters ( QStringList () << "*.so" );
#elif defined(Q_OS_MACOS)
  dir.setNameFilters ( QStringList () << "*.dylib" );
#else
        // Agrega extensiones para otras plataformas si es necesario
#endif
  QStringList pluginFiles = dir.entryList ( QDir::Files );

  foreach ( const QString &fileName, pluginFiles ) {

    load ( path + "/" + fileName );
  }
}

void PluginManager::load ( const QString &path ) {

  if ( !QLibrary::isLibrary ( path ) ) {

    return;
  }
  if ( !d->check ( path ) ) {

    return;
  }
  // QPluginLoader *loader = new QPluginLoader ( path );
//  if ( tstPlugin *plugin = qobject_cast<tstPlugin *> ( loader->instance () ) ) {

//    d->loaders.insert ( path, loader );
//  } else {

//    delete loader;
//  }


//  QPluginLoader loader ( path );
//  QObject *plugin = loader.instance ();

//  if ( plugin ) {

//    // El plugin se cargó con éxito
//    qDebug () << "Plugin loaded: " << loader.metaData ().value ( "MetaDataKey" ).toVariant ();
//    // Puedes realizar cualquier operación adicional con el plugin aquí
//    loadedPlugins.append ( plugin );

//  } else {

//    qDebug () << "Failed to load plugin: " << loader.errorString ();
//  }
}

void PluginManager::unload ( const QString &path ) {

  for ( int i = 0; i < loadedPlugins.size (); ++i ) {

    if ( loadedPlugins [ i ]->objectName () == path ) {

      loadedPlugins [ i ]->deleteLater ();
      loadedPlugins.removeAt ( i );
      qDebug () << "Plugin unloaded: " << path;
      return;
    }
  }
  qDebug () << "Plugin not found for unloading: " << path;
}

QStringList PluginManager::plugins () const {

  QStringList pluginNames;
  foreach ( QObject *plugin, loadedPlugins ) {

    pluginNames << plugin->objectName ();
  }
  return pluginNames;
}
