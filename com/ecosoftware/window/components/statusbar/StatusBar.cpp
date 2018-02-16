#include "StatusBar.h"

using namespace Com::Ecosoftware::Window::Components::Statusbar;

StatusBar::StatusBar ( QWidget *parent ) : QStatusBar ( parent ) {

  QLabel *etiqueta1 = new QLabel ( this );
  etiqueta1->setText ( "Etiqueta de prueba 1" );
  this->addWidget ( etiqueta1, 1 );

  QLabel *etiqueta2 = new QLabel ( this );
  etiqueta2->setText ( "Etiqueta de prueba 2" );
  this->addWidget ( etiqueta2, 1 );

  QLabel *etiqueta3 = new QLabel ( this );
  etiqueta3->setText ( "Etiqueta de prueba 3" );
  this->addWidget ( etiqueta3, 1 );

  QLabel *etiqueta14 = new QLabel ( this );
  etiqueta14->setText ( "Etiqueta de prueba 4" );
  this->addWidget ( etiqueta14, 1 );
}

StatusBar::~StatusBar () {}

void StatusBar::addNewSection () {
// TODO: Hacer código para agregar una sección.
}

void StatusBar::hideSection () {
  // TODO: Hacer código para ocultar una sección.
}

void StatusBar::showSection () {
  // TODO: Hacer código para mostrar una sección.
}
