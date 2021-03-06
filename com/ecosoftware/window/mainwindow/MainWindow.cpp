#include "MainWindow.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QEvent>
#include <QResizeEvent>

#include <QDebug>

using namespace Com::Ecosoftware::Window::MainWindow;

MainWindow::MainWindow ( QSettings *settings, QWidget *parent ) : QMainWindow ( parent ) {

  this->init ( settings );
  /**
   * PREGUNTAR PRIMERO SI ESTÁ MAXIMIZADA O EN PANTALLA COMPLETA, SI NO EJECUTAR
   * ESTE MÉTODO
   */
  this->centerWindow ();
  this->showMaximized ();
}

MainWindow::~MainWindow () {}

void MainWindow::centerWindow () {

  this->adjustSize ();
  this->move ( QApplication::desktop ()->screen ()->rect ().center () - this->rect ().center () );
}

void MainWindow::changeEvent ( QEvent *event ) {

  this->mainWindowEvents->changeEvent ( event );
}

void MainWindow::closeEvent ( QCloseEvent *event ) {

  this->mainWindowEvents->closeEvent ( event );
}

void MainWindow::createMenuBar () {

  this->setMenuBar ( new Components::Menubar::MenuBar ( this ) );
}

void MainWindow::createStatusBar () {

  this->setStatusBar ( new Components::Statusbar::StatusBar ( this ) );
}

void MainWindow::createSysTrayIcon () {

  if ( QSystemTrayIcon::isSystemTrayAvailable () ) {

    if ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "systemtrayicon/showsystemtrayicon" ).toBool () ) {

      this->sysTrayIcon = new Components::SystemTrayIcon::SystemTrayIcon ( this );
      connect ( this->sysTrayIcon, SIGNAL ( activated ( QSystemTrayIcon::ActivationReason ) ), this, SLOT ( iconActivated ( QSystemTrayIcon::ActivationReason ) ) );
      this->sysTrayIcon->show ();
    }
  }
}

MainWindowSlots *MainWindow::getMainWindowSlots () const {

  return this->mainWindowSlots;
}

QSystemTrayIcon *MainWindow::getSysTrayIcon () const {

  return this->sysTrayIcon;
}

void MainWindow::iconActivated ( QSystemTrayIcon::ActivationReason reason ) {

  switch ( reason ) {

    case QSystemTrayIcon::Context:
      break;

    case QSystemTrayIcon::DoubleClick:
      break;

    case QSystemTrayIcon::MiddleClick:
      break;

    case QSystemTrayIcon::Trigger:

      if ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "app/showsystemtrayicon" ).toBool () ) {

        if ( !this->isVisible () ) {

          this->show ();

        } else {

          this->hide ();
        }
      }
      break;

    default:
      break;
  }
}

void MainWindow::init ( QSettings *settings ) {

  //int const MainWindow::EXIT_CODE_REBOOT = -123456789;
  this->mainWindowEvents = new MainWindowEvents ( this );
  this->mainWindowSignals = new MainWindowSignals ( this );
  this->mainWindowSlots = new MainWindowSlots ( this );

  this->setWindowTitle ( settings->value ( "app/applicationdisplayname" ).toString () );
  this->setWindowIcon ( QIcon ( App::AppPaths::getInstance ().getApplicationImagePath () + settings->value ( "app/iconimage" ).toString () ) );
  this->setMinimunWindowSize ();
  /*
  this->setTabPosition ( Qt::BottomDockWidgetArea, QTabWidget::North );
  this->setDockOptions ( QMainWindow::ForceTabbedDocks );
  this->setCorner ( Qt::BottomLeftCorner, Qt::LeftDockWidgetArea );
  this->setCorner ( Qt::BottomRightCorner, Qt::RightDockWidgetArea );
  */
  /**
   * Revisar
   * http://qt-project.org/wiki/Saving_Window_Size_State
   * https://www.google.co.ve/webhp?sourceid=chrome-instant&ion=1&espv=2&es_th=1&ie=UTF-8#q=save+windowstate+in+qt
   */
  this->createMenuBar ();
  this->createStatusBar ();
  this->createSysTrayIcon ();

  //this->setStyleSheet ( "QMainWindow { background : rgb( 64, 66, 68 ) }" );
}

void MainWindow::loadSettins () {}

void MainWindow::resizeEvent ( QResizeEvent *event ) {

  this->mainWindowEvents->resizeEvent ( event );
  /**
   * Para probar si se puede evitar que el centralWidget no se expanda :)
   * http://stackoverflow.com/questions/2722939/c-resize-a-docked-qt-qdockwidget-programmatically?rq=1
   * http://qt-project.org/doc/qt-4.8/widgets-scribble.html
   * http://stackoverflow.com/questions/25505041/resize-qmainwindow-to-fit-qdockwidget-size
   * http://stackoverflow.com/questions/26286646/create-a-qdockwidget-that-resizes-to-its-contents
   */
  //QMessageBox::information ( this, "Información", "La ventana a cambiado de tamaño" );
  //QDockWidget::resizeEvent ( event );
  //emit sizeChanged ( event->size () );
  /**
   * Borrar esto cuando se tenga definido el código de este método.
   */
  //event->accept ();
}

void MainWindow::saveSettings () {}

void MainWindow::setMinimunWindowSize () {

  /**
   * Que hacer si las dimenciones de la pantalla son menores a 800x600?
   */
  if ( QApplication::desktop ()->screen ()->width () > 800 ) {

    this->setMinimumWidth ( 800 );

  } else {


  }

  if ( QApplication::desktop ()->screen ()->height () > 600 ) {

    this->setMinimumHeight ( 600 );

  } else {


  }
}

void MainWindow::setVisible ( bool visible ) {

  /*this->minimizeAction->setEnabled ( visible );
  this->maximizeAction->setEnabled ( !isMaximized () );
  this->restoreAction->setEnabled ( isMaximized() || !visible );*/
  this->sysTrayIcon->setVisible ( visible );
  QMainWindow::setVisible ( visible );
}
