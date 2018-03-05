#include "XsdDialog.h"
#include <QDebug>

using namespace Com::Ecosoftware::Engines::Xsd;

XsdDialog::XsdDialog ( XsdElement *xsdElement, QWidget *parent ) {

  this->xsdElement = xsdElement;
  this->formDialog = new QDialog ( parent );
  this->formDialog->setObjectName ( "settingsDialog" );
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
  this->cargarDatos ( doc.firstChild (), xsdFormCreator->getForm () );

}

QDialog *XsdDialog::getFormDialog () const {

  return this->formDialog;
}

QWidget *XsdDialog::getWidget ( QString objectName, QWidget *widget ) {

  QWidget *objectReturn = nullptr;
  QObjectList childrenList = widget->children ();
  const int childrensCount = childrenList.count ();
  for ( int i = 0; i < childrensCount; i++ ) {

    if ( childrenList.at ( i )->objectName ().compare ( objectName ) == 0  ) {

      objectReturn = ( QWidget * ) childrenList.at ( i );
      break;

    } else {

      objectReturn = this->getWidget ( objectName, ( QWidget * ) childrenList.at ( i ) );
      if ( objectReturn != nullptr ) {

        break;
      }
    }
  }
  return objectReturn;
}

void XsdDialog::cargarDatos ( QDomNode element, QWidget *widget ) {

  if ( !element.isNull () ) {

    if ( element.toText ().isNull () ) {

      if ( element.hasChildNodes () ) {

        this->cargarDatos ( element.firstChild (), widget );
      }
    } else {

      if ( !element.parentNode ().toElement ().isNull () && ( element.nodeType () == QDomNode::TextNode ) ) {

        qDebug () << "El padre no es un elemento nulo #######################################";
        qDebug () << "Nombre del elemento padre:  " << element.parentNode ().toElement ().nodeName ();
        qDebug () << "Nombre del elemento padre:  " << this->getNameInput ( element.parentNode ().toElement () );
        qDebug () << "Valor del elemento padre:  " << element.parentNode ().toElement ().text ();
        QWidget *inputWidget = this->getWidget ( this->getNameInput ( element.parentNode ().toElement () ) + "Input", widget );
        XsdElement *xsdElementType = nullptr;
        if ( inputWidget != nullptr ) {

          qDebug () << "Nombre del inputWidget:  " << inputWidget->objectName ();
          xsdElementType = this->getXsdElement ( element.parentNode ().toElement (), this->xsdElement );
          if ( xsdElementType != nullptr ) {

            TypeProperty *objTypeProperty = ( TypeProperty * ) xsdElementType->getProperty ( "TypeProperty" );
            switch ( objTypeProperty->getValue () ) {

              case TypeAbs::ANYURI:


                break;

              case TypeAbs::BASE64BINARY:


                break;

              case TypeAbs::BOOLEAN:


                break;

              case TypeAbs::BYTE:


                break;

              case TypeAbs::DATETIMESTAMP:


                break;

              case TypeAbs::DATETIME:


                break;

              case TypeAbs::DATE:


                break;

              case TypeAbs::DAYTIMEDURATION:


                break;

              case TypeAbs::DECIMAL:


                break;

              case TypeAbs::DOUBLE:


                break;

              case TypeAbs::DURATION:


                break;

              case TypeAbs::ENTITIES:


                break;

              case TypeAbs::ENTITY:


                break;

              case TypeAbs::FLOAT:


                break;

              case TypeAbs::GDAY:


                break;

              case TypeAbs::GMONTHDAY:


                break;

              case TypeAbs::GMONTH:


                break;

              case TypeAbs::GYEARMONTH:


                break;

              case TypeAbs::GYEAR:


                break;

              case TypeAbs::HEXBINARY: {

                //this->createHexbinaryInput ( widget, xsdElement );
                QLineEdit *lineEditHex = ( QLineEdit * ) inputWidget;
                lineEditHex->setText ( element.parentNode ().toElement ().text () );
                break;
              }
              case TypeAbs::IDREFS:



                break;

              case TypeAbs::IDREF:


                break;

              case TypeAbs::ID:


                break;

              case TypeAbs::INTEGER: {

                //this->createIntegerInput ( widget, xsdElement );
                QSpinBox *spinBoxInteger = ( QSpinBox * ) inputWidget;
                spinBoxInteger->setValue ( element.parentNode ().toElement ().text ().toInt () );
                break;
              }
              case TypeAbs::INT: {

                //this->createIntegerInput ( widget, xsdElement );
                QSpinBox *spinBox = ( QSpinBox * ) inputWidget;
                spinBox->setValue ( element.parentNode ().toElement ().text ().toInt () );
                break;
              }
              case TypeAbs::LANGUAGE:


                break;

              case TypeAbs::LONG:


                break;

              case TypeAbs::NAME:


                break;

              case TypeAbs::NCNAME:


                break;

              case TypeAbs::NEGATIVEINTEGER:


                break;

              case TypeAbs::NMTOKENS:


                break;

              case TypeAbs::NMTOKEN:


                break;

              case TypeAbs::NONNEGATIVEINTEGER:


                break;

              case TypeAbs::NONPOSITIVEINTEGER:


                break;

              case TypeAbs::NORMALIZEDSTRING:


                break;

              case TypeAbs::NOTATION:


                break;

              case TypeAbs::POSITIVEINTEGER:


                break;

              case TypeAbs::QNAME:


                break;

              case TypeAbs::SHORT:


                break;

              case TypeAbs::STRING: {

                //this->createStringInput ( widget, xsdElement );
                QLineEdit *lineEdit = ( QLineEdit * ) inputWidget;
                lineEdit->setText ( element.parentNode ().toElement ().text () );
                break;
              }
              case TypeAbs::TIME:


                break;

              case TypeAbs::TOKEN:


                break;

              case TypeAbs::UNSIGNEDBYTE:


                break;

              case TypeAbs::UNSIGNEDINT:


                break;

              case TypeAbs::UNSIGNEDLONG:


                break;

              case TypeAbs::UNSIGNEDSHORT:


                break;

              case TypeAbs::YEARMONTHDURATION:


                break;

              default:

                break;
            }
          }

        } else {


        }



        //inputWidget

      } else {

        qDebug () << "El padre es un elemento nulo ##########################################";
      }

      // TODO: Aquí buscar el objeto
      //this->getWidget ( this->getNameInput ( element ), widget );
      //qDebug () << this->getNameInput ( element );
      //qDebug () << "No está vacío";
    }
    this->cargarDatos ( element.nextSibling (), widget );
  }
}

QString XsdDialog::getNameInput ( QDomElement element ) {

  QString nameInputAux = "";
  if ( !element.parentNode ().isNull () ) {

    nameInputAux = this->getNameInput ( element.parentNode ().toElement () );
  }
  return nameInputAux + element.nodeName ();
}

XsdElement *XsdDialog::getXsdElement ( QDomElement element, XsdElement *xsdElement ) const {

  XsdElement *xsdElementReturn = nullptr;
  if ( ( ( NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue ().compare ( element.nodeName () ) == 0 ) {

    xsdElementReturn = xsdElement;

  } else {

    const int xsdElementCount = xsdElement->getElementsList ().count ();
    if ( xsdElementCount > 0 ) {

      for ( int i = 0; i < xsdElementCount; i++ ) {

        xsdElementReturn = this->getXsdElement ( element, xsdElement->getElementsList ().at ( i ) );
        if ( xsdElementReturn != nullptr ) {

          break;
        }
      }
    }
  }
  return xsdElementReturn;
}
