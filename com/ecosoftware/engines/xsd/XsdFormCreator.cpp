#include "XsdFormCreator.h"
#include <QDebug>

using namespace Com::Ecosoftware::Engines::Xsd;

XsdFormCreator::XsdFormCreator () {}

void XsdFormCreator::createForm ( XsdElement *xsdElement, QWidget *parent ) {

  this->nuevaEstrategia ( xsdElement, parent );
  //this->formDialog = new QDialog ( parent );
  //this->formDialog->setMinimumSize ( 800, 600 );
  //this->formDialog->setWindowTitle ( ( ( NameProperty * ) xsdElement->getProperty ( "name" ) )->getValue () );
  //QVBoxLayout *formDialogLayout = new QVBoxLayout ( this->formDialog );
  //this->formDialog->setLayout ( formDialogLayout );
//this->tabsDialog = new QTabWidget ( parent );
  //QDialogButtonBox *buttonBox = new QDialogButtonBox ( this->formDialog );
  //buttonBox->setStandardButtons ( QDialogButtonBox::Ok | QDialogButtonBox::Apply | QDialogButtonBox::Cancel );
  //formDialogLayout->addWidget ( this->tabsDialog );
  //formDialogLayout->addWidget ( buttonBox );
  //this->formDialog->connect ( buttonBox, SIGNAL ( rejected () ), this->formDialog, SLOT ( reject () ) );

  /*const int tabsCount = xsdElement->getElementsList ().count ();
  if ( tabsCount > 0 ) {

    this->createTabs ( xsdElement->getElementsList () );
  }*/
}

