#include "XsdDialog.h"
#include <QDebug>

using namespace Com::Ecosoftware::Engines::XsdForm;

XsdDialog::XsdDialog ( QWidget *parent ) {

  Xsd::XsdEngine *xsdEngine = new Xsd::XsdEngine ();
  xsdEngine->load ( ":/xsdresources/xsd/config.xsd" );
  xsdEngine->parse ();
  this->xsdElement = xsdEngine->getXsdElementModel ();
  this->formDialog = new QDialog ( parent );
  this->formDialog->setObjectName ( "settingsDialog" );
  this->formDialog->setMinimumSize ( 800, 600 );
  this->formDialog->setWindowTitle ( ( ( Xsd::NameProperty * ) this->xsdElement->getProperty ( "NameProperty" ) )->getValue () );
  this->formDialogLayout = new QVBoxLayout ( this->formDialog );
  this->formDialog->setLayout ( this->formDialogLayout );
}

void XsdDialog::createForm () {

  this->buttonBox = new QDialogButtonBox ( this->formDialog );
  this->buttonBox->setStandardButtons ( QDialogButtonBox::Ok | QDialogButtonBox::Apply | QDialogButtonBox::Cancel );
  this->xsdFormCreator = new XsdFormCreator ();
  this->xsdFormCreator->createForm ( this->xsdElement, this->formDialog );
  this->formDialogLayout->addWidget ( this->xsdFormCreator->getForm () );
  this->formDialogLayout->addWidget ( this->buttonBox );
  this->formDialog->connect ( this->buttonBox, SIGNAL ( rejected () ), this->formDialog, SLOT ( reject () ) );

  //QDomDocument domDocument = this->loadXml ();
  QDomDocument domDocument = Utils::Xml::load ( App::AppPaths::getInstance ().getApplicationConfigPath () + "config.xml", true );
  this->loadData ( domDocument.firstChild (), this->xsdFormCreator->getForm () );
}

QDialog *XsdDialog::getFormDialog () const {

  return this->formDialog;
}

