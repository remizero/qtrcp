#ifndef LOGGER_H
#define LOGGER_H

// Librerías Internas
#include "logger_global.h"

// Librerías Externas
#include "macros_global.h"
#include "AppInfo.h"
#include "AppPaths.h"
#include "creational/Singleton.h"

// Librerías de terceros
// third-party Library
#include "SmtpMime"

// Librerías Qt
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QIODeviceBase>
#include <QMessageBox>
#include <QMessageLogContext>
#include <QScopedPointer>
#include <QString>
#include <QStringLiteral>
#include <QTextStream>

// Librerías C++


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_LOGGER {

      class LOGGERSHARED_EXPORT Logger : public NAMESPACE_LIBRARY_PATTERNIFY::Singleton<Logger> {

        public :

          enum LogOutput {

            Standard,
            File
          };

          virtual ~Logger ();

          void exception ();
          void init ( Logger::LogOutput output = File, QString outputFormat = STR(FILE_OUTPUT_QT_MESSAGE_PATTERN) );
          void sendEmail ();

        private :
                           QString filePath;
                           QString outputFormat;
           QIODeviceBase::OpenMode openMode;
                 Logger::LogOutput output;
          QScopedPointer < QFile > logFile;

          Logger ();
          friend class NAMESPACE_LIBRARY_PATTERNIFY::Singleton<Logger>;
          void checkAndRotateLog ();
          void close ();
          void configMessagePatternOutput ();
          void handleMessage ( QtMsgType type, const QMessageLogContext &context, const QString &msg );
          void installMessageHandler ();
          static void messageHandler ( QtMsgType type, const QMessageLogContext &context, const QString &msg );
          void open ();
          void writeToLog ( const QString &message );
      };
    }
  }
}

#endif // LOGGER_H
