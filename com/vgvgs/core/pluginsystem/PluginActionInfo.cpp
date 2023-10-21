#include "PluginActionInfo.h"


using namespace NAMESPACE_LIBRARY_CORE;


bool PluginActionInfo::getAutoRepeat () const {

  return this->autoRepeat;
}

void PluginActionInfo::setAutoRepeat ( bool newAutoRepeat ) {

  this->autoRepeat = newAutoRepeat;
}

bool PluginActionInfo::getCheckable () const {

  return this->checkable;
}

void PluginActionInfo::setCheckable ( bool newCheckable ) {

  this->checkable = newCheckable;
}

bool PluginActionInfo::getChecked () const {

  return this->checked;
}

void PluginActionInfo::setChecked ( bool newChecked ) {

  this->checked = newChecked;
}

const QString &PluginActionInfo::getDescription () const {

  return this->description;
}

void PluginActionInfo::setDescription ( const QString &newDescription ) {

  this->description = newDescription;
}

bool PluginActionInfo::getEnabled () const {

  return this->enabled;
}

void PluginActionInfo::setEnabled ( bool newEnabled ) {

  this->enabled = newEnabled;
}

const QFont &PluginActionInfo::getFont () const {

  return this->font;
}

void PluginActionInfo::setFont ( const QFont &newFont ) {

  this->font = newFont;
}

const QIcon &PluginActionInfo::getIcon () const {

  return this->icon;
}

void PluginActionInfo::setIcon ( const QIcon &newIcon ) {

  this->icon = newIcon;
}

const QString &PluginActionInfo::getIconText () const {

  return this->iconText;
}

void PluginActionInfo::setIconText ( const QString &newIconText ) {

  this->iconText = newIconText;
}

bool PluginActionInfo::getIconVisibleInMenu () const {

  return this->iconVisibleInMenu;
}

void PluginActionInfo::setIconVisibleInMenu ( bool newIconVisibleInMenu ) {

  this->iconVisibleInMenu = newIconVisibleInMenu;
}

const QList<PluginActionLocationInfo *> &PluginActionInfo::getLocation () const {

  return this->location;
}

void PluginActionInfo::setLocation ( PluginActionLocationInfo *newLocation ) {

  this->location.append ( newLocation );
}

const QString &PluginActionInfo::getMenu () const {

  return this->menu;
}

void PluginActionInfo::setMenu ( const QString &newMenu ) {

  this->menu = newMenu;
}

const QAction::MenuRole &PluginActionInfo::getMenuRole () const {

  return this->menuRole;
}

void PluginActionInfo::setMenuRole ( const QString &newMenuRole ) {

  if ( newMenuRole == "NoRole" ) {

    this->menuRole = QAction::NoRole;

  } else if ( newMenuRole == "TextHeuristicRole" ) {

    this->menuRole = QAction::TextHeuristicRole;

  } else if ( newMenuRole == "ApplicationSpecificRole" ) {

    this->menuRole = QAction::ApplicationSpecificRole;

  } else if ( newMenuRole == "AboutQtRole" ) {

    this->menuRole = QAction::AboutQtRole;

  } else if ( newMenuRole == "AboutRole" ) {

    this->menuRole = QAction::AboutRole;

  } else if ( newMenuRole == "PreferencesRole" ) {

    this->menuRole = QAction::PreferencesRole;

  } else if ( newMenuRole == "QuitRole" ) {

    this->menuRole = QAction::QuitRole;
  }
}

const QString &PluginActionInfo::getName () const {

  return this->name;
}

void PluginActionInfo::setName ( const QString &newName ) {

  this->name = newName;
}

const QAction::Priority &PluginActionInfo::getPriority () const {

  return this->priority;
}

void PluginActionInfo::setPriority ( const QString &newPriority ) {

  if ( newPriority == "LowPriority" ) {

    this->priority = QAction::LowPriority;

  } else if ( newPriority == "NormalPriority" ) {

    this->priority = QAction::NormalPriority;

  } else if ( newPriority == "HighPriority" ) {

    this->priority = QAction::HighPriority;
  }
}

const QKeySequence &PluginActionInfo::getShortcut () const {

  return this->shortcut;
}

void PluginActionInfo::setShortcut ( const QKeySequence &newShortcut ) {

  this->shortcut = newShortcut;
}

Qt::ShortcutContext PluginActionInfo::getShortcutContext () const {

  return this->shortcutContext;
}

void PluginActionInfo::setShortcutContext ( const QString &newShortcutContext ) {

  if ( newShortcutContext == "WidgetShortcut" ) {

    this->shortcutContext = Qt::WidgetShortcut;

  } else if ( newShortcutContext == "WidgetWithChildrenShortcut" ) {

    this->shortcutContext = Qt::WidgetWithChildrenShortcut;

  } else if ( newShortcutContext == "WindowShortcut" ) {

    this->shortcutContext = Qt::WindowShortcut;

  } else if ( newShortcutContext == "ApplicationShortcut" ) {

    this->shortcutContext = Qt::ApplicationShortcut;
  }
}

bool PluginActionInfo::getShortcutVisibleInContextMenu () const {

  return this->shortcutVisibleInContextMenu;
}

void PluginActionInfo::setShortcutVisibleInContextMenu ( bool newShortcutVisibleInContextMenu ) {

  this->shortcutVisibleInContextMenu = newShortcutVisibleInContextMenu;
}

const QString &PluginActionInfo::getSlot () const {

  return this->slot;
}

void PluginActionInfo::setSlot ( const QString &newSlot ) {

  this->slot = newSlot;
}

const QString &PluginActionInfo::getStatusTip () const {

  return this->statusTip;
}

void PluginActionInfo::setStatusTip ( const QString &newStatusTip ) {

  this->statusTip = newStatusTip;
}

const QString &PluginActionInfo::getText () const {

  return this->text;
}

void PluginActionInfo::setText ( const QString &newText ) {

  this->text = newText;
}

const QString &PluginActionInfo::getToolTip () const {

  return this->toolTip;
}

void PluginActionInfo::setToolTip ( const QString &newToolTip ) {

  this->toolTip = newToolTip;
}

bool PluginActionInfo::getVisible () const {

  return this->visible;
}

void PluginActionInfo::setVisible ( bool newVisible ) {

  this->visible = newVisible;
}

const QString &PluginActionInfo::getWhatsThis () const {

  return this->whatsThis;
}

void PluginActionInfo::setWhatsThis ( const QString &newWhatsThis ) {

  this->whatsThis = newWhatsThis;
}
