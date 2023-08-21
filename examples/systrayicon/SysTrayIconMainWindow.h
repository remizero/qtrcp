#ifndef SYSTRAYICONMAINWINDOW_H
#define SYSTRAYICONMAINWINDOW_H

// Librerías Internas

// Librerías Externas
#include "AppInit.h"
#include "AppSettings.h"
#include "MainWindow.h"

// Librerías Qt
#include <QCloseEvent>
#include <QMainWindow>
#include <QSystemTrayIcon>

class SysTrayIconMainWindow : public Com::Vgvgs::Window::MainWindow::MainWindow {

    Q_OBJECT

  public :
    explicit SysTrayIconMainWindow ( QSettings *settings, QWidget *parent = nullptr );
    ~SysTrayIconMainWindow ();

  signals:

  public slots :

  protected :
      /**
       * Virtual function of the parent class in our class
       * Overridden to change the behavior of the application,
       * That it is minimized to tray when we want
       */
      //void closeEvent ( QCloseEvent *event );

  private slots:
    /**
     * The slot that will accept the signal from the event
     * Click on the application icon in the system tray
     */
    //void iconActivated ( QSystemTrayIcon::ActivationReason reason );

  private :
    /**
     * Declare the object of future applications for the tray icon
     */
    //QSystemTrayIcon *sysTrayIcon;
};

#endif // SYSTRAYICONMAINWINDOW_H
