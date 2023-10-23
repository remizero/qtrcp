#ifndef APPPATHS_H
#define APPPATHS_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "creational/Singleton.h"

// Librerías Qt
// Qt Libraries
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QString>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT AppPaths : public QObject, public NAMESPACE_LIBRARY_PATTERNIFY::Singleton<AppPaths> {

        public :
          QString getApplicationConfigPath () const;
          QString getApplicationDataPath () const;
          QString getApplicationImagePath () const;
          QString getApplicationLanguagePath () const;
          QString getApplicationLibrariesPath () const;
          QString getApplicationLogPath () const;
          QString getApplicationPath () const;
          QString getApplicationPathRoot () const;
          QString getApplicationPluginsPath () const;
          QString getApplicationResourcesPath () const;
          QString getApplicationTempPath () const;
          QString getApplicationWorkspacePath () const;
          QString getXsdPath () const;

        private :
          QString applicationConfigPath;
          QString applicationDataPath;
             QDir *applicationDirPath;
          QString applicationImagePath;
          QString applicationLanguagePath;
          QString applicationLibrariesPath;
          QString applicationLogPath;
          QString applicationPath;
          QString applicationPathRoot;
          QString applicationPluginsPath;
          QString applicationResourcesPath;
          QString applicationTempPath;
          QString applicationWorkspacePath;
          QString xsdPath;
          QString userConfigPath;
          QString userDataPath;
          QString userLanguagePath;
          QString userTempPath;
          AppPaths ( QObject *parent = nullptr );
          friend class NAMESPACE_LIBRARY_PATTERNIFY::Singleton<AppPaths>;
      };
    }
  }
}

#endif // APPPATHS_H
