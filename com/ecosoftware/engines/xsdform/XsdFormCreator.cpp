#include "XsdFormCreator.h"
#include <QDebug>

using namespace Com::Ecosoftware::Engines::XsdForm;

XsdFormCreator::XsdFormCreator () {}

void XsdFormCreator::createForm ( Com::Ecosoftware::Engines::Xsd::XsdElement *xsdElement, QWidget *parent ) {

  this->tabsDialog = new QTabWidget ( parent );
  this->tabsDialog->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
  const int tabsCount = xsdElement->getElementsList ().count ();
  if ( tabsCount > 0 ) {

    this->createTabs ( xsdElement->getElementsList () );
  }
}

void XsdFormCreator::createGroup ( QWidget *widget, Com::Ecosoftware::Engines::Xsd::XsdElement *xsdElement ) {

  QGroupBox *groupBoxElement = new QGroupBox ( widget );
  groupBoxElement->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
  groupBoxElement->setTitle ( ( ( Xsd::NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
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

void XsdFormCreator::createHexbinaryInput ( QWidget *widget, Com::Ecosoftware::Engines::Xsd::XsdElement *xsdElement ) {

  const int facetsCount = xsdElement->getFacets ().count ();
  for ( int i = 0; i < facetsCount; i++ ) {

    if ( xsdElement->isEnumerate () ) {

      ( ( QComboBox * ) widget )->addItem ( ( ( Xsd::EnumerationFacet * ) xsdElement->getFacets ().at ( i ) )->getValue () );

    } else {

      if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::AssertionsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::LengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( Xsd::LengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MaxLengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( Xsd::MaxLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MinLengthFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QLineEdit * ) widget )->setMaxLength ( ( ( Xsd::MinLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::PatternFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setInputMask ( ( ( Xsd::PatternFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ()  );

      }
    }
  }
}

void XsdFormCreator::createInputType ( QWidget *widget, Com::Ecosoftware::Engines::Xsd::XsdElement *xsdElement ) {

  // https://www.softzone.es/2015/11/26/como-aumentar-la-velocidad-de-arranque-de-windows-10-con-esta-configuracion/
  // https://www.softzone.es/2017/08/20/como-evitar-que-nos-cambien-la-imagen-de-usuario-en-windows-10/
  Xsd::TypeProperty *objTypeProperty = ( Xsd::TypeProperty * ) xsdElement->getProperty ( "TypeProperty" );
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

    case Xsd::TypeAbs::HEXBINARY:

      this->createHexbinaryInput ( widget, xsdElement );
      break;

    case Xsd::TypeAbs::IDREFS:


      break;

    case Xsd::TypeAbs::IDREF:


      break;

    case Xsd::TypeAbs::ID:


      break;

    case Xsd::TypeAbs::INTEGER:

      this->createIntegerInput ( widget, xsdElement );
      break;

    case Xsd::TypeAbs::INT:

      this->createIntegerInput ( widget, xsdElement );
      break;

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

    case Xsd::TypeAbs::STRING:

      this->createStringInput ( widget, xsdElement );
      break;

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

void XsdFormCreator::createIntegerInput ( QWidget *widget, Com::Ecosoftware::Engines::Xsd::XsdElement *xsdElement ) {

  const int facetsCount = xsdElement->getFacets ().count ();
  for ( int i = 0; i < facetsCount; i++ ) {

    if ( xsdElement->isEnumerate () ) {

      ( ( QComboBox * ) widget )->addItem ( ( ( Xsd::EnumerationFacet * ) xsdElement->getFacets ().at ( i ) )->getValue () );

    } else {

      if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::AssertionsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MaxExclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMaximum ( ( ( Xsd::MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () - 1 );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MaxInclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMaximum ( ( ( Xsd::MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MinExclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMinimum ( ( ( Xsd::MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () + 1 );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MinInclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMinimum ( ( ( Xsd::MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt ()  );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::TotalDigitsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->
      }
    }
  }
}

void XsdFormCreator::createParam ( QWidget *widget, Com::Ecosoftware::Engines::Xsd::XsdElement *xsdElement ) {

  QLabel *paramLabel = new QLabel ( widget );
  paramLabel->setText ( ( ( Xsd::NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
  ( ( QGridLayout * ) widget->layout () )->addWidget ( paramLabel, ( ( QGridLayout * ) widget->layout () )->rowCount (), 0, 1, 1, Qt::AlignRight );

  if ( xsdElement->isEnumerate () ) {

    QComboBox *comboBox = new QComboBox ( widget );
    comboBox->setMaximumHeight ( 18 );
    comboBox->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
    ( ( QGridLayout * ) widget->layout () )->addWidget ( comboBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
    this->createInputType ( comboBox, xsdElement );

  } else {

    Xsd::TypeProperty *objTypeProperty = ( Xsd::TypeProperty * ) xsdElement->getProperty ( "TypeProperty" );
    if ( objTypeProperty->getValue () == Xsd::TypeAbs::INTEGER ) {

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

void XsdFormCreator::createParams ( QWidget *widget, QList<Com::Ecosoftware::Engines::Xsd::XsdElement *> xsdElementList ) {

  const int paramsCount = xsdElementList.count ();
  for ( int i = 0; i < paramsCount; i++ ) {

    Com::Ecosoftware::Engines::Xsd::XsdElement *xsdElement = xsdElementList.at ( i );
    if ( xsdElement->getElementLevel () == Xsd::Xsd::GROUPFORM ) {

      this->createGroup ( widget, xsdElement );

    } else {

      this->createParam ( widget, xsdElement );
      ( ( QGridLayout * ) widget->layout () )->setColumnStretch ( ( ( QGridLayout * ) widget->layout () )->columnCount (), 1 );
    }
  }
}

void XsdFormCreator::createStringInput ( QWidget *widget, Com::Ecosoftware::Engines::Xsd::XsdElement *xsdElement ) {

  const int facetsCount = xsdElement->getFacets ().count ();
  for ( int i = 0; i < facetsCount; i++ ) {

    if ( xsdElement->isEnumerate () ) {

      ( ( QComboBox * ) widget )->addItem ( ( ( Xsd::EnumerationFacet * ) xsdElement->getFacets ().at ( i ) )->getValue () );

    } else {

      if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::AssertionsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::LengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( Xsd::LengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MaxLengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( Xsd::MaxLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::MinLengthFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QLineEdit * ) widget )->setMaxLength ( ( ( Xsd::MinLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::PatternFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setInputMask ( ( ( Xsd::PatternFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ()  );

      }
    }
  }
}

void XsdFormCreator::createTab ( Com::Ecosoftware::Engines::Xsd::XsdElement *xsdElement ) {

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
  this->tabsDialog->addTab ( tabWidget, ( ( Xsd::NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
  const int tabsCount = xsdElement->getElementsList ().count ();
  if ( tabsCount > 0 ) {

    this->createParams ( internalTabWidget, xsdElement->getElementsList () );
    internalTabWidgetLayout->setRowStretch ( internalTabWidgetLayout->rowCount (), 1 );
  }
}

void XsdFormCreator::createTabs ( QList<Com::Ecosoftware::Engines::Xsd::XsdElement *> xsdElementList ) {

  const int tabsCount = xsdElementList.count ();
  for ( int i = 0; i < tabsCount; i++ ) {

    this->createTab ( xsdElementList.at ( i ) );
  }
}

QTabWidget *XsdFormCreator::getForm () const {

  return this->tabsDialog;
}

QString XsdFormCreator::getNameInput ( Com::Ecosoftware::Engines::Xsd::XsdElement *xsdElement ) {

  QString nameInputAux = "";
  if ( xsdElement->getParent () != nullptr ) {

    nameInputAux = this->getNameInput ( xsdElement->getParent () );
  }
  return nameInputAux + ( ( Xsd::NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue ();
}
