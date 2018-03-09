#include "VentanaPrincipal.h"

#include <QDebug>
#include <QDomDocument>

VentanaPrincipal::VentanaPrincipal ( QSettings *settings, QWidget *parent ) : Com::Ecosoftware::Window::MainWindow::MainWindow ( settings, parent ) {

  Q_INIT_RESOURCE ( xsdresources );
}
