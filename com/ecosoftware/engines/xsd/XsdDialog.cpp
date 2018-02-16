#include "XsdDialog.h"
#include <QDebug>

using namespace Com::Ecosoftware::Engines::Xsd;

XsdDialog::XsdDialog ( XsdElement *xsdElement, QWidget *parent ) {

  this->formDialog = new QDialog ( parent );
  this->formDialog->setMinimumSize ( 800, 600 );
  this->formDialog->setWindowTitle ( ( ( NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
  QVBoxLayout *formDialogLayout = new QVBoxLayout ( this->formDialog );
  this->formDialog->setLayout ( formDialogLayout );
  QDialogButtonBox *buttonBox = new QDialogButtonBox ( this->formDialog );
  buttonBox->setStandardButtons ( QDialogButtonBox::Ok | QDialogButtonBox::Apply | QDialogButtonBox::Cancel );
  XsdFormCreator *xsdFormCreator = new XsdFormCreator ();
  xsdFormCreator->createForm ( xsdElement, this->formDialog );
  formDialogLayout->addWidget ( xsdFormCreator->getForm () );
  formDialogLayout->addWidget ( buttonBox );
  this->formDialog->connect ( buttonBox, SIGNAL ( rejected () ), this->formDialog, SLOT ( reject () ) );
}

QDialog *XsdDialog::getFormDialog () const {

  return this->formDialog;
}
