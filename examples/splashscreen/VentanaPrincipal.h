#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

// Librerías Externas
#include "MainWindow.h"

class VentanaPrincipal : public Com::Ecosoftware::Window::MainWindow::MainWindow {

    Q_OBJECT

  public:
    explicit VentanaPrincipal ( QSettings *settings, QWidget *parent = 0 );
    ~VentanaPrincipal ();
};

#endif // VENTANAPRINCIPAL_H
