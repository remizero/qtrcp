#include "XsdDialog.h"
#include <QDebug>

using namespace Com::Ecosoftware::Engines::Xsd;

XsdDialog::XsdDialog ( XsdElement *xsdElement, QWidget *parent ) {

  this->formDialog = new QDialog ( parent );
  this->formDialog->setMinimumSize ( 800, 600 );
  //this->formDialog->setWindowTitle ( xsdFormElement->getElementName () );
  QVBoxLayout *formDialogLayout = new QVBoxLayout ( this->formDialog );
  this->formDialog->setLayout ( formDialogLayout );
  QDialogButtonBox *buttonBox = new QDialogButtonBox ( this->formDialog );
  buttonBox->setStandardButtons ( QDialogButtonBox::Ok | QDialogButtonBox::Apply | QDialogButtonBox::Cancel );

  XsdFormCreator *xsdFormCreator = new XsdFormCreator ();
  qDebug () << "Creó el objeto xsdFormCreator";
  xsdFormCreator->createForm ( xsdElement, this->formDialog );
  qDebug () << "Creó el formulario xsdFormCreator";
  formDialogLayout->addWidget ( xsdFormCreator->getForm () );
  qDebug () << "Agregó objeto xsdFormCreator a la ventana de dialogo";


  formDialogLayout->addWidget ( buttonBox );
  this->formDialog->connect ( buttonBox, SIGNAL ( rejected () ), this->formDialog, SLOT ( reject () ) );
}

QDialog *XsdDialog::getFormDialog () const {

  return this->formDialog;
}
