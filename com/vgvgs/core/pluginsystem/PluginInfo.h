#ifndef PLUGININFO_H
#define PLUGININFO_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"
#include "PluginDependenciesInfo.h"
#include "PluginActionInfo.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QHash>
#include <QList>
#include <QString>
#include <QVariant>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT PluginInfo {

        public :

          const QString &getNameToShow () const;
          void setNameToShow ( const QString &newNameToShow );

          const QString &getLogicalName () const;
          void setLogicalName ( const QString &newLogicalName );

          const QString &getVersion () const;
          void setVersion ( const QString &newVersion );

          const QString &getCompatVersion () const;
          void setCompatVersion ( const QString &newCompatVersion );

          const QString &getVendor () const;
          void setVendor ( const QString &newVendor);

          const QString &getCopyright () const;
          void setCopyright ( const QString &newCopyright );

          const QString &getLicense () const;
          void setLicense ( const QString &newLicense );

          const QString &getDescription () const;
          void setDescription ( const QString &newDescription );

          const QString &getUrl () const;
          void setUrl ( const QString &newUrl );

          const QList<PluginDependenciesInfo *> &getLibDependencies () const;
          void setLibDependencies ( PluginDependenciesInfo *newLibDependency );

          const QList<PluginDependenciesInfo *> &getPluginDependencies () const;
          void setPluginDependencies ( PluginDependenciesInfo *newPluginDependencies );

          const QList<PluginActionInfo *> &getActions () const;
          void setActions ( PluginActionInfo *newActions );

        private :
          QString nameToShow;
          QString logicalName;
          QString version;
          QString compatVersion;
          QString vendor;
          QString copyright;
          QString license;
          QString description;
          QString url;
          QList < PluginDependenciesInfo * > libDependencies;
          QList < PluginDependenciesInfo * > pluginDependencies;
          QList < PluginActionInfo * > actions;
      };
    }
  }
}

#endif // PLUGININFO_H
