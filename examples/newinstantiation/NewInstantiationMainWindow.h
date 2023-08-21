#ifndef NEWINSTANTIATIONMAINWINDOW_H
#define NEWINSTANTIATIONMAINWINDOW_H

// Librerías Internas

// Librerías Externas
#include "MainWindow.h"

class NewInstantiationMainWindow : public Com::Vgvgs::Window::MainWindow::MainWindow {

    Q_OBJECT

  public :
    NewInstantiationMainWindow ( QSettings *settings, QWidget *parent = nullptr );
    ~NewInstantiationMainWindow ();

  signals:

  public slots :
};

#endif // NEWINSTANTIATIONMAINWINDOW_H
