#include "AppInfo.h"


using namespace NAMESPACE_LIBRARY_APP;


AppInfo::AppInfo ( QObject *parent ) : QObject ( parent ) {}

QString AppInfo::getApplicationDisplayName () {

  return NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/applicationdisplayname" ).toString ();
}

QString AppInfo::getApplicationName () {

  return NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/applicationname" ).toString ();
}

QString AppInfo::getApplicationVersion () {

  return NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/applicationversion" ).toString ();
}

QString AppInfo::getOrganizationDomain () {

  return NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/organizationdomain" ).toString ();
}

QString AppInfo::getOrganizationName () {

  return NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/organizationname" ).toString ();
}
