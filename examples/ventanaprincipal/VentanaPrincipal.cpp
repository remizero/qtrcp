#include "VentanaPrincipal.h"

#include <QDebug>
#include <QDomDocument>

VentanaPrincipal::VentanaPrincipal ( QSettings *settings, QWidget *parent ) : Com::Ecosoftware::Window::MainWindow::MainWindow ( settings, parent ) {

  Q_INIT_RESOURCE ( xsdresources );
}

void VentanaPrincipal::listarNuevosElementos ( Com::Ecosoftware::Engines::Xsd::XsdElement *xsdElement ) {

}

/*void VentanaPrincipal::listarElementos ( Com::Ecosoftware::Engines::XsdEngine::XsdFormElement *xsdFormElement ) {

  qDebug () << "Nombre de Elemento: " << xsdFormElement->getElementName ();
  qDebug () << "Tipo de Elemento de Formulario: " << xsdFormElement->getFormElementType ();
  qDebug () << "Tipo de Elemento: " << xsdFormElement->getElementType ();
  qDebug () << "Valor del Elemento: " << xsdFormElement->getElementValue ();
  const int contador = xsdFormElement->getElementsList ().count ();
  qDebug () << "Cantidad de elementos hijos: " << contador;
  if ( contador > 0 ) {

    for ( int i = 0; i < contador; i++ ) {

      this->listarElementos ( xsdFormElement->getElementsList ().at ( i ) );
    }
  }
}*/
