#include "SystemTrayIcon.h"
#include <QDebug>

using namespace Com::Ecosoftware::Window::Components::SystemTrayIcon;

SystemTrayIcon::SystemTrayIcon ( QObject *parent ) : QSystemTrayIcon ( parent ) {

  this->parent = ( QMainWindow * ) parent;
  this->setIcon ( QIcon ( Com::Ecosoftware::App::AppPaths::getInstance ().getApplicationImagePath () + Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "systemtrayicon/systrayicon" ).toString () ) );
  this->setToolTip ( Com::Ecosoftware::App::AppInit::getInstance ().getSettings ()->value ( "systemtrayicon/systrayicon" ).toString () );
  this->createActions ();
  this->createMenu ();
}

void SystemTrayIcon::createActions () {

  this->minimizeAction = new QAction ( tr ( "Mi&nimize" ), this );
  connect ( this->minimizeAction, &QAction::triggered, this->parent, &QMainWindow::hide );
  this->maximizeAction = new QAction ( tr ( "Ma&ximize" ), this );
  connect ( this->maximizeAction, &QAction::triggered, this->parent, &QMainWindow::showMaximized );
  this->restoreAction = new QAction ( tr ( "&Restore" ), this );
  connect ( this->restoreAction, &QAction::triggered, this->parent, &QMainWindow::showNormal );
  this->quitAction = new QAction ( tr ( "&Quit" ), this );
  connect ( this->quitAction, &QAction::triggered, qApp, &QCoreApplication::quit );
}

void SystemTrayIcon::createMenu () {

  this->trayIconMenu = new QMenu ( this->parent );
  this->trayIconMenu->addAction ( minimizeAction );
  this->trayIconMenu->addAction ( maximizeAction );
  this->trayIconMenu->addAction ( restoreAction );
  this->trayIconMenu->addSeparator ();
  this->trayIconMenu->addAction ( quitAction );
  this->setContextMenu ( this->trayIconMenu );
}

void SystemTrayIcon::setVisible ( bool visible ) {

  this->minimizeAction->setEnabled ( visible );
  this->maximizeAction->setEnabled ( !this->parent->isMaximized () );
  this->restoreAction->setEnabled ( this->parent->isMaximized() || !visible );
}
