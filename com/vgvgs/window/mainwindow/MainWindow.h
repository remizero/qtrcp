#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Librerías Internas
// Internal Libraries
#include "mainwindow_global.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "MainWindowEvents.h"
#include "MainWindowSignals.h"
#include "MainWindowSlots.h"

// Librerías Externas
// External Libraries
#include "AppInit.h"
#include "AppPaths.h"
#include "MenuBar.h"
#include "StatusBar.h"
#include "SystemTrayIcon.h"

// Librerías Qt
// Qt Libraries
#include <QApplication>
#include <QDebug>
#include <QEvent>
#include <QMainWindow>
#include <QResizeEvent>
#include <QSettings>
#include <QSystemTrayIcon>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_WINDOW {

      namespace NAMESPACE_MAINWINDOW {

        class MainWindowEvents;
        class MainWindowSlots;

        class MAINWINDOWSHARED_EXPORT MainWindow : public QMainWindow {

            Q_OBJECT

          public :
            explicit MainWindow ( QSettings *settings, QWidget *parent = nullptr );
            ~MainWindow ();

            // static int const EXIT_CODE_REBOOT = -123456789;

            MainWindowSlots *getMainWindowSlots () const;
            QSystemTrayIcon *getSysTrayIcon () const;
            void setVisible ( bool visible ) Q_DECL_OVERRIDE;

          public slots :
            void iconActivated ( QSystemTrayIcon::ActivationReason reason );

          protected :
            void centerWindow ();
            virtual void changeEvent( QEvent *event ) Q_DECL_OVERRIDE;
            void closeEvent ( QCloseEvent *event ) Q_DECL_OVERRIDE;
            void createMenuBar ();
            void createStatusBar ();
            void init ( QSettings *settings );
            void loadSettins ();
            void resizeEvent ( QResizeEvent *event ) Q_DECL_OVERRIDE;
            void saveSettings ();
            void setMinimunWindowSize ();

          private :
                                            MainWindowEvents *mainWindowEvents;
                                           MainWindowSignals *mainWindowSignals;
                                             MainWindowSlots *mainWindowSlots;
            NAMESPACE_LIBRARY_SYSTEMTRAYICON::SystemTrayIcon *sysTrayIcon;

            void createSysTrayIcon ();
        };
      }
    }
  }
}

#endif // MAINWINDOW_H
