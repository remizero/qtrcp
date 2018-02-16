#ifndef APPPATHS_H
#define APPPATHS_H

// Librerías internas
#include "app_global.h"

// Librerías Qt
#include <QCoreApplication>
#include <QDir>
#include <QString>

namespace Com {

  namespace Ecosoftware {

    namespace App {

      class APPSHARED_EXPORT AppPaths {

        public:
          static AppPaths &getInstance ();

          QString getApplicationConfigPath () const;
          QString getApplicationDataPath () const;
          QString getApplicationImagePath () const;
          QString getApplicationLanguagePath () const;
          QString getApplicationPath () const;
          QString getApplicationPathRoot () const;
          QString getApplicationResourcesPath () const;
          QString getApplicationTempPath () const;
          QString getApplicationWorkspacePath () const;
          QString getXsdPath () const;

        private:
          AppPaths ();
          ~AppPaths ();
          static AppPaths instance;
                  QString applicationConfigPath;
                  QString applicationDataPath;
                     QDir *applicationDirPath;
                  QString applicationImagePath;
                  QString applicationLanguagePath;
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
