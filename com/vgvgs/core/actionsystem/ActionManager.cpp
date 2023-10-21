#include "ActionManager.h"


using namespace NAMESPACE_LIBRARY_CORE;


ActionManager::ActionManager () {}

void ActionManager::createStaticActions () {}

void ActionManager::createDynamicActions ( PluginInterface *plugin ) {

  int countActions = plugin->getPluginInfo ()->getActions ().count ();
  for ( int i = 0; i < countActions; i++ ) {

    PluginActionInfo *actionInfo = plugin->getPluginInfo ()->getActions ().at ( i );
    QAction *action = new QAction ( plugin );
    action->setAutoRepeat ( actionInfo->getAutoRepeat () );
    action->setCheckable ( actionInfo->getCheckable () );
    action->setChecked ( actionInfo->getChecked () );
    action->setEnabled ( actionInfo->getEnabled () );
    action->setFont ( actionInfo->getFont () );
    action->setIcon ( actionInfo->getIcon () );
    action->setIconText ( actionInfo->getIconText () );
    action->setIconVisibleInMenu ( actionInfo->getIconVisibleInMenu () );
    action->setMenuRole ( actionInfo->getMenuRole () );
    action->setPriority ( actionInfo->getPriority () );
    action->setShortcut ( actionInfo->getShortcut () );
    action->setShortcutContext ( actionInfo->getShortcutContext () );
    action->setShortcutVisibleInContextMenu ( actionInfo->getShortcutVisibleInContextMenu () );
    action->setText ( actionInfo->getText () );
    action->setToolTip ( actionInfo->getToolTip () );
    action->setVisible ( actionInfo->getVisible () );
    action->setWhatsThis ( actionInfo->getWhatsThis () );
    connect ( action, SIGNAL ( triggered() ), plugin, actionInfo->getSlot ().toUtf8 () );
    this->setActionList ( action );
  }
}

const QList<QAction *> &ActionManager::getActionList () const {

  return this->actionList;
}

void ActionManager::setActionList ( QAction *newAction ) {

  this->actionList.append ( newAction );
}
