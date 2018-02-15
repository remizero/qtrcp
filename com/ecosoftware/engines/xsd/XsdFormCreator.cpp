#include "XsdFormCreator.h"
#include <QDebug>

using namespace Com::Ecosoftware::Engines::Xsd;

XsdFormCreator::XsdFormCreator () {}

void XsdFormCreator::createForm ( XsdElement *xsdElement, QWidget *parent ) {

  //this->formDialog = new QDialog ( parent );
  //this->formDialog->setMinimumSize ( 800, 600 );
  //this->formDialog->setWindowTitle ( ( ( NameProperty * ) xsdElement->getProperty ( "name" ) )->getValue () );
  //QVBoxLayout *formDialogLayout = new QVBoxLayout ( this->formDialog );
  //this->formDialog->setLayout ( formDialogLayout );
  this->tabsDialog = new QTabWidget ( parent );
  //QDialogButtonBox *buttonBox = new QDialogButtonBox ( this->formDialog );
  //buttonBox->setStandardButtons ( QDialogButtonBox::Ok | QDialogButtonBox::Apply | QDialogButtonBox::Cancel );
  //formDialogLayout->addWidget ( this->tabsDialog );
  //formDialogLayout->addWidget ( buttonBox );
  //this->formDialog->connect ( buttonBox, SIGNAL ( rejected () ), this->formDialog, SLOT ( reject () ) );

  const int tabsCount = xsdElement->getElementsList ().count ();
  if ( tabsCount > 0 ) {

    this->createTabs ( xsdElement->getElementsList () );
  }
}

