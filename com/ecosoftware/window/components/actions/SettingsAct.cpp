#include "SettingsAct.h"

using namespace Com::Ecosoftware::Window::Components::Actions;

SettingsAct::SettingsAct ( QString title , QWidget *parent ) : ActionAbs ( title, parent ) {

  this->setObjectName ( this->metaObject ()->className () );
  this->setIcon ( QIcon ( ":/images/application-exit.svg" ) );
  this->setShortcut ( QKeySequence::Preferences );
}

void SettingsAct::execAct () {

  Com::Ecosoftware::Engines::XsdForm::XsdDialog *xsdDialog = new Com::Ecosoftware::Engines::XsdForm::XsdDialog ( this->myParent );
  xsdDialog->getFormDialog ()->show ();
}
