#include "NewInstantiationMainWindow.h"

#include <QDebug>

NewInstantiationMainWindow::NewInstantiationMainWindow ( QSettings *settings, QWidget *parent ) : Com::Vgvgs::Window::MainWindow::MainWindow ( settings, parent ) {

  Q_INIT_RESOURCE ( xsdresources );
}

NewInstantiationMainWindow::~NewInstantiationMainWindow () {}
