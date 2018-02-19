#include "XsdFormCreator.h"
#include <QDebug>

using namespace Com::Ecosoftware::Engines::Xsd;

XsdFormCreator::XsdFormCreator () {}

void XsdFormCreator::createForm ( XsdElement *xsdElement, QWidget *parent ) {

  this->tabsDialog = new QTabWidget ( parent );
  this->tabsDialog->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
  const int tabsCount = xsdElement->getElementsList ().count ();
  if ( tabsCount > 0 ) {

    this->createTabs ( xsdElement->getElementsList () );
  }
}

void XsdFormCreator::createGroup ( QWidget *widget, XsdElement *xsdElement ) {

  QGroupBox *groupBoxElement = new QGroupBox ( widget );
  groupBoxElement->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
  groupBoxElement->setTitle ( ( ( NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
  QGridLayout *groupBoxElementLayout = new QGridLayout ( groupBoxElement );
  groupBoxElement->setLayout ( groupBoxElementLayout );
  ( ( QGridLayout * ) widget->layout () )->addWidget ( groupBoxElement, ( ( QGridLayout * ) widget->layout () )->rowCount (), 0, 6, 6, Qt::AlignBaseline );

  const int paramsCount = xsdElement->getElementsList ().count ();
  if ( paramsCount > 0 ) {

    this->createParams ( groupBoxElement, xsdElement->getElementsList () );
    groupBoxElementLayout->setRowStretch ( groupBoxElementLayout->rowCount (), 1 );
    groupBoxElementLayout->setColumnStretch ( groupBoxElementLayout->columnCount (), 1 );
  }
}

void XsdFormCreator::createHexbinaryInput ( QWidget *widget, XsdElement *xsdElement ) {

  const int facetsCount = xsdElement->getFacets ().count ();
  for ( int i = 0; i < facetsCount; i++ ) {

    if ( xsdElement->isEnumerate () ) {

      ( ( QComboBox * ) widget )->addItem ( ( ( EnumerationFacet * ) xsdElement->getFacets ().at ( i ) )->getValue () );

    } else {

      if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::AssertionsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::LengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( LengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MaxLengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( MaxLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MinLengthFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QLineEdit * ) widget )->setMaxLength ( ( ( MinLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::PatternFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setInputMask ( ( ( PatternFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ()  );

      }
    }
  }
}

void XsdFormCreator::createInputType ( QWidget *widget, XsdElement *xsdElement ) {

  // https://www.softzone.es/2015/11/26/como-aumentar-la-velocidad-de-arranque-de-windows-10-con-esta-configuracion/
  // https://www.softzone.es/2017/08/20/como-evitar-que-nos-cambien-la-imagen-de-usuario-en-windows-10/
  TypeProperty *objTypeProperty = ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" );
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

    case TypeAbs::HEXBINARY:

      this->createHexbinaryInput ( widget, xsdElement );
      break;

    case TypeAbs::IDREFS:


      break;

    case TypeAbs::IDREF:


      break;

    case TypeAbs::ID:


      break;

    case TypeAbs::INTEGER:

      this->createIntegerInput ( widget, xsdElement );
      break;

    case TypeAbs::INT:

      this->createIntegerInput ( widget, xsdElement );
      break;

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

    case TypeAbs::STRING:

      this->createStringInput ( widget, xsdElement );
      break;

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

void XsdFormCreator::createIntegerInput ( QWidget *widget, XsdElement *xsdElement ) {

  const int facetsCount = xsdElement->getFacets ().count ();
  for ( int i = 0; i < facetsCount; i++ ) {

    if ( xsdElement->isEnumerate () ) {

      ( ( QComboBox * ) widget )->addItem ( ( ( EnumerationFacet * ) xsdElement->getFacets ().at ( i ) )->getValue () );

    } else {

      if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::AssertionsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MaxExclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMaximum ( ( ( MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () - 1 );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MaxInclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMaximum ( ( ( MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MinExclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMinimum ( ( ( MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () + 1 );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MinInclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMinimum ( ( ( MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt ()  );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::TotalDigitsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->
      }
    }
  }
}

void XsdFormCreator::createParam ( QWidget *widget, XsdElement *xsdElement ) {

  QLabel *paramLabel = new QLabel ( widget );
  paramLabel->setText ( ( ( NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
  ( ( QGridLayout * ) widget->layout () )->addWidget ( paramLabel, ( ( QGridLayout * ) widget->layout () )->rowCount (), 0, 1, 1, Qt::AlignRight );

  if ( xsdElement->isEnumerate () ) {

    QComboBox *comboBox = new QComboBox ( widget );
    comboBox->setMaximumHeight ( 18 );
    comboBox->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
    ( ( QGridLayout * ) widget->layout () )->addWidget ( comboBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
    this->createInputType ( comboBox, xsdElement );

  } else {

    TypeProperty *objTypeProperty = ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" );
    if ( objTypeProperty->getValue () == TypeAbs::INTEGER ) {

      QSpinBox *spinBox = new QSpinBox ( widget );
      spinBox->setMaximumHeight ( 18 );
      spinBox->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
      this->createInputType ( spinBox, xsdElement );
      ( ( QGridLayout * ) widget->layout () )->addWidget ( spinBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

    } else {

      QLineEdit *lineEdit = new QLineEdit ();
      lineEdit->setMaximumHeight ( 18 );
      lineEdit->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
      this->createInputType ( lineEdit, xsdElement );
      //connect ( lineEdit, SIGNAL (  ), this, SLOT (  ) );
      // TODO: Aquí asignar una acción que al hacer click, llame al colorPicker QColorDialog
      // TODO: Como saber cuando es hexbinary y cuando string para saber cuando colocar el color picker
      ( ( QGridLayout * ) widget->layout () )->addWidget ( lineEdit, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
    }
  }
}

void XsdFormCreator::createParams ( QWidget *widget, QList<XsdElement *> xsdElementList ) {

  const int paramsCount = xsdElementList.count ();
  for ( int i = 0; i < paramsCount; i++ ) {

    XsdElement *xsdElement = xsdElementList.at ( i );
    if ( xsdElement->getElementLevel () == Xsd::GROUPFORM ) {

      this->createGroup ( widget, xsdElement );

    } else {

      this->createParam ( widget, xsdElement );
      ( ( QGridLayout * ) widget->layout () )->setColumnStretch ( ( ( QGridLayout * ) widget->layout () )->columnCount (), 1 );
    }
  }
}

void XsdFormCreator::createStringInput ( QWidget *widget, XsdElement *xsdElement ) {

  const int facetsCount = xsdElement->getFacets ().count ();
  for ( int i = 0; i < facetsCount; i++ ) {

    if ( xsdElement->isEnumerate () ) {

      ( ( QComboBox * ) widget )->addItem ( ( ( EnumerationFacet * ) xsdElement->getFacets ().at ( i ) )->getValue () );

    } else {

      if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::AssertionsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::LengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( LengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MaxLengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( MaxLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MinLengthFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QLineEdit * ) widget )->setMaxLength ( ( ( MinLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::PatternFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setInputMask ( ( ( PatternFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ()  );

      }
    }
  }
}

void XsdFormCreator::createTab ( XsdElement *xsdElement ) {

  QWidget *tabWidget = new QWidget ( this->tabsDialog );
  tabWidget->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
  tabWidget->setSizePolicy ( QSizePolicy::Expanding, QSizePolicy::Expanding );
  QVBoxLayout *tabWidgetLayout = new QVBoxLayout ( tabWidget );
  tabWidget->setLayout ( tabWidgetLayout );
  QScrollArea *scrollArea = new QScrollArea ( tabWidget );
  scrollArea->setWidgetResizable ( true );
  tabWidgetLayout->addWidget ( scrollArea );
  QWidget *internalTabWidget = new QWidget ( scrollArea );
  internalTabWidget->setSizePolicy ( QSizePolicy::Expanding, QSizePolicy::Expanding );
  QGridLayout *internalTabWidgetLayout = new QGridLayout ( internalTabWidget );
  internalTabWidget->setLayout ( internalTabWidgetLayout );
  scrollArea->setWidget ( internalTabWidget );
  this->tabsDialog->addTab ( tabWidget, ( ( NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
  const int tabsCount = xsdElement->getElementsList ().count ();
  if ( tabsCount > 0 ) {

    this->createParams ( internalTabWidget, xsdElement->getElementsList () );
    internalTabWidgetLayout->setRowStretch ( internalTabWidgetLayout->rowCount (), 1 );
  }
}

void XsdFormCreator::createTabs ( QList<XsdElement *> xsdElementList ) {

  const int tabsCount = xsdElementList.count ();
  for ( int i = 0; i < tabsCount; i++ ) {

    this->createTab ( xsdElementList.at ( i ) );
  }
}

QTabWidget *XsdFormCreator::getForm () const {

  return this->tabsDialog;
}

QString XsdFormCreator::getNameInput ( XsdElement *xsdElement ) {

  QString nameInputAux = "";
  if ( xsdElement->getParent () != nullptr ) {

    nameInputAux = this->getNameInput ( xsdElement->getParent () );
  }
  return nameInputAux + ( ( NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue ();
}
