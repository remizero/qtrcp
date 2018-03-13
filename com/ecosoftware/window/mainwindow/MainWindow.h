#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Librerías Internas
#include "mainwindow_global.h"
#include "MainWindowEvents.h"
#include "MainWindowSignals.h"
#include "MainWindowSlots.h"

// Librerías Externas
#include "AppInit.h"
#include "AppPaths.h"
#include "MenuBar.h"
#include "StatusBar.h"
#include "SystemTrayIcon.h"

// Librerías Qt
#include <QMainWindow>
#include <QSettings>
#include <QSystemTrayIcon>

namespace Com {

  namespace Ecosoftware {

    namespace Window {

      namespace MainWindow {

        class MainWindowEvents;
        class MainWindowSlots;

        class MAINWINDOWSHARED_EXPORT MainWindow : public QMainWindow {

            Q_OBJECT

          public:
            explicit MainWindow ( QSettings *settings, QWidget *parent = 0 );
            ~MainWindow ();

            static int const EXIT_CODE_REBOOT = -123456789;

            MainWindowSlots *getMainWindowSlots () const;
            QSystemTrayIcon *getSysTrayIcon () const;
            void setVisible ( bool visible ) override;

          public slots:
            void iconActivated ( QSystemTrayIcon::ActivationReason reason );

          protected:
            void centerWindow ();
            virtual void changeEvent( QEvent *event ) override;
            void closeEvent ( QCloseEvent *event ) override;
            void createMenuBar ();
            void createStatusBar ();
            void init ( QSettings *settings );
            void loadSettins ();
            void resizeEvent ( QResizeEvent *event ) override;
            void saveSettings ();
            void setMinimunWindowSize ();

          private:
             MainWindowEvents *mainWindowEvents;
            MainWindowSignals *mainWindowSignals;
              MainWindowSlots *mainWindowSlots;

              Components::SystemTrayIcon::SystemTrayIcon *sysTrayIcon;

                void createSysTrayIcon ();
        };
      }
    }
  }
}

#endif // MAINWINDOW_H
