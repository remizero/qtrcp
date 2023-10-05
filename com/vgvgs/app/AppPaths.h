#ifndef APPPATHS_H
#define APPPATHS_H

// Librerías Internas
// Internal Libraries
#include "app_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías Qt
// Qt Libraries
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QString>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_APP {

      class APPSHARED_EXPORT AppPaths {

        public :
          static AppPaths &getInstance ();

          QString getApplicationConfigPath () const;
          QString getApplicationDataPath () const;
          QString getApplicationImagePath () const;
          QString getApplicationLanguagePath () const;
          QString getApplicationLogPath () const;
          QString getApplicationPath () const;
          QString getApplicationPathRoot () const;
          QString getApplicationResourcesPath () const;
          QString getApplicationTempPath () const;
          QString getApplicationWorkspacePath () const;
          QString getXsdPath () const;

        private :
          AppPaths ();
          ~AppPaths ();
          static AppPaths instance;
                  QString applicationConfigPath;
                  QString applicationDataPath;
                     QDir *applicationDirPath;
                  QString applicationImagePath;
                  QString applicationLanguagePath;
                  QString applicationLogPath;
                  QString applicationPath;
                  QString applicationPathRoot;
                  QString applicationResourcesPath;
                  QString applicationTempPath;
                  QString applicationWorkspacePath;
                  QString xsdPath;
                  QString userConfigPath;
                  QString userDataPath;
                  QString userLanguagePath;
                  QString userTempPath;
      };
    }
  }
}

#endif // APPPATHS_H