QString XsdDialog::getNameInput ( QDomElement element ) {

  QString nameInputAux = "";
  if ( !element.parentNode ().isNull () ) {

    nameInputAux = this->getNameInput ( element.parentNode ().toElement () );
  }
  return nameInputAux + element.nodeName ();
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

Com::Ecosoftware::Engines::Xsd::XsdElement *XsdDialog::getXsdElement ( QDomElement element, Com::Ecosoftware::Engines::Xsd::XsdElement *xsdElement ) {

  Xsd::XsdElement *xsdElementReturn = nullptr;
  if ( ( ( Xsd::NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue ().compare ( element.nodeName () ) == 0 ) {

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

void XsdDialog::loadData ( QDomNode element, QWidget *widget ) {

  if ( !element.isNull () ) {

    if ( element.toText ().isNull () ) {

      if ( element.hasChildNodes () ) {

        this->loadData ( element.firstChild (), widget );
      }
    } else {

      if ( !element.parentNode ().toElement ().isNull () && ( element.nodeType () == QDomNode::TextNode ) ) {

        QDomElement nodeElement = element.parentNode ().toElement ();
        QWidget *inputWidget = this->getWidget ( this->getNameInput ( nodeElement ) + "Input", widget );
        Xsd::XsdElement *xsdElementType = nullptr;
        if ( inputWidget != nullptr ) {

          xsdElementType = this->getXsdElement ( nodeElement, this->xsdElement );
          if ( xsdElementType != nullptr ) {

            Xsd::TypeProperty *objTypeProperty = ( Xsd::TypeProperty * ) xsdElementType->getProperty ( "TypeProperty" );
            switch ( objTypeProperty->getValue () ) {

              case Xsd::TypeAbs::ANYURI:


                break;

              case Xsd::TypeAbs::BASE64BINARY:


                break;

              case Xsd::TypeAbs::BOOLEAN:


                break;

              case Xsd::TypeAbs::BYTE:


                break;

              case Xsd::TypeAbs::DATETIMESTAMP:


                break;

              case Xsd::TypeAbs::DATETIME:


                break;

              case Xsd::TypeAbs::DATE:


                break;

              case Xsd::TypeAbs::DAYTIMEDURATION:


                break;

              case Xsd::TypeAbs::DECIMAL:


                break;

              case Xsd::TypeAbs::DOUBLE:


                break;

              case Xsd::TypeAbs::DURATION:


                break;

              case Xsd::TypeAbs::ENTITIES:


                break;

              case Xsd::TypeAbs::ENTITY:


                break;

              case Xsd::TypeAbs::FLOAT:


                break;

              case Xsd::TypeAbs::GDAY:


                break;

              case Xsd::TypeAbs::GMONTHDAY:


                break;

              case Xsd::TypeAbs::GMONTH:


                break;

              case Xsd::TypeAbs::GYEARMONTH:


                break;

              case Xsd::TypeAbs::GYEAR:


                break;

              case Xsd::TypeAbs::HEXBINARY: {

                QLineEdit *lineEditHex = ( QLineEdit * ) inputWidget;
                lineEditHex->setText ( nodeElement.text () );
                break;
              }
              case Xsd::TypeAbs::IDREFS:



                break;

              case Xsd::TypeAbs::IDREF:


                break;

              case Xsd::TypeAbs::ID:


                break;

              case Xsd::TypeAbs::INTEGER: {

                if ( xsdElementType->isEnumerate () ) {

                  QComboBox *comboBoxInteger = ( QComboBox * ) inputWidget;
                  comboBoxInteger->setCurrentText ( nodeElement.text () );

                } else {

                  QSpinBox *spinBoxInteger = ( QSpinBox * ) inputWidget;
                  spinBoxInteger->setValue ( nodeElement.text ().toInt () );
                }
                break;
              }
              case Xsd::TypeAbs::INT: {

                if ( xsdElementType->isEnumerate () ) {

                  QComboBox *comboBoxInt = ( QComboBox * ) inputWidget;
                  comboBoxInt->setCurrentText ( nodeElement.text () );

                } else {

                  QSpinBox *spinBox = ( QSpinBox * ) inputWidget;
                  spinBox->setValue ( nodeElement.text ().toInt () );
                }
                break;
              }
              case Xsd::TypeAbs::LANGUAGE:


                break;

              case Xsd::TypeAbs::LONG:


                break;

              case Xsd::TypeAbs::NAME:


                break;

              case Xsd::TypeAbs::NCNAME:


                break;

              case Xsd::TypeAbs::NEGATIVEINTEGER:


                break;

              case Xsd::TypeAbs::NMTOKENS:


                break;

              case Xsd::TypeAbs::NMTOKEN:


                break;

              case Xsd::TypeAbs::NONNEGATIVEINTEGER:


                break;

              case Xsd::TypeAbs::NONPOSITIVEINTEGER:


                break;

              case Xsd::TypeAbs::NORMALIZEDSTRING:


                break;

              case Xsd::TypeAbs::NOTATION:


                break;

              case Xsd::TypeAbs::POSITIVEINTEGER:


                break;

              case Xsd::TypeAbs::QNAME:


                break;

              case Xsd::TypeAbs::SHORT:


                break;

              case Xsd::TypeAbs::STRING: {

                if ( xsdElementType->isEnumerate () ) {

                  QComboBox *comboBox = ( QComboBox * ) inputWidget;
                  comboBox->setCurrentText ( nodeElement.text () );

                } else {

                  QLineEdit *lineEdit = ( QLineEdit * ) inputWidget;
                  lineEdit->setText ( nodeElement.text () );
                }
                break;
              }
              case Xsd::TypeAbs::TIME:


                break;

              case Xsd::TypeAbs::TOKEN:


                break;

              case Xsd::TypeAbs::UNSIGNEDBYTE:


                break;

              case Xsd::TypeAbs::UNSIGNEDINT:


                break;

              case Xsd::TypeAbs::UNSIGNEDLONG:


                break;

              case Xsd::TypeAbs::UNSIGNEDSHORT:


                break;

              case Xsd::TypeAbs::YEARMONTHDURATION:


                break;

              default:

                break;
            }
          }
        }
      }
    }
    this->loadData ( element.nextSibling (), widget );
  }
}

QDomDocument XsdDialog::loadXml () {

  QFile *file = Utils::Files::load ( App::AppPaths::getInstance ().getApplicationConfigPath () + "config.xml" );
  QDomDocument doc;
  if ( file == nullptr ) {

    return doc;
  }
  if ( !doc.setContent ( file ) ) {

    // TODO: Aquí guardar el error de asignación del archivo al objeto QDomDocument y mostrar error
    file->close ();
    return doc;
  }
  file->close ();
  return doc;
}
