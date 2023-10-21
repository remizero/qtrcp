#include "PluginAbs.h"


using namespace NAMESPACE_LIBRARY_CORE;


void PluginAbs::initializeMetadata ( PluginInfo *pluginInfo, QJsonObject object ) {

  pluginInfo->setNameToShow ( object.value ( "nameToShow" ).toString () );
  pluginInfo->setLogicalName ( object.value ( "logicalName" ).toString () );
  pluginInfo->setVersion ( object.value ( "version" ).toString () );
  pluginInfo->setCompatVersion ( object.value ( "compatVersion" ).toString () );
  pluginInfo->setVendor ( object.value ( "vendor" ).toString () );
  pluginInfo->setCopyright ( object.value ( "copyright" ).toString () );
  pluginInfo->setLicense ( object.value ( "license" ).toString () );
  pluginInfo->setDescription ( object.value ( "description" ).toString () );
  pluginInfo->setUrl ( object.value ( "url" ).toString () );

  if ( object.value ( "lib_dependencies" ).isArray () ) {

    QJsonArray newArray = object.value ( "lib_dependencies" ).toArray ();
    for ( int i = 0; i < newArray.size (); ++i ) {

      QJsonValue jsonValue = newArray.at ( i );
      if ( jsonValue.isObject () ) {

        QJsonObject index = jsonValue.toObject ();
        PluginDependenciesInfo *libDependencies = new PluginDependenciesInfo ();
        libDependencies->setName ( index.value ( "name" ).toString () );
        libDependencies->setVersion ( index.value ( "version" ).toString () );
        pluginInfo->setLibDependencies ( libDependencies );
      }
    }
  }

  if ( object.value ( "lib_dependencies" ).isArray () ) {

    QJsonArray newArray = object.value ( "lib_dependencies" ).toArray ();
    for ( int i = 0; i < newArray.size (); ++i ) {

      QJsonValue jsonValue = newArray.at ( i );
      if ( jsonValue.isObject () ) {

        QJsonObject index = jsonValue.toObject ();
        PluginDependenciesInfo *pluginDependencies = new PluginDependenciesInfo ();
        pluginDependencies->setName ( index.value ( "name" ).toString () );
        pluginDependencies->setVersion ( index.value ( "version" ).toString () );
        pluginInfo->setPluginDependencies ( pluginDependencies );
      }
    }
  }

  if ( object.value ( "actions" ).isArray () ) {

    QJsonArray newArray = object.value ( "actions" ).toArray ();
    for ( int i = 0; i < newArray.size (); ++i ) {

      QJsonValue jsonValue = newArray.at ( i );
      if ( jsonValue.isObject () ) {

        QJsonObject index = jsonValue.toObject ();
        PluginActionInfo *action = new PluginActionInfo ();
        action->setName ( index.value ( "name" ).toString () );
        action->setDescription ( index.value ( "description" ).toString () );
        action->setMenu ( index.value ( "menu" ).toString () );
        action->setSlot ( index.value ( "slot" ).toString () );

        if ( object.value ( "location" ).isArray () ) {

          QJsonArray locationArray = object.value ( "location" ).toArray ();
          PluginActionLocationInfo *location = new PluginActionLocationInfo ();
          for ( int j = 0; j < locationArray.size (); ++j ) {

            QJsonValue locationValue = locationArray.at ( j );
            if ( locationValue.isObject () ) {

              QJsonObject indexLocationArray = locationValue.toObject ();
              if ( indexLocationArray.contains ( "menu" ) ) {

                location->setMenu ( indexLocationArray.value ( "menu" ).toString () );

              } else if ( indexLocationArray.contains ( "toolbar" ) ) {

                location->setToolbar ( indexLocationArray.value ( "toolbar" ).toString () );

              } else if ( indexLocationArray.contains ( "contextual" ) ) {

                location->setContextual ( indexLocationArray.value ( "contextual" ).toString () );
              }
            }
          }
          action->setLocation ( location );
        }
        action->setAutoRepeat ( index.value ( "autoRepeat" ).toBool () );
        action->setCheckable ( index.value ( "checkable" ).toBool () );
        action->setChecked ( index.value ( "checked" ).toBool () );
        action->setEnabled ( index.value ( "enabled" ).toBool () );
        action->setFont ( QFont ( index.value ( "font" ).toString () ) );
        action->setIcon ( QIcon ( index.value ( "icon" ).toString () ) );
        action->setIconText ( index.value ( "iconText" ).toString () );
        action->setIconVisibleInMenu ( index.value ( "iconVisibleInMenu" ).toBool () );
        action->setMenuRole ( index.value ( "menuRole" ).toString () );
        action->setPriority ( index.value ( "priority" ).toString () );
        action->setShortcut ( QKeySequence ( index.value ( "shortcut" ).toString () ) );
        action->setShortcutContext ( index.value ( "shortcutContext" ).toString () );
        action->setShortcutVisibleInContextMenu ( index.value ( "shortcutVisibleInContextMenu" ).toBool () );
        action->setStatusTip ( index.value ( "statusTip" ).toString () );
        action->setText ( index.value ( "text" ).toString () );
        action->setToolTip ( index.value ( "toolTip" ).toString () );
        action->setVisible ( index.value ( "visible" ).toBool () );
        action->setWhatsThis ( index.value ( "whatsThis" ).toString () );
        pluginInfo->setActions ( action );
      }
    }
  }
}
