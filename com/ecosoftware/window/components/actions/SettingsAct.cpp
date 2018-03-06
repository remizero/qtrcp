#include "SettingsAct.h"

using namespace Com::Ecosoftware::Window::Components::Actions;

SettingsAct::SettingsAct ( QString title , QWidget *parent ) : ActionAbs ( title, parent ) {

  this->setIcon ( QIcon ( ":/images/application-exit.svg" ) );
  this->setShortcut ( QKeySequence::Quit );
}

void SettingsAct::execAct () {

  /*
  Com::Ecosoftware::Engines::XsdEngine::XsdFormEngine *xsdFormEngine = new Com::Ecosoftware::Engines::XsdEngine::XsdFormEngine ();
  xsdFormEngine->loadXsd ( ":/xsdresources/xsd/config.xsd" );
  xsdFormEngine->parseXsd ();
  Com::Ecosoftware::Engines::XsdEngine::XsdFormCreator *xsdFormCreator = new Com::Ecosoftware::Engines::XsdEngine::XsdFormCreator ();
  xsdFormCreator->createForm ( xsdFormEngine->getXsdFormElementModel (), this->myParent );
  xsdFormCreator->showForm ();
  */
  Com::Ecosoftware::Engines::XsdForm::XsdDialog *xsdDialog = new Com::Ecosoftware::Engines::XsdForm::XsdDialog ( this->myParent );
  xsdDialog->createForm ();
  xsdDialog->getFormDialog ()->show ();


  /*Com::Ecosoftware::Engines::Xsd::XsdEngine *xsdEngine = new Com::Ecosoftware::Engines::Xsd::XsdEngine ();
  xsdEngine->load ( ":/xsdresources/xsd/config.xsd" );
  xsdEngine->parse ();
  xsdEngine->toFormDialog ( this->myParent )->show ();
  xsdEngine->listarElementos ();*/
}
