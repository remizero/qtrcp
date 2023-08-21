#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

// Librerías Internas

// Librerías Externas
#include "MainWindow.h"

// Librerías Qt
#include <QMainWindow>


class VentanaPrincipal : public Com::Vgvgs::Window::MainWindow::MainWindow {

    Q_OBJECT

  public :
    explicit VentanaPrincipal ( QSettings *settings, QWidget *parent = nullptr );

  signals:

  public slots :
};

#endif // VENTANAPRINCIPAL_H
