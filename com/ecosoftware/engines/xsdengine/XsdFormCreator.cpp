#include "XsdFormCreator.h"
#include <QDebug>

using namespace Com::Ecosoftware::Engines::XsdEngine;

XsdFormCreator::XsdFormCreator () {}

void XsdFormCreator::createForm ( XsdFormElement *xsdFormElement, QWidget *parent ) {

  this->formDialog = new QDialog ( parent );
  this->formDialog->setMinimumSize ( 800, 600 );
  this->formDialog->setWindowTitle ( xsdFormElement->getElementName () );
  QVBoxLayout *formDialogLayout = new QVBoxLayout ( this->formDialog );
  this->formDialog->setLayout ( formDialogLayout );
  this->tabsDialog = new QTabWidget ( this->formDialog );
  QDialogButtonBox *buttonBox = new QDialogButtonBox ( this->formDialog );
  buttonBox->setStandardButtons ( QDialogButtonBox::Ok | QDialogButtonBox::Apply | QDialogButtonBox::Cancel );
  formDialogLayout->addWidget ( this->tabsDialog );
  formDialogLayout->addWidget ( buttonBox );
  this->formDialog->connect ( buttonBox, SIGNAL ( rejected () ), this->formDialog, SLOT ( reject () ) );

  const int tabsCount = xsdFormElement->getElementsList ().count ();
  if ( tabsCount > 0 ) {

    this->createTabs ( xsdFormElement->getElementsList () );
  }
}

void XsdFormCreator::createGroup ( QWidget *widget, XsdFormElement *xsdFormElement ) {

  QGroupBox *groupBoxElement = new QGroupBox ( widget );
  groupBoxElement->setTitle ( xsdFormElement->getElementName () );
  QGridLayout *groupBoxElementLayout = new QGridLayout ( groupBoxElement );
  groupBoxElement->setLayout ( groupBoxElementLayout );
  ( ( QGridLayout * ) widget->layout () )->addWidget ( groupBoxElement, ( ( QGridLayout * ) widget->layout () )->rowCount (), 0, 6, 6, Qt::AlignBaseline );

  const int paramsCount = xsdFormElement->getElementsList ().count ();
  if ( paramsCount > 0 ) {

    this->createParams ( groupBoxElement, xsdFormElement->getElementsList () );
    groupBoxElementLayout->setRowStretch ( groupBoxElementLayout->rowCount (), 1 );
    groupBoxElementLayout->setColumnStretch ( groupBoxElementLayout->columnCount (), 1 );
  }
}

