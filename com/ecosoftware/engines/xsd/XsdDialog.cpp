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

  //this->cargarDatos ( doc.firstChildElement (), this->formDialog->children () );
  this->cargarDatos ( doc.firstChildElement (), this->formDialog );
  //this->cargarDatos ( doc.firstChildElement (), xsdFormCreator->getForm () );

}

QDialog *XsdDialog::getFormDialog () const {

  return this->formDialog;
}

void XsdDialog::cargarDatos ( QDomElement element, QObject *object ) {

  if ( !element.isNull () ) {

    QObjectList childrenList = object->children ();
    const int childrensCount = childrenList.count ();
    for ( int i = 0; i < childrensCount; i++ ) {

      if ( element.nodeValue ().isEmpty () ) {

        if ( childrenList.at ( i )->objectName ().compare ( element.nodeName () + "Input" ) == 0 ) {

          this->cargarDatos ( element.firstChildElement (), childrenList.at ( i ) );
        }
      } else {

        qDebug () << "El valor del elemento es vacío";
        // TODO: Asignar el valor al input, pero como conseguir el tipo de dato
        // para saber cual es el tipo de input a castear, es decir, QLineEdit, QSpinBox, QComboBox
        qDebug () << "Nombre del elemento " << element.nodeName () + "Input";
        qDebug () << "Nombre del objeto   " << childrenList.at ( i )->objectName ();
      }
    }
  } else {

    qDebug () << "El elemento es nulo";
  }
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

void XsdDialog::cargarDatos ( QDomElement element, QWidget *widget ) {

  if ( !element.isNull () ) {

    qDebug () << "El elemento no es nulo";
    QObjectList childrenList = widget->children ();
    const int childrensCount = childrenList.count ();
    for ( int i = 0; i < childrensCount; i++ ) {

      qDebug () << "Entró al for";
      if ( element.nodeValue ().isEmpty () ) {

        qDebug () << "El valor del elemento no es vacío";
        qDebug () << "El nombre del objeto " << childrenList.at ( i )->objectName ();
        qDebug () << "El nombre del elemento " << this->getNameInput ( element ) + "Input";
        if ( childrenList.at ( i )->objectName ().compare ( this->getNameInput ( element ) + "Input" ) == 0 ) {

          this->cargarDatos ( element.firstChildElement (), ( QWidget * ) childrenList.at ( i ) );
        } else {

          qDebug () << "El nombre del elemento no coincide con el nombre del objeto";
        }
      } else {

        qDebug () << "El valor del elemento es vacío";
        // TODO: Asignar el valor al input, pero como conseguir el tipo de dato
        // para saber cual es el tipo de input a castear, es decir, QLineEdit, QSpinBox, QComboBox
        qDebug () << "Nombre del elemento " << element.nodeName () + "Input";
        qDebug () << "Nombre del objeto   " << childrenList.at ( i )->objectName ();
      }
    }
  } else {

    qDebug () << "El elemento es nulo";
  }

  /*if ( !element.isNull () ) {

    if ( widget->objectName ().compare ( this->getNameInput ( element ) + "Input" ) == 0 ) {

      qDebug () << "Si lo conseguí ;p";
      if ( element.nodeValue ().isEmpty () ) {

        //this->cargarDatos ( element.firstChildElement (),  );



        //this->cargarDatos ( element.nextSiblingElement () );

      } else {

        // TODO: Asignar el valor al input, pero como conseguir el tipo de dato
        // para saber cual es el tipo de input a castear.
      }

    } else {

      qDebug () << "No lo conseguí :(";
    }
  }*/



  /*QList<QWidget*> widgets = widget->findChildren<QWidget*> ();
  foreach ( QWidget *widgetChild, widgets ) {

    if ( !widgetChild->objectName ().isEmpty () ) {

      //if ( element. )
      qDebug () << "Nombre del objeto: " << widgetChild->objectName ();
      qDebug () << "Nombre del elemento: " << element.nodeName ();
      //this->cargarDatos ( widgetChild );
      if ( widgetChild->objectName ().compare ( this->getNameInput ( element ) + "Input" ) == 0 ) {

        qDebug () << "Si lo conseguí ;p";
        qDebug () << element.nodeName ();
        qDebug () << this->getNameInput ( element );
        this->cargarDatos ( element.firstChildElement (), widgetChild );
        //break;
      } else {

        element = element.nextSiblingElement ();
      }
    }
  }*/
}

QString XsdDialog::getNameInput ( QDomElement element ) {

  QString nameInputAux = "";
  if ( !element.parentNode ().isNull () ) {

    nameInputAux = this->getNameInput ( element.parentNode ().toElement () );
  }
  return nameInputAux + element.nodeName ();
}
