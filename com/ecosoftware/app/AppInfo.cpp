#include "AppInfo.h"

using namespace Com::Ecosoftware::App;

AppInfo::AppInfo ( QObject *parent ) : QObject ( parent ) {}

QString AppInfo::getApplicationDisplayName () {

  return Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/applicationdisplayname" ).toString ();
}

QString AppInfo::getApplicationName () {

  return Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/applicationname" ).toString ();
}

QString AppInfo::getApplicationVersion () {

  return Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/applicationversion" ).toString ();
}

QString AppInfo::getOrganizationDomain () {

  return Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/organizationdomain" ).toString ();
}

QString AppInfo::getOrganizationName () {

  return Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/organizationname" ).toString ();
}
