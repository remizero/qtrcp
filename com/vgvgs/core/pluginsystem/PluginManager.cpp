#include "PluginManager.h"

using namespace NAMESPACE_LIBRARY_CORE;

PluginManager::PluginManager ( QObject *parent )
  : QObject ( parent )
{}

void PluginManager::initialize () {
    // Puedes realizar cualquier inicialización necesaria aquí
  QDir path = QDir ( NAMESPACE_LIBRARY_APP::AppPaths::getInstance ().getApplicationPluginsPath () );
//  foreach ( QFileInfo info, path.entryInfoList ( QDir::Files | QDir::NoDotAndDotDot ) ) {

//    this->scan ( info.absoluteFilePath () );
//  }
  foreach ( QFileInfo info, path.entryInfoList ( QDir::Files | QDir::NoDotAndDotDot ) ) {

    this->load ( info.absoluteFilePath () );
  }
}

void PluginManager::initializeStaticPlugins (const QStringList &staticPlugins ) {

  if ( !initialized ) {

    for ( const QString &pluginName : staticPlugins ) {

      Q_IMPORT_PLUGIN ( pluginName );
    }
    initialized = true;
  }
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

    this->load ( path + "/" + fileName );
  }
}

void PluginManager::load ( const QString &path ) {

  if ( !QLibrary::isLibrary ( path ) ) {

    return;
  }
  if ( !this->d->check ( path ) ) {

    return;
  }
  QPluginLoader *loader = new QPluginLoader ( path );
  if ( PluginInterface *plugin = qobject_cast<PluginInterface *> ( loader->instance () ) ) {

    this->d->loaders.insert ( path, plugin );

  } else {

    delete plugin;
  }


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

  for ( int i = 0; i < this->loadedPlugins.size (); ++i ) {

    if ( this->loadedPlugins [ i ]->objectName () == path ) {

      this->loadedPlugins [ i ]->deleteLater ();
      this->loadedPlugins.removeAt ( i );
      qDebug () << "Plugin unloaded: " << path;
      return;
    }
  }
  qDebug () << "Plugin not found for unloading: " << path;
}

QStringList PluginManager::plugins () const {

  QStringList pluginNames;
  foreach ( QObject *plugin, this->loadedPlugins ) {

    pluginNames << plugin->objectName ();
  }
  return pluginNames;
}
