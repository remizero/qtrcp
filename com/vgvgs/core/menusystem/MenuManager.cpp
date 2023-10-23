#include "MenuManager.h"


using namespace NAMESPACE_LIBRARY_CORE;


MenuManager::MenuManager ( QObject *parent ) : QObject ( parent ) {

  this->menuBarType = MenuBarType::Standard;
  this->createMenuBar ( this->menuBarType );
}

void MenuManager::createMenuBar ( MenuBarType menuBarType ) {

  this->menuBarType = menuBarType;
  switch ( menuBarType ) {

    case MenuBarType::Stripe :

      this->prueba = QVariant::fromValue ( new QMenuBar () );
      break;

    default :

      this->prueba = QVariant::fromValue ( new QMenuBar () );
      break;
  }
}

void MenuManager::addActionToMenu ( const QString &menuName, QAction *action ) {

  QMenu *menu = this->findMenuByName ( menuName );
  if ( menu ) {

    menu->addAction ( action );
    switch ( this->menuBarType ) {

      case MenuBarType::Stripe :

//        StripeMenuBar *menuAux = qvariant_cast<StripeMenuBar *> ( this->prueba );
//        menuAux->addMenu ( menu );
        break;

      default :

        QMenuBar *menuAux = qvariant_cast<QMenuBar *> ( this->prueba );
        menuAux->addMenu ( menu );
        break;
    }
  }
}

void MenuManager::addActionToToolbar ( const QString &toolbarName, QAction *action ) {

  QToolBar *toolbar = this->findToolbarByName ( toolbarName );
  if ( toolbar ) {

    toolbar->addAction ( action );
  }
}

QMenu *MenuManager::findMenuByName ( const QString &menuName ) {

  return menus.value ( menuName, nullptr );
}

QToolBar *MenuManager::findToolbarByName ( const QString &toolbarName ) {

  return toolbars.value ( toolbarName, nullptr );
}
