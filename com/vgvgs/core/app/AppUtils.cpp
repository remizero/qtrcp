#include "AppUtils.h"


using namespace NAMESPACE_LIBRARY_APP;


QString AppUtils::normalizePath ( QString path ) {

  #ifdef Q_OS_WIN
    path.replace ( "/", QDir::separator () );
  #endif
  #ifdef Q_OS_LINUX
    path.replace ( "\\", QDir::separator () );
  #endif
  return path;
}

QString AppUtils::pathTo ( QString path ) {

  path.resize ( path.size () - 1 );
  return path;
}

QString AppUtils::relativePath ( QString rootPath, QString path ) {
  
  path.remove ( rootPath );
  return path;
}