void XsdFormCreator::createParam ( QWidget *widget, XsdFormElement *xsdFormElement ) {

  QLabel *paramLabel = new QLabel ( widget );
  paramLabel->setText ( xsdFormElement->getElementName () );
  ( ( QGridLayout * ) widget->layout () )->addWidget ( paramLabel, ( ( QGridLayout * ) widget->layout () )->rowCount (), 0, 1, 1, Qt::AlignRight );
  const int paramsCount = xsdFormElement->getElementsList ().count ();
  if ( paramsCount > 0 ) {

    if ( xsdFormElement->getElementType () == "xs:integer" ) {

      if ( xsdFormElement->getElementsList ().at ( 0 )->getElementType () == "xs:enumeration" ) {

        QComboBox *comboBox = new QComboBox ( widget );
        comboBox->setMaximumHeight ( 18 );
        ( ( QGridLayout * ) widget->layout () )->addWidget ( comboBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
        this->createTypes ( comboBox, xsdFormElement->getElementsList () );

      } else if ( xsdFormElement->getElementsList ().at ( 0 )->getElementType () == "xs:minInclusive" ) {

        QSpinBox *spinBox = new QSpinBox ( widget );
        spinBox->setMaximumHeight ( 18 );
        ( ( QGridLayout * ) widget->layout () )->addWidget ( spinBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
        this->createTypes ( spinBox, xsdFormElement->getElementsList () );
      }
    } else if ( xsdFormElement->getElementType () == "xs:string" ) {

      if ( xsdFormElement->getElementsList ().at ( 0 )->getElementType () == "xs:enumeration" ) {

        QComboBox *comboBox = new QComboBox ( widget );
        comboBox->setMaximumHeight ( 18 );
        ( ( QGridLayout * ) widget->layout () )->addWidget ( comboBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
        this->createTypes ( comboBox, xsdFormElement->getElementsList () );
      }
    }
  } else {

    if ( xsdFormElement->getElementType () == "xs:string" ) {

      QLineEdit *lineEdit = new QLineEdit ();
      lineEdit->setMaximumHeight ( 18 );
      ( ( QGridLayout * ) widget->layout () )->addWidget ( lineEdit, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

    } else if ( xsdFormElement->getElementType () == "xs:hexBinary" ) {

      QLineEdit *lineEdit = new QLineEdit ();
      lineEdit->setMaximumHeight ( 18 );
      //connect ( lineEdit, SIGNAL (  ), this, SLOT (  ) );
      // TODO: Aquí asignar una acción que al hacer click, llame al colorPicker QColorDialog
      ( ( QGridLayout * ) widget->layout () )->addWidget ( lineEdit, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

    } else if ( xsdFormElement->getElementType () == "xs:integer" ) {

      QSpinBox *spinBox = new QSpinBox ( widget );
      spinBox->setMaximumHeight ( 18 );
      ( ( QGridLayout * ) widget->layout () )->addWidget ( spinBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
    }
  }
}

void XsdFormCreator::createParams ( QWidget *widget, QList<XsdFormElement *> xsdFormElementList ) {

  QListIterator<XsdFormElement *> paramsIterator ( xsdFormElementList );
  while ( paramsIterator.hasNext () ) {

    XsdFormElement *xsdFormElement = paramsIterator.next ();
    if ( xsdFormElement->getFormElementType () == XsdEngine::GROUP ) {

      this->createGroup ( widget, xsdFormElement );

    } else {

      this->createParam ( widget, xsdFormElement );
      ( ( QGridLayout * ) widget->layout () )->setColumnStretch ( ( ( QGridLayout * ) widget->layout () )->columnCount (), 1 );
    }
  }
}

void XsdFormCreator::createTab ( XsdFormElement *xsdFormElement ) {

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
  this->tabsDialog->addTab ( tabWidget, xsdFormElement->getElementName () );
  const int tabsCount = xsdFormElement->getElementsList ().count ();
  if ( tabsCount > 0 ) {

    this->createParams ( internalTabWidget, xsdFormElement->getElementsList () );
    internalTabWidgetLayout->setRowStretch ( internalTabWidgetLayout->rowCount (), 1 );
  }
}

void XsdFormCreator::createTabs ( QList<XsdFormElement *> xsdFormElementList ) {

  QListIterator<XsdFormElement *> tabsIterator ( xsdFormElementList );
  while ( tabsIterator.hasNext () ) {

    this->createTab ( tabsIterator.next () );
  }
}

void XsdFormCreator::createType ( QWidget *widget, XsdFormElement *xsdFormElement ) {

  if ( xsdFormElement->getElementType () == "xs:string" ) {

    QLineEdit *lineEdit = new QLineEdit ();
    lineEdit->setMaximumHeight ( 14 );
    ( ( QGridLayout * ) widget->layout () )->addWidget ( lineEdit, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

  } else if ( xsdFormElement->getElementType () == "xs:integer" ) {

    QSpinBox *spinBox = new QSpinBox ( widget );
    spinBox->setMaximumHeight ( 18 );
    ( ( QGridLayout * ) widget->layout () )->addWidget ( spinBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

  } else if ( xsdFormElement->getElementType () == "xs:hexBinary" ) {

    QLineEdit *lineEdit = new QLineEdit ();
    lineEdit->setMaximumHeight ( 18 );
    ( ( QGridLayout * ) widget->layout () )->addWidget ( lineEdit, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

  } else if ( xsdFormElement->getElementType () == "xs:enumeration" ) {

    ( ( QComboBox * ) widget )->addItem ( xsdFormElement->getElementValue () );
  }
}

void XsdFormCreator::createTypes ( QWidget *widget, QList<XsdFormElement *> xsdFormElementList ) {

  QListIterator<XsdFormElement *> typesIterator ( xsdFormElementList );
  while ( typesIterator.hasNext () ) {

    this->createType ( widget, typesIterator.next () );
  }
}

void XsdFormCreator::showForm () {

  this->formDialog->show ();
}
