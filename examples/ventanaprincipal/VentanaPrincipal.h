#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

// Librerías Internas
// Internal Libraries

// Librerías Externas
// External Libraries
#include "MainWindow.h"

// Librerías Qt
// Qt Libraries
#include <QMainWindow>


class VentanaPrincipal : public Com::Vgvgs::Window::MainWindow::MainWindow {

    Q_OBJECT

  public :
    explicit VentanaPrincipal ( QSettings *settings, QWidget *parent = nullptr );

  signals:

  public slots :
};

#endif // VENTANAPRINCIPAL_H
