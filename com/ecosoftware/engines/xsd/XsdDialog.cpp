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



#ifdef Q_OS_WIN
  QFile file ( "C:/Users/fzaa/Documents/proyectos/Desarrollo/qt/qtrcp/com/ecosoftware/resources/xml/config.xml" );
#endif
#ifdef Q_OS_LINUX
  QFile file ( "/home/remizero/Proyectos/Desarrollo/Qt/qtrcp/com/ecosoftware/resources/xml/config.xml" );
#endif
  /*if ( !file.open ( QIODevice::ReadOnly | QIODevice::Text ) ) {

    return 0;
  }*/
  file.open ( QIODevice::ReadOnly | QIODevice::Text );

  QDomDocument doc;
  /*if ( !doc.setContent ( &file ) ) {

    file.close ();
    return 0;
  }*/
  doc.setContent ( &file );
  file.close ();

  this->cargarDatos ( doc.firstChildElement (), this->formDialog->children () );
}

QDialog *XsdDialog::getFormDialog () const {

  return this->formDialog;
}

void XsdDialog::cargarDatos ( QDomElement element, QObjectList objectList ) {

  if ( !element.isNull () ) {


    if ( element.nodeValue ().isEmpty () ) {

      //QObjectList childrens = objectList->children ();
      const int childrensCount = objectList.count ();
      for ( int i = 0; i < childrensCount; i++ ) {

        qDebug () << objectList.at ( i )->objectName ();
        if ( objectList.at ( i )->objectName ().compare ( element.nodeName () + "Input" ) == 0 ) {

          qDebug () << "Si lo conseguí ;p";
          qDebug () << element.nodeName ();
          this->cargarDatos ( element.firstChildElement (), objectList.at ( i )->children () );
          break;

        } else {

          qDebug () << "No lo consigo :(";
        }
      }
    } else {

      qDebug () << "El elemento tiene un valor";
      qDebug () << element.nodeValue ();
      // TODO: como obtener el tipo del objeto para castearlo y asignar el valor correctamente
      //this->cargarDatos ( element.nextSiblingElement (), childrens.at ( i ) );
    }
  } else {

    qDebug () << "El elemento es nulo";
  }
}
