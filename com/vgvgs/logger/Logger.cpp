#include "Logger.h"

const qint64 MAX_LOG_SIZE = 1024 * 1024;  // 1MB


using namespace NAMESPACE_LIBRARY_LOGGER;


Logger::Logger () {

  this->openMode = QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text;
  this->filePath = NAMESPACE_LIBRARY_APP::AppPaths::getInstance ().getApplicationLogPath () + NAMESPACE_LIBRARY_APP::AppInfo::getApplicationName () + "_error.log";
  this->init ();
}

Logger::~Logger () {

  if ( logFile.data ()->isOpen () ) {

    logFile.data ()->close ();
    logFile.reset ( nullptr );
  }
}

void Logger::checkAndRotateLog () {

  if ( this->logFile.data ()->size () >= MAX_LOG_SIZE ) {

    QDateTime currentDateTime = QDateTime::currentDateTime ();
    QFileInfo fileInfo ( this->logFile.data ()->filesystemFileName () );
    QString newFileName = NAMESPACE_LIBRARY_APP::AppPaths::getInstance ().getApplicationLogPath () + fileInfo.baseName () + "_" + currentDateTime.toString ( "yyyy-MM-dd hh:mm:ss" ) + ".log";
    this->logFile.data ()->rename ( newFileName );
    this->logFile.data ()->close ();
    this->logFile.reset ( nullptr );
    this->open ();
  }
}

void Logger::close () {

  if ( this->logFile.data ()->isOpen () ) {

    this->logFile.data ()->close ();
    this->logFile.reset ( nullptr );
  }
  qInstallMessageHandler ( 0 );
}

void Logger::configMessagePatternOutput () {

  if ( this->outputFormat.isEmpty () ) {

    #ifdef QT_DEBUG
      this->outputFormat = QStringLiteral ( STR(DEFAULT_QT_MESSAGE_PATTERN) );
    #else
      this->outputFormat = QStringLiteral ( STR(FILE_OUTPUT_QT_MESSAGE_PATTERN) );
    #endif

  }
  qSetMessagePattern ( this->outputFormat );
}

void Logger::exception ( const NAMESPACE_LIBRARY_CORE::Exception &exception ) {

  QString customFormat = qFormatLogMessage ( QtCriticalMsg, QMessageLogContext (
                                               exception.getFile ().toUtf8 ().constData (),
                                               exception.getLine (),
                                               exception.getFunction ().toUtf8 ().constData (),
                                               "Critical" ), exception.what () );
  // this->sendEmail ( customFormat ); // TODO descomentar esta línea.
  QMessageBox::critical ( nullptr, "Mensaje de Error Crítico del Sistema.", customFormat );
  this->writeToLog ( customFormat + "\n" );
}

void Logger::handleMessage ( QtMsgType type, const QMessageLogContext &context, const QString &msg ) {

  QString msgFormat = qFormatLogMessage ( type, context, msg );

  switch ( type ) {

    case QtDebugMsg :

      // QMessageBox::warning ( nullptr, "Mensaje de Depuración del Sistema.", msgFormat );
      break;

    case QtInfoMsg :

      // QMessageBox::information ( nullptr, "Mensaje de Información del Sistema.", msgFormat );
      break;

    case QtWarningMsg :

      // QMessageBox::warning ( nullptr, "Mensaje de Advertencia del Sistema.", msgFormat );
      break;

    case QtCriticalMsg :

      // this->sendEmail ( msgFormat ); // TODO descomentar esta línea.
      QMessageBox::critical ( nullptr, "Mensaje de Acción Crítica del Sistema.", msgFormat );
      break;

    case QtFatalMsg :

      // this->sendEmail ( msgFormat ); // TODO descomentar esta línea.
      QMessageBox::critical ( nullptr, "Mensaje Fatal del Sistema.", msgFormat );
      break;
  }
  this->writeToLog ( msgFormat + "\n" );
}

void Logger::init ( Logger::LogOutput output, QString outputFormat ) {

  this->output = output;
  this->outputFormat = outputFormat;
  switch ( this->output ) {

    case Standard :

      this->close ();
      break;

    case File :

      this->configMessagePatternOutput ();
      this->open ();
      this->installMessageHandler ();
      break;
  }
}

