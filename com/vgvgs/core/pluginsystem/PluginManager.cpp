#include "PluginManager.h"


using namespace NAMESPACE_LIBRARY_CORE;


PluginManager::PluginManager ( QObject *parent ) : QObject ( parent ) {

  // this->d = new PluginData ();
}

void PluginManager::initialize () {

  QDir path = QDir ( NAMESPACE_LIBRARY_APP::AppPaths::getInstance ().getApplicationPluginsPath () );
  foreach ( QFileInfo info, path.entryInfoList ( QDir::Files | QDir::NoDotAndDotDot ) ) {

    this->load ( info.absoluteFilePath () );
  }
}

//void PluginManager::initializeStaticPlugins ( const QStringList &staticPlugins ) {

//  if ( !initialized ) {

//    for ( const QString &pluginName : staticPlugins ) {

//      Q_IMPORT_PLUGIN ( pluginName );
//    }
//    initialized = true;
//  }
//}

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
  QPluginLoader *loader = new QPluginLoader ( path );
  QJsonObject object { loader->metaData ().value ( "MetaData" ).toObject () };
  if ( this->validateLibraryDependencies ( object ) ) {

    if ( this->validatePluginDependencies ( object  ) ) {

      if ( PluginInterface *plugin = qobject_cast<PluginInterface *> ( loader->instance () ) ) {

        plugin->initialize ( object );
        ActionManager::getInstance ()->createDynamicActions ( plugin );

      } else {

        delete plugin;
      }
    }
  }
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

bool PluginManager::validateLibraryDependencies ( QJsonObject object ) {

  if ( object.value ( "lib_dependencies" ).isArray () ) {

    QJsonArray newArray = object.value ( "lib_dependencies" ).toArray ();
    for ( int i = 0; i < newArray.size (); ++i ) {

      QJsonValue jsonValue = newArray.at ( i );
      if ( jsonValue.isObject () ) {

        QJsonObject index = jsonValue.toObject ();
        QString libraryPath ( NAMESPACE_LIBRARY_APP::AppPaths::getInstance ().getApplicationLibrariesPath () + index.value ( "name" ).toString () );
        if ( QFile::exists ( libraryPath ) ) {

          if ( QLibrary::isLibrary ( libraryPath ) ) {

            QLibrary *library = new QLibrary ( libraryPath );

            if ( library->load () ) {

              if ( library->isLoaded () ) {

                typedef QString ( * Version ) ();
                Version versionLibrary = ( Version ) library->resolve ( "version" );
                QString version = versionLibrary ();
                if ( version == index.value ( "version" ).toString () ) {

                  qDebug () << "Versión de la librería: " << versionLibrary ();

                } else {

                  qDebug () << "No se pudo resolver la versión de la librería.";
                  library->unload ();
                  return false;
                }
                library->unload ();
              }
            } else {

              qDebug () << "No se pudo cargar la librería.";
              return false;
            }
          } else {

            qDebug () << "El archivo leido no es una librería.";
            return false;
          }
        } else {

          qDebug () << "La librería librería no existe o no se encuentra disponible.";
          return false;
        }
      } else {

        qDebug () << "Error al leer datos JSON del plugin.";
        return false;
      }
    }
  } else {

    qDebug () << "Error al leer datos JSON del plugin.";
    return false;
  }
  return true;
}

bool PluginManager::validatePluginDependencies ( QJsonObject object ) {

  if ( object.value ( "plugin_dependencies" ).isArray () ) {

    QJsonArray newArray = object.value ( "plugin_dependencies" ).toArray ();
    for ( int i = 0; i < newArray.size (); ++i ) {

      QJsonValue jsonValue = newArray.at ( i );
      if ( jsonValue.isObject () ) {

        QJsonObject index = jsonValue.toObject ();
        QString libraryPath ( NAMESPACE_LIBRARY_APP::AppPaths::getInstance ().getApplicationLibrariesPath () + index.value ( "name" ).toString () );
        if ( QFile::exists ( libraryPath ) ) {

          if ( QLibrary::isLibrary ( libraryPath ) ) {

            QLibrary *library = new QLibrary ( libraryPath );

            if ( library->load () ) {

              if ( library->isLoaded () ) {

                typedef QString ( * Version ) ();
                Version versionLibrary = ( Version ) library->resolve ( "version" );
                QString version = versionLibrary ();
                if ( version == index.value ( "version" ).toString () ) {

                  qDebug () << "Versión de la librería: " << versionLibrary ();

                } else {

                  qDebug () << "No se pudo resolver la versión de la librería.";
                  library->unload ();
                  return false;
                }
                library->unload ();
              }
            } else {

              qDebug () << "No se pudo cargar la librería.";
              return false;
            }
          } else {

            qDebug () << "El archivo leido no es una librería.";
            return false;
          }
        } else {

          qDebug () << "La librería librería no existe o no se encuentra disponible.";
          return false;
        }
      } else {

        qDebug () << "Error al leer datos JSON del plugin.";
        return false;
      }
    }
  } else {

    qDebug () << "Error al leer datos JSON del plugin.";
    return false;
  }
  return true;
}
