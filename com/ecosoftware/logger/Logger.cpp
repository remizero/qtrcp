#include "Logger.h"
#include <QDebug>

using namespace Com::Ecosoftware::Logger;

Logger::Logger () {

  logger = this;
  // TODO: Cambiar la dirección del log de errores
  // TODO: Verificar el tamaño del archivo que no sea mayor a 1MB, sino,
  // renombrar con el nombre del archivo y la fecha del día, y crear uno nuevo
  // y comenzar a escribir en el archivo nuevo.
  this->logFile.reset ( new QFile ( App::AppPaths::getInstance ().getApplicationLogPath () + "logger.log" ) );
  // Open the file logging
  this->logFile.data ()->open ( QFile::Append | QFile::Text );

#if QT_VERSION >= QT_VERSION_CHECK ( 5, 0, 0 )
  //#pragma comment(lib, "logger.lib")
  qInstallMessageHandler ( logger->loggerOutput );
#else
  qInstallMsgHandler ( logger->loggerOutput );
#endif
}

void Logger::loggerOutput ( QtMsgType type, const QMessageLogContext &context, const QString &msg ) {

  // Open stream file writes
  QTextStream out ( logger->logFile.data () );
  // Write the date of recording
  out << QDateTime::currentDateTime ().toString ( "yyyy-MM-dd hh:mm:ss.zzz " );
  // By type determine to what level belongs message
  switch ( type ) {

    case QtInfoMsg:     out << "INF "; break;
    case QtDebugMsg:    out << "DBG "; break;
    case QtWarningMsg:  out << "WRN "; break;
    case QtCriticalMsg: out << "CRT "; break;
    case QtFatalMsg:    out << "FTL "; break;
  }
  // Write to the output category of the message and the message itself
  out << context.category << ": " << __FILE__ << " " << __LINE__ << " " << Q_FUNC_INFO << " " << msg << endl;
  out.flush ();    // Clear the buffered data , ,
}