void XsdFormCreator::createGroup ( QWidget *widget, XsdElement *xsdElement ) {

  QGroupBox *groupBoxElement = new QGroupBox ( widget );
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

void XsdFormCreator::createParam ( QWidget *widget, XsdElement *xsdElement ) {

  QLabel *paramLabel = new QLabel ( widget );
  paramLabel->setText ( ( ( NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
  ( ( QGridLayout * ) widget->layout () )->addWidget ( paramLabel, ( ( QGridLayout * ) widget->layout () )->rowCount (), 0, 1, 1, Qt::AlignRight );

  const int facetsCount = xsdElement->getFacets ().count ();
  qDebug () << "Pero debería buscar los FACETS del elemento, y tiene: " << facetsCount << " FACETAS";

  TypeProperty *objTypeProperty = ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" );

  if ( facetsCount > 0 ) {

    for ( int i = 0; i < facetsCount; i++ ) {

      if ( objTypeProperty->getValue () == TypeAbs::INTEGER ) {

        qDebug () << "El tipo es un TypeAbs::INTEGER";
        qDebug () << xsdElement->getFacets ().at ( i )->metaObject ()->className ();
        if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "Com::Ecosoftware::Engines::Xsd::EnumerationFacet" ) == 0 ) {

        }
      } else if ( objTypeProperty->getValue () == TypeAbs::STRING ) {

        qDebug () << "El tipo es un TypeAbs::STRING";

      } else if ( objTypeProperty->getValue () == TypeAbs::HEXBINARY ) {

        qDebug () << "El tipo es un TypeAbs::HEXBINARY";
      }
    }
  } else {

    if ( objTypeProperty->getValue () == TypeAbs::INTEGER ) {

      //qDebug () << xsdElement->getFacets ().at ( i )->metaObject ()->className ();
      QSpinBox *spinBox = new QSpinBox ( widget );
      spinBox->setMaximumHeight ( 18 );
      ( ( QGridLayout * ) widget->layout () )->addWidget ( spinBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

    } else if ( objTypeProperty->getValue () == TypeAbs::STRING ) {

      QLineEdit *lineEdit = new QLineEdit ();
      lineEdit->setMaximumHeight ( 18 );
      ( ( QGridLayout * ) widget->layout () )->addWidget ( lineEdit, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

    } else if ( objTypeProperty->getValue () == TypeAbs::HEXBINARY ) {

      QLineEdit *lineEdit = new QLineEdit ();
      lineEdit->setMaximumHeight ( 18 );
      //connect ( lineEdit, SIGNAL (  ), this, SLOT (  ) );
      // TODO: Aquí asignar una acción que al hacer click, llame al colorPicker QColorDialog
      ( ( QGridLayout * ) widget->layout () )->addWidget ( lineEdit, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
    }
  }
/*
  if ( paramsCount > 0 ) {

    if ( ( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->getValue () == TypeAbs::INTEGER ) {

      if ( xsdElement->getElementsList ().at ( 0 )->getElementType () == "xs:enumeration" ) {

        QComboBox *comboBox = new QComboBox ( widget );
        comboBox->setMaximumHeight ( 18 );
        ( ( QGridLayout * ) widget->layout () )->addWidget ( comboBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
        this->createTypes ( comboBox, xsdElement->getElementsList () );

      } else if ( xsdElement->getElementsList ().at ( 0 )->getElementType () == "xs:minInclusive" ) {

        QSpinBox *spinBox = new QSpinBox ( widget );
        spinBox->setMaximumHeight ( 18 );
        ( ( QGridLayout * ) widget->layout () )->addWidget ( spinBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
        this->createTypes ( spinBox, xsdElement->getElementsList () );
      }
    } else if ( ( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->getValue () == TypeAbs::STRING ) {

      if ( xsdElement->getElementsList ().at ( 0 )->getElementType () == "xs:enumeration" ) {

        QComboBox *comboBox = new QComboBox ( widget );
        comboBox->setMaximumHeight ( 18 );
        ( ( QGridLayout * ) widget->layout () )->addWidget ( comboBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
        this->createTypes ( comboBox, xsdElement->getElementsList () );
      }
    }
  } else {

    if ( ( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->getValue () == TypeAbs::STRING ) {

      QLineEdit *lineEdit = new QLineEdit ();
      lineEdit->setMaximumHeight ( 18 );
      ( ( QGridLayout * ) widget->layout () )->addWidget ( lineEdit, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

    } else if ( ( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->getValue () == TypeAbs::HEXBINARY ) {

      QLineEdit *lineEdit = new QLineEdit ();
      lineEdit->setMaximumHeight ( 18 );
      //connect ( lineEdit, SIGNAL (  ), this, SLOT (  ) );
      // TODO: Aquí asignar una acción que al hacer click, llame al colorPicker QColorDialog
      ( ( QGridLayout * ) widget->layout () )->addWidget ( lineEdit, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

    } else if ( ( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->getValue () == TypeAbs::INTEGER ) {

      QSpinBox *spinBox = new QSpinBox ( widget );
      spinBox->setMaximumHeight ( 18 );
      ( ( QGridLayout * ) widget->layout () )->addWidget ( spinBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
    }
  }*/
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

void XsdFormCreator::createTab ( XsdElement *xsdElement ) {

  QWidget *tabWidget = new QWidget ( this->tabsDialog );
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

void XsdFormCreator::createType ( QWidget *widget, XsdElement *xsdElement ) {

  /*if ( xsdElement->getElementType () == "xs:string" ) {

    QLineEdit *lineEdit = new QLineEdit ();
    lineEdit->setMaximumHeight ( 14 );
    ( ( QGridLayout * ) widget->layout () )->addWidget ( lineEdit, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

  } else if ( xsdElement->getElementType () == "xs:integer" ) {

    QSpinBox *spinBox = new QSpinBox ( widget );
    spinBox->setMaximumHeight ( 18 );
    ( ( QGridLayout * ) widget->layout () )->addWidget ( spinBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

  } else if ( xsdElement->getElementType () == "xs:hexBinary" ) {

    QLineEdit *lineEdit = new QLineEdit ();
    lineEdit->setMaximumHeight ( 18 );
    ( ( QGridLayout * ) widget->layout () )->addWidget ( lineEdit, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

  } else if ( xsdElement->getElementType () == "xs:enumeration" ) {

    ( ( QComboBox * ) widget )->addItem ( xsdElement->getElementValue () );
  }*/
}

void XsdFormCreator::createTypes ( QWidget *widget, QList<XsdElement *> xsdElementList ) {

  /*QListIterator<XsdElement *> typesIterator ( xsdElementList );
  while ( typesIterator.hasNext () ) {

    this->createType ( widget, typesIterator.next () );
  }*/
}

QTabWidget *XsdFormCreator::getForm () const {

  return this->tabsDialog;
}