void XsdFormCreator::createGroup ( QWidget *widget, XsdElement *xsdElement ) {

  //qDebug () << "Si entra en el método XsdFormCreator::createGroup ";
  QGroupBox *groupBoxElement = new QGroupBox ( widget );
  //qDebug () << "Creando el grupo de parámetros de: " << ( ( NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue ();
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

  qDebug () << "Si entra en el método XsdFormCreator::createParam ";
  qDebug () << "Creando el parámetro: " << ( ( NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue ();
  QLabel *paramLabel = new QLabel ( widget );
  //qDebug () << xsdElement->getProperties ().count ();
  //qDebug () << ( ( NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue ();
  //qDebug () << ( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->toInt ();
  //qDebug () << ( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->toString ();
  qDebug () << "El rollo está cuando solicita el NameProperty ";
  paramLabel->setText ( ( ( NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
  ( ( QGridLayout * ) widget->layout () )->addWidget ( paramLabel, ( ( QGridLayout * ) widget->layout () )->rowCount (), 0, 1, 1, Qt::AlignRight );
  const int paramsCount = xsdElement->getElementsList ().count ();
  qDebug () << "Segun esto se busca en la lista de elementos, y tiene: " << paramsCount << " Elementos";

  const int facetsCount = xsdElement->getFacets ().count ();
  qDebug () << "Pero debería buscar los FACETS del elemento, y tiene: " << facetsCount << " FACETAS";
  if ( facetsCount > 0 ) {

    for ( int i = 0; i < facetsCount; i++ ) {

      qDebug () << "El tipo a determinar es: " << xsdElement->getProperty ( "TypeProperty" )->metaObject ()->className ();
      TypeProperty *objTypeProperty = ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" );
      qDebug () << "El tipo a determinar es: " << ( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->metaObject ()->className ();
      qDebug () << "El tipo a determinar es: " << objTypeProperty->getValue ();
      qDebug () << "El tipo a determinar es: " << ( TypeAbs::types ) ( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->toInt ();
      qDebug () << "El tipo a determinar es: " << ( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->toString ();
      if ( ( ( TypeAbs::types ) ( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->toInt () ) == TypeAbs::INTEGER ) {

        qDebug () << xsdElement->getFacets ().at ( i )->metaObject ()->className ();
        if ( xsdElement->getFacets ().at ( i )->metaObject ()->className () == "xs:enumeration" ) {

        }
      }
    }
  } else {

    qDebug () << "El tipo a determinar es: " << xsdElement->getProperty ( "TypeProperty" )->metaObject ()->className ();
    TypeProperty *objTypeProperty = ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" );
    qDebug () << "El tipo a determinar es: " << ( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->metaObject ()->className ();
    qDebug () << "El tipo a determinar es: " << objTypeProperty->getValue ();
    qDebug () << "El tipo a determinar es: " << ( TypeAbs::types ) ( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->toInt ();
    qDebug () << "El tipo a determinar es: " << ( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->toString ();
    if ( ( ( TypeAbs::types ) ( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->toInt () ) == TypeAbs::INTEGER ) {

      //qDebug () << xsdElement->getFacets ().at ( i )->metaObject ()->className ();
      QSpinBox *spinBox = new QSpinBox ( widget );
      spinBox->setMaximumHeight ( 18 );
      ( ( QGridLayout * ) widget->layout () )->addWidget ( spinBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
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

  qDebug () << "Si entra en el método XsdFormCreator::createParams ";

  const int paramsCount = xsdElementList.count ();
  for ( int i = 0; i < paramsCount; i++ ) {

    XsdElement *xsdElement = xsdElementList.at ( i );
    qDebug () << "------------------" << Xsd::levelEnumToString ( xsdElement->getElementLevel () );
    if ( xsdElement->getElementLevel () == Xsd::GROUPFORM ) {

      this->createGroup ( widget, xsdElement );

    } else {

      this->createParam ( widget, xsdElement );
      ( ( QGridLayout * ) widget->layout () )->setColumnStretch ( ( ( QGridLayout * ) widget->layout () )->columnCount (), 1 );
    }
  }

/*
  QListIterator<XsdElement *> paramsIterator ( xsdElementList );
  while ( paramsIterator.hasNext () ) {

    XsdElement *xsdElement = paramsIterator.next ();
    qDebug () << "------------------" << Xsd::levelEnumToString ( xsdElement->getElementLevel () );
    if ( xsdElement->getElementLevel () == Xsd::GROUPFORM ) {

      this->createGroup ( widget, xsdElement );

    } else {

      this->createParam ( widget, xsdElement );
      ( ( QGridLayout * ) widget->layout () )->setColumnStretch ( ( ( QGridLayout * ) widget->layout () )->columnCount (), 1 );
    }
  }*/
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
  // TODO: Como obtener el nombre del elemento
  //qDebug () << "Creando la pestaña: " << ( ( NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue ();
  this->tabsDialog->addTab ( tabWidget, ( ( NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
  const int tabsCount = xsdElement->getElementsList ().count ();
  if ( tabsCount > 0 ) {

    this->createParams ( internalTabWidget, xsdElement->getElementsList () );
    internalTabWidgetLayout->setRowStretch ( internalTabWidgetLayout->rowCount (), 1 );
  }
}

void XsdFormCreator::createTabs ( QList<XsdElement *> xsdElementList ) {

  qDebug () << "Creando las pestañas -------------------------------------------";
  const int tabsCount = xsdElementList.count ();
  for ( int i = 0; i < tabsCount; i++ ) {

    this->createTab ( xsdElementList.at ( i ) );
  }


  /*QListIterator<XsdElement *> tabsIterator ( xsdElementList );
  while ( tabsIterator.hasNext () ) {

    this->createTab ( tabsIterator.next () );
  }*/
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

void XsdFormCreator::nuevaEstrategia ( XsdElement *xsdElement, QWidget *parent ) {

  /*qDebug () << ( ( NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue ();

  QListIterator<XsdElement *> tabsIterator ( xsdElement->getElementsList () );
  while ( tabsIterator.hasNext () ) {

    XsdElement *tabElement = tabsIterator.next ();
    qDebug () << "    " << ( ( NameProperty * ) tabElement->getProperty ( "NameProperty" ) )->getValue ();
    qDebug () << "    " << ( ( TypeProperty * ) tabElement->getProperty ( "TypeProperty" ) )->getValue ();
    if ( tabElement->getFacets ().count () > 0 ) {

      qDebug () << "    " << "Tiene " << tabElement->getFacets ().count () << "FACETS";
      QListIterator<FacetAbs *> facetsTabsIterator ( xsdElement->getFacets () );
      while ( facetsTabsIterator.hasNext () ) {

        FacetAbs *facetTabElement = facetsTabsIterator.next ();
        qDebug () << "        " << "El valor del FACET es: " << facetTabElement->getValue ();
      }
    }
    if ( tabElement->getElementsList ().count () > 0 ) {

      qDebug () << "    " << "Tiene " << tabElement->getElementsList ().count () << "ELEMENTS";
      QListIterator<XsdElement *> paramsTabsIterator ( tabElement->getElementsList () );
      while ( paramsTabsIterator.hasNext () ) {

        XsdElement *paramTabElement = paramsTabsIterator.next ();
        qDebug () << "        " << ( ( NameProperty * ) paramTabElement->getProperty ( "NameProperty" ) )->getValue ();
        qDebug () << "        " << ( ( TypeProperty * ) paramTabElement->getProperty ( "TypeProperty" ) )->getValue ();
      }
    }
  }*/

  /*
Buenas amigos, en esta oportunidad vengo con el siguiente problema.

Tengo una lista de elementos definido por mi, de la cual estoy intentando obtener
sus valores, pero al castearlos e imprimirlo me retorna un valor nulo o impreciso.
La lista que uso es como sigue:

QList<PropertyAbs *>

Esto es, porque dispongo de diferentes tipos de propiedades, llamese:

NameProperty
TypeProperty
BaseProperty
...

Todo este código forma parte del subproyecto com->ecosoftware->engines->xsd

Si requieren de código compilable les coloco el enlace al repositorio,
pues se hace bastante complicado aislar solo el código donde se presenta el problema

luego, en la carpeta examples se encontraran con el subproyecto ventanaprincipal, ese
es el proyecto a ejecutar, una vez hecho esto Preference->Configuración del sistema

Luego ir a aplication output en qtcreator y veran en la salida lo siguiente: (veran muchas otras cosas jeje)

1.- El valor CONVERTIDO que trae es:  Com::Ecosoftware::Engines::Xsd::TypeAbs::types(HEXBINARY)
2.- El valor del type guardado es  Com::Ecosoftware::Engines::Xsd::TypeAbs::types(-33686019)


Donde (1) es el valor TypeProperty a guardar y (2) es el valor recuperado y que
intento mostrar, pero parece perderse.

Al recuperarlo lo casteo de la siguiente manera

( ( TypeProperty * ) xsdElement->getProperty ( "TypeProperty" ) )->getValue ();

El error se centra, la clase XsdEngine (.h .cpp), especificamente en los métodos
parse y processProperties, Líneas 1757 a 1763 y 1933 a 1947.
   */

}

