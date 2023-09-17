#include "SettingsAct.h"

using namespace NAMESPACE_LIBRARY_ACTONS;

SettingsAct::SettingsAct ( QString title , QWidget *parent ) : ActionAbs ( title, parent ) {

  this->setObjectName ( this->metaObject ()->className () );
  this->setIcon ( QIcon ( ":/images/application-exit.svg" ) );
  this->setShortcut ( QKeySequence::Preferences );
}

void SettingsAct::execAct () {

  NAMESPACE_LIBRARY_XSDFORM::XsdDialog *xsdDialog = new NAMESPACE_LIBRARY_XSDFORM::XsdDialog ( this->myParent );
  xsdDialog->getFormDialog ()->show ();
}
