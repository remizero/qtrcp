#include "PluginData.h"


using namespace NAMESPACE_LIBRARY_CORE;


bool PluginData::check ( const QString &path ) {

  bool status = true;
  foreach ( QVariant item, this->dependencies.value ( path ) ) {

    QVariantMap mitem = item.toMap ();
    QVariant na_mitem = mitem.value ( "name" );
    QVariant ve_mitem = mitem.value ( "version" );
    QString key = this->names.key ( na_mitem );
    if ( !this->names.values ().contains ( na_mitem ) ) {

      qDebug () << Q_FUNC_INFO << " Missing dependency:" << na_mitem.toString () << "for plugin" << path;
      status = false;
      continue;
    }
    if ( this->versions.value ( key ) != ve_mitem ) {

      qDebug () << Q_FUNC_INFO << " Version mismatch:" << na_mitem.toString () << "version" << this->versions.value ( this->names.key ( na_mitem ) ).toString () << "but" << ve_mitem.toString () << "required for plugin" << path;
      status = false;
      continue;
    }
    if ( !this->check ( key ) ) {

      qDebug () << Q_FUNC_INFO << "Corrupted dependency:" << na_mitem.toString () << "for plugin" << path;
      status = false;
      continue;
    }
  }
  return status;
}
