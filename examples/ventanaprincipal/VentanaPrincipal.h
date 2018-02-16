#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

// Librerías Internas

// Librerías Externas
#include "MainWindow.h"

// Librerías Qt
#include <QMainWindow>


class VentanaPrincipal : public Com::Ecosoftware::Window::MainWindow::MainWindow {

    Q_OBJECT

  public:
    explicit VentanaPrincipal ( QSettings *settings, QWidget *parent = 0 );

    //void listarElementos ( Com::Ecosoftware::Engines::XsdEngine::XsdFormElement *xsdFormElement );
    void listarNuevosElementos ( Com::Ecosoftware::Engines::Xsd::XsdElement *xsdElement );

  signals:

  public slots:
};

#endif // VENTANAPRINCIPAL_H
