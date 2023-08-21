#include "SysTrayIconMainWindow.h"

#include <QDebug>
#include <QDomDocument>
#include <QPlainTextEdit>

SysTrayIconMainWindow::SysTrayIconMainWindow ( QSettings *settings, QWidget *parent ) : Com::Vgvgs::Window::MainWindow::MainWindow ( settings, parent ) {

  Q_INIT_RESOURCE ( xsdresources );
  this->setCentralWidget ( new QPlainTextEdit ( this ) );

  /**
   * Initialize the tray icon, set the icon of a set of system icons,
   * As well as set a tooltip
   */
  /*this->sysTrayIcon = new QSystemTrayIcon ( this );
  this->sysTrayIcon->setIcon ( this->style ()->standardIcon ( QStyle::SP_ComputerIcon ) );
  // TODO: Aquí debe ir el nombre de la aplicación
  this->sysTrayIcon->setToolTip ( "Tray Program" "\n"
                       "Работа со сворачиванием программы трей");*/
  /* After that create a context menu of two items */
  /*QMenu * menu = new QMenu ( this );
  QAction * viewWindow = new QAction ( trUtf8 ( "Restore" ), this );
  QAction * quitAction = new QAction ( trUtf8 ( "Quit" ), this );*/

  /**
   * connect the signals clicks on menu items to by appropriate slots.
   * The first menu item expands the application from the tray,
   * And the second menu item terminates the application
   */
  /*connect ( viewWindow, SIGNAL ( triggered () ), this, SLOT ( show () ) );
  connect ( quitAction, SIGNAL ( triggered () ), this, SLOT ( close () ) );
  menu->addAction ( viewWindow);
  menu->addAction ( quitAction );*/

  /**
   * Set the context menu on the icon
   * And show the application icon in the system tray
   */
  /*sysTrayIcon->setContextMenu ( menu );
  sysTrayIcon->show ();*/

  /* Also connect clicking on the icon to the signal processor of this press
       * */
  /*connect ( sysTrayIcon, SIGNAL ( activated ( QSystemTrayIcon::ActivationReason ) ), this, SLOT ( iconActivated ( QSystemTrayIcon::ActivationReason ) ) );
  */
}

SysTrayIconMainWindow::~SysTrayIconMainWindow () {}

/**
 * The method that handles the closing event of the application window
 */
/*void SysTrayIconMainWindow::closeEvent ( QCloseEvent * event ) {

  /**
   * If the window is visible, and the checkbox is checked, then the completion of the application
   * Ignored, and the window simply hides that accompanied
   * The corresponding pop-up message
   */
  /*if ( this->isVisible () && NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/showsystemtrayicon" ).toBool ()  ) {

    event->ignore ();
    this->hide ();
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon ( QSystemTrayIcon::Information );
    sysTrayIcon->showMessage ( "Tray Program",
                              trUtf8 ( "Приложение свернуто в трей. Для того чтобы, "
                                     "развернуть окно приложения, щелкните по иконке приложения в трее" ),
                              icon,
                              2000 );
  }
}*/

/**
 * The method that handles click on the application icon in the system tray
 */
/*void SysTrayIconMainWindow::iconActivated ( QSystemTrayIcon::ActivationReason reason ) {

  switch ( reason ) {

    case QSystemTrayIcon::Trigger:

      /**
       * The event is ignored if the checkbox is not checked
       */
      /*if ( NAMESPACE_LIBRARY_APP::AppInit::getInstance ().getSettings ()->value ( "app/showsystemtrayicon" ).toBool () ) {

        /**
         *  otherwise, if the window is visible, it is hidden,
         * Conversely, if hidden, it unfolds on the screen
         */
        /*if ( !this->isVisible () ) {

          this->show ();

        } else {

          this->hide ();
        }
      }
      break;

    default:
      break;
  }
}*/
