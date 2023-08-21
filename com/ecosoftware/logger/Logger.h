#ifndef LOGGER_H
#define LOGGER_H

// Librerías Internas
#include "logger_global.h"

// Librerías Externas
#include "macros_global.h"

// Librerías Externas
#include "AppPaths.h"

// Librerías Qt
#include <QDateTime>
#include <QFile>
#include <QLoggingCategory>
#include <QMessageLogContext>
#include <QScopedPointer>
#include <QString>
#include <QTextStream>

Q_DECLARE_LOGGING_CATEGORY ( logDebug )
Q_DECLARE_LOGGING_CATEGORY ( logInfo )
Q_DECLARE_LOGGING_CATEGORY ( logWarning )
Q_DECLARE_LOGGING_CATEGORY ( logCritical )

/**
 * TODO
 * ESTE ES MUY IMPORTANTE, EMPEZAR POR AHÍ
 * https://stackoverflow.com/questions/4661883/qt-c-error-handling
 * https://stackoverflow.com/questions/576185/logging-best-practices?rq=1
 * https://jpnaude.github.io/Qtilities/page_logging.html
 * https://evileg.com/en/post/154/
 * https://github.com/Speedy37/QtLog/blob/master/qtlog.h
 *
 * ESTE ESTÁ INTERESANTE PARA MOSTRAR LA TRAZA DEL ERROR
 * https://woboq.com/blog/nice-debug-output-with-qt.html
 *
 * OTROS EJEMPLOS A REVISAR, PUEDE HABER ALGO IMPORTANTE QUE SE PUEDA AÑADIR AL
 * SISTEMA DE LOGGER
 * http://doc.qt.io/qt-5/qmessagelogcontext.html
 * http://doc.qt.io/qt-5/qtglobal.html#QtMessageHandler-typedef
 * http://doc.qt.io/qt-5/qtglobal.html#qInstallMessageHandler
 * http://doc.qt.io/qt-5/qmessagelogger.html
 * http://doc.qt.io/qt-5/qloggingcategory.html#Q_DECLARE_LOGGING_CATEGORY
 * http://doc.qt.io/qt-5/qloggingcategory.html#Q_LOGGING_CATEGORY
 * http://www.kdab.com/wp-content/uploads/stories/slides/Day2/KaiKoehne_Qt%20Logging%20Framework%2016_9_0.pdf
 * https://github.com/dept2/CuteLogger/blob/master/include/Logger.h
 */


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_LOGGER {

      class LOGGERSHARED_EXPORT Logger {

        public :
          Logger ( QFile logFile );

          static void loggerOutput ( QtMsgType type, const QMessageLogContext &context, const QString &msg );

        private :
          QScopedPointer < QFile > logFile;
          static Logger *logger;
      };
    }
  }
}

#endif // LOGGER_H
