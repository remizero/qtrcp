#ifndef PLUGINACTIONINFO_H
#define PLUGINACTIONINFO_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "PluginActionLocationInfo.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QAction>
#include <QDebug>
#include <QFont>
#include <QIcon>
#include <QKeySequence>
#include <QString>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT PluginActionInfo {

        public :

          bool getAutoRepeat () const;
          void setAutoRepeat ( bool newAutoRepeat );

          bool getCheckable () const;
          void setCheckable ( bool newCheckable );

          bool getChecked () const;
          void setChecked ( bool newChecked );

          const QString &getDescription () const;
          void setDescription ( const QString &newDescription );

          bool getEnabled () const;
          void setEnabled ( bool newEnabled );

          const QFont &getFont () const;
          void setFont ( const QFont &newFont );

          const QIcon &getIcon () const;
          void setIcon ( const QIcon &newIcon );

          const QString &getIconText () const;
          void setIconText ( const QString &newIconText );

          bool getIconVisibleInMenu () const;
          void setIconVisibleInMenu ( bool newIconVisibleInMenu );

          const QList<PluginActionLocationInfo *> &getLocation () const;
          void setLocation ( PluginActionLocationInfo *newLocation );

          const QString &getMenu () const;
          void setMenu ( const QString &newMenu );

          const QAction::MenuRole &getMenuRole () const;
          void setMenuRole ( const QString &newMenuRole );

          const QString &getName () const;
          void setName ( const QString &newName );

          const QAction::Priority &getPriority () const;
          void setPriority ( const QString &newPriority );

          const QKeySequence &getShortcut () const;
          void setShortcut ( const QKeySequence &newShortcut );

          Qt::ShortcutContext getShortcutContext () const;
          void setShortcutContext ( const QString &newShortcutContext );

          bool getShortcutVisibleInContextMenu () const;
          void setShortcutVisibleInContextMenu ( bool newShortcutVisibleInContextMenu );

          const QString &getStatusTip () const;
          void setStatusTip ( const QString &newStatusTip );

          const QString &getText () const;
          void setText ( const QString &newText );

          const QString &getToolTip () const;
          void setToolTip ( const QString &newToolTip );

          bool getVisible () const;
          void setVisible ( bool newVisible );

          const QString &getWhatsThis () const;
          void setWhatsThis ( const QString &newWhatsThis );

          const QString &getSlot() const;
          void setSlot(const QString &newSlot);

        private :
                                          bool autoRepeat;
                                          bool checkable;
                                          bool checked;
                                       QString description;
                                          bool enabled;
                                         QFont font;
                                         QIcon icon;
                                       QString iconText;
                                          bool iconVisibleInMenu;
          QList < PluginActionLocationInfo * > location;
                                       QString menu;
                             QAction::MenuRole menuRole;
                                       QString name;
                             QAction::Priority priority;
                                  QKeySequence shortcut;
                           Qt::ShortcutContext shortcutContext;
                                          bool shortcutVisibleInContextMenu;
                                       QString slot;
                                       QString statusTip;
                                       QString text;
                                       QString toolTip;
                                          bool visible;
                                       QString whatsThis;
        };
    }
  }
}

#endif // PLUGINACTIONINFO_H
