#include "XsdFormCreator.h"
#include <QDebug>

using namespace NAMESPACE_LIBRARY_XSDFORM;

XsdFormCreator::XsdFormCreator () {}

void XsdFormCreator::createForm ( NAMESPACE_LIBRARY_XSD::XsdElement *xsdElement, QWidget *parent ) {

  this->tabsDialog = new QTabWidget ( parent );
  this->tabsDialog->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
  const int tabsCount = xsdElement->getElementsList ().count ();
  if ( tabsCount > 0 ) {

    this->createTabs ( xsdElement->getElementsList () );
  }
}

void XsdFormCreator::createGroup ( QWidget *widget, NAMESPACE_LIBRARY_XSD::XsdElement *xsdElement ) {

  QGroupBox *groupBoxElement = new QGroupBox ( widget );
  groupBoxElement->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
  groupBoxElement->setTitle ( ( ( NAMESPACE_LIBRARY_XSD::NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
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

void XsdFormCreator::createHexbinaryInput ( QWidget *widget, NAMESPACE_LIBRARY_XSD::XsdElement *xsdElement ) {

  const int facetsCount = xsdElement->getFacets ().count ();
  for ( int i = 0; i < facetsCount; i++ ) {

    if ( xsdElement->isEnumerate () ) {

      ( ( QComboBox * ) widget )->addItem ( ( ( NAMESPACE_LIBRARY_XSD::EnumerationFacet * ) xsdElement->getFacets ().at ( i ) )->getValue () );

    } else {

      if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::AssertionsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::LengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( NAMESPACE_LIBRARY_XSD::LengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::MaxLengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( NAMESPACE_LIBRARY_XSD::MaxLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::MinLengthFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QLineEdit * ) widget )->setMaxLength ( ( ( NAMESPACE_LIBRARY_XSD::MinLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::PatternFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setInputMask ( ( ( NAMESPACE_LIBRARY_XSD::PatternFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ()  );

      }
    }
  }
}

void XsdFormCreator::createInputType ( QWidget *widget, NAMESPACE_LIBRARY_XSD::XsdElement *xsdElement ) {

  NAMESPACE_LIBRARY_XSD::TypeProperty *objTypeProperty = ( NAMESPACE_LIBRARY_XSD::TypeProperty * ) xsdElement->getProperty ( "TypeProperty" );
  switch ( objTypeProperty->getValue () ) {

    case NAMESPACE_LIBRARY_XSD::TypeAbs::ANYURI:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::BASE64BINARY:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::BOOLEAN:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::BYTE:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::DATETIMESTAMP:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::DATETIME:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::DATE:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::DAYTIMEDURATION:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::DECIMAL:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::DOUBLE:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::DURATION:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::ENTITIES:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::ENTITY:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::FLOAT:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::GDAY:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::GMONTHDAY:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::GMONTH:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::GYEARMONTH:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::GYEAR:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::HEXBINARY:

      this->createHexbinaryInput ( widget, xsdElement );
      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::IDREFS:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::IDREF:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::ID:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::INTEGER:

      this->createIntegerInput ( widget, xsdElement );
      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::INT:

      this->createIntegerInput ( widget, xsdElement );
      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::LANGUAGE:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::LONG:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::NAME:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::NCNAME:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::NEGATIVEINTEGER:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::NMTOKENS:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::NMTOKEN:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::NONNEGATIVEINTEGER:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::NONPOSITIVEINTEGER:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::NORMALIZEDSTRING:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::NOTATION:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::POSITIVEINTEGER:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::QNAME:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::SHORT:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::STRING:

      this->createStringInput ( widget, xsdElement );
      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::TIME:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::TOKEN:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::UNSIGNEDBYTE:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::UNSIGNEDINT:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::UNSIGNEDLONG:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::UNSIGNEDSHORT:


      break;

    case NAMESPACE_LIBRARY_XSD::TypeAbs::YEARMONTHDURATION:


      break;

    default:

      break;
  }
}

void XsdFormCreator::createIntegerInput ( QWidget *widget, NAMESPACE_LIBRARY_XSD::XsdElement *xsdElement ) {

  const int facetsCount = xsdElement->getFacets ().count ();
  for ( int i = 0; i < facetsCount; i++ ) {

    if ( xsdElement->isEnumerate () ) {

      ( ( QComboBox * ) widget )->addItem ( ( ( NAMESPACE_LIBRARY_XSD::EnumerationFacet * ) xsdElement->getFacets ().at ( i ) )->getValue () );

    } else {

      if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::AssertionsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::MaxExclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMaximum ( ( ( NAMESPACE_LIBRARY_XSD::MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () - 1 );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::MaxInclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMaximum ( ( ( NAMESPACE_LIBRARY_XSD::MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::MinExclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMinimum ( ( ( NAMESPACE_LIBRARY_XSD::MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () + 1 );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::MinInclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMinimum ( ( ( NAMESPACE_LIBRARY_XSD::MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt ()  );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::TotalDigitsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->
      }
    }
  }
}

void XsdFormCreator::createParam ( QWidget *widget, NAMESPACE_LIBRARY_XSD::XsdElement *xsdElement ) {

  QLabel *paramLabel = new QLabel ( widget );
  paramLabel->setText ( ( ( NAMESPACE_LIBRARY_XSD::NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
  ( ( QGridLayout * ) widget->layout () )->addWidget ( paramLabel, ( ( QGridLayout * ) widget->layout () )->rowCount (), 0, 1, 1, Qt::AlignRight );
  NAMESPACE_LIBRARY_XSD::TypeProperty *objTypeProperty = ( NAMESPACE_LIBRARY_XSD::TypeProperty * ) xsdElement->getProperty ( "TypeProperty" );

  if ( xsdElement->isEnumerate () ) {

    QComboBox *comboBox = new QComboBox ( widget );
    comboBox->setMaximumHeight ( 18 );
    comboBox->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
    ( ( QGridLayout * ) widget->layout () )->addWidget ( comboBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
    this->createInputType ( comboBox, xsdElement );

  } else {

    if ( objTypeProperty->getValue () == NAMESPACE_LIBRARY_XSD::TypeAbs::INTEGER ) {

      QSpinBox *spinBox = new QSpinBox ( widget );
      spinBox->setMaximumHeight ( 18 );
      spinBox->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
      this->createInputType ( spinBox, xsdElement );
      ( ( QGridLayout * ) widget->layout () )->addWidget ( spinBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

    } else {

      if ( objTypeProperty->getValue () == NAMESPACE_LIBRARY_XSD::TypeAbs::HEXBINARY ) {

        NAMESPACE_LIBRARY_COLORBOX::ColorBox *colorBox = new NAMESPACE_LIBRARY_COLORBOX::ColorBox ();
        colorBox->setMaximumHeight ( 18 );
        colorBox->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
        this->createInputType ( colorBox, xsdElement );
        ( ( QGridLayout * ) widget->layout () )->addWidget ( colorBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

      } else {

        QLineEdit *lineEdit = new QLineEdit ();
        lineEdit->setMaximumHeight ( 18 );
        lineEdit->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
        this->createInputType ( lineEdit, xsdElement );
        //connect ( lineEdit, SIGNAL (  ), this, SLOT (  ) );
        ( ( QGridLayout * ) widget->layout () )->addWidget ( lineEdit, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
      }
    }
  }
}

void XsdFormCreator::createParams ( QWidget *widget, QList<NAMESPACE_LIBRARY_XSD::XsdElement *> xsdElementList ) {

  const int paramsCount = xsdElementList.count ();
  for ( int i = 0; i < paramsCount; i++ ) {

    NAMESPACE_LIBRARY_XSD::XsdElement *xsdElement = xsdElementList.at ( i );
    if ( xsdElement->getElementLevel () == NAMESPACE_LIBRARY_XSD::Xsd::GROUPFORM ) {

      this->createGroup ( widget, xsdElement );

    } else {

      this->createParam ( widget, xsdElement );
      ( ( QGridLayout * ) widget->layout () )->setColumnStretch ( ( ( QGridLayout * ) widget->layout () )->columnCount (), 1 );
    }
  }
}

void XsdFormCreator::createStringInput ( QWidget *widget, NAMESPACE_LIBRARY_XSD::XsdElement *xsdElement ) {

  const int facetsCount = xsdElement->getFacets ().count ();
  for ( int i = 0; i < facetsCount; i++ ) {

    if ( xsdElement->isEnumerate () ) {

      ( ( QComboBox * ) widget )->addItem ( ( ( NAMESPACE_LIBRARY_XSD::EnumerationFacet * ) xsdElement->getFacets ().at ( i ) )->getValue () );

    } else {

      if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::AssertionsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::LengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( NAMESPACE_LIBRARY_XSD::LengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::MaxLengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( NAMESPACE_LIBRARY_XSD::MaxLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::MinLengthFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QLineEdit * ) widget )->setMaxLength ( ( ( NAMESPACE_LIBRARY_XSD::MinLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NAMESPACE_LIBRARY_XSD::PatternFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setInputMask ( ( ( NAMESPACE_LIBRARY_XSD::PatternFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ()  );

      }
    }
  }
}

void XsdFormCreator::createTab ( NAMESPACE_LIBRARY_XSD::XsdElement *xsdElement ) {

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
  this->tabsDialog->addTab ( tabWidget, ( ( NAMESPACE_LIBRARY_XSD::NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
  const int tabsCount = xsdElement->getElementsList ().count ();
  if ( tabsCount > 0 ) {

    this->createParams ( internalTabWidget, xsdElement->getElementsList () );
    internalTabWidgetLayout->setRowStretch ( internalTabWidgetLayout->rowCount (), 1 );
  }
}

void XsdFormCreator::createTabs ( QList<NAMESPACE_LIBRARY_XSD::XsdElement *> xsdElementList ) {

  const int tabsCount = xsdElementList.count ();
  for ( int i = 0; i < tabsCount; i++ ) {

    this->createTab ( xsdElementList.at ( i ) );
  }
}

QTabWidget *XsdFormCreator::getForm () const {

  return this->tabsDialog;
}

QString XsdFormCreator::getNameInput ( NAMESPACE_LIBRARY_XSD::XsdElement *xsdElement ) {

  QString nameInputAux = "";
  if ( xsdElement->getParent () != nullptr ) {

    nameInputAux = this->getNameInput ( xsdElement->getParent () );
  }
  return nameInputAux + ( ( NAMESPACE_LIBRARY_XSD::NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue ();
}