void Logger::installMessageHandler () {

  #ifdef QT_DEBUG
    // Modo de depuración, no hagas nada especial.
    qInstallMessageHandler ( Logger::messageHandler ); // TODO Esto se debe quitar.
  #else
    // Modo de lanzamiento, instala un manejador de mensajes personalizado.
    qInstallMessageHandler ( Logger::messageHandler );
  #endif
}

void Logger::messageHandler ( QtMsgType type, const QMessageLogContext &context, const QString &msg ) {

  Logger::getInstance ()->handleMessage ( type, context, msg );
}

void Logger::open () {

  if ( QFile::exists ( this->filePath ) ) {

    if ( this->logFile.isNull () ) {

      this->logFile.reset ( new QFile ( this->filePath ) );
      if ( this->logFile.data ()->open ( this->openMode ) ) {

        this->checkAndRotateLog ();

      } else {

        QString message ( "No se pudo cargar el archivo de registro de la aplicación." );
        qWarning () << message;
        QMessageBox::warning ( nullptr, "Error de registro", message );
      }
    } else {

      if ( !this->logFile.data ()->isOpen () ) {

        if ( this->logFile.data ()->open ( this->openMode ) ) {

          this->checkAndRotateLog ();

        } else {

          QString message ( "No se pudo abrir el archivo de registro de la aplicación." );
          qWarning () << message;
          QMessageBox::warning ( nullptr, "Error de registro", message );
        }
      } else {

        this->checkAndRotateLog ();
      }
    }
  } else {

    if ( this->logFile.isNull () ) {

      this->logFile.reset ( new QFile ( this->filePath ) );
      if ( this->logFile.data ()->open ( this->openMode ) ) {

        this->checkAndRotateLog ();

      } else {

        QString message ( "No se pudo crear un nuevo archivo de registro de la aplicación." );
        qWarning () << message;
        QMessageBox::warning ( nullptr, "Error de registro", message );
      }
    } else {

      if ( !this->logFile.data ()->isOpen () ) {

        if ( this->logFile.data ()->open ( this->openMode ) ) {

          this->checkAndRotateLog ();

        } else {

          QString message ( "No se pudo abrir el archivo de registro de la aplicación." );
          qWarning () << message;
          QMessageBox::warning ( nullptr, "Error de registro", message );
        }
      } else {

        this->checkAndRotateLog ();
      }
    }
  }
}

void Logger::sendEmail ( QString message ) {

  MimeMessage mimeMessage;

  EmailAddress sender (
    NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "logger/sender" ).toString (),
    NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "logger/sendername" ).toString () );
  mimeMessage.setSender ( sender );

  EmailAddress to (
    NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "logger/addressee" ).toString (),
    NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "logger/addresseename" ).toString () );
  mimeMessage.addRecipient ( to );

  mimeMessage.setSubject ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "logger/subject" ).toString () );

  // Now add some text to the email.
  // First we create a MimeText object.
  MimeText *text = new MimeText ( message + "\n" );

  // Now add it to the mail
  mimeMessage.addPart ( text );

  // Now we can send the mail
  SmtpClient smtp (
    NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "logger/smtpserver" ).toString (),
    NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "logger/port" ).toInt (),
    SmtpClient::TlsConnection );

  smtp.connectToHost ();
  if ( !smtp.waitForReadyConnected () ) {

    qDebug () << "Failed to connect to host!";
  }

  smtp.login (
    NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "logger/user" ).toString (),
    NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "logger/password" ).toString () );
  if ( !smtp.waitForAuthenticated () ) {

    qDebug () << "Failed to login!";
  }

  smtp.sendMail ( mimeMessage );
  if ( !smtp.waitForMailSent () ) {

    qDebug () << "Failed to send mail!";
  }

  smtp.quit();
}

void Logger::writeToLog ( const QString &message ) {

  QMutexLocker lock ( this->mutex );
  if ( this->logFile.data ()->isOpen () ) {

    QTextStream textStream ( this->logFile.data () );
    QString logMessage = QString ( "%1 - %2" ).arg ( message, "\n" );
    textStream << logMessage;
    this->checkAndRotateLog ();

  } else {

    QMessageBox::critical ( nullptr, "Error de registro", "No se pudo abrir el archivo de registro." );
  }
}
