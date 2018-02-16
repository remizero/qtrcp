#include "MainWindowEvents.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QDockWidget>

using namespace Com::Ecosoftware::Window::MainWindow;

MainWindowEvents::MainWindowEvents ( QMainWindow *parent ) {

  this->parent = parent;
}

void MainWindowEvents::adjustMaximizedSize ( QMainWindow *parent ) {

    /**
     * Para probar si se puede evitar que el centralWidget no se expanda :)
     * http://stackoverflow.com/questions/2722939/c-resize-a-docked-qt-qdockwidget-programmatically?rq=1
     * http://qt-project.org/doc/qt-4.8/widgets-scribble.html
     * http://stackoverflow.com/questions/25505041/resize-qmainwindow-to-fit-qdockwidget-size
     * http://stackoverflow.com/questions/26286646/create-a-qdockwidget-that-resizes-to-its-contents
     *
     * TOMAR LA LISTA DE DOCKEDWINDOWS Y HACER LO SIGUIENTE
     *
     * dock1->setFixedHeight ( QApplication::desktop ()->screen ()->height () - 100 );
     * dock2->setFixedHeight ( QApplication::desktop ()->screen ()->height () - 100 );
     *
     * VER COMO HACER USO DEL 100 PERO CON UNA VARIABLE O CON EL MINIMUNSIZE DEL REPRODUCTOR
     */

    QList<QDockWidget *> dockWidgets = parent->findChildren<QDockWidget *> ();
    QListIterator<QDockWidget *> dockWidgetIterator ( dockWidgets );

    while ( dockWidgetIterator.hasNext () ) {

        QDockWidget *dockWidget = dockWidgetIterator.next ();
        //dockWidget->setFixedHeight ( QApplication::desktop ()->screen ()->height () - 100 );
        dockWidget->setFixedHeight ( QApplication::desktop ()->screen ()->height () - 200 );
    }
}

void MainWindowEvents::adjustMinimizedSize ( QMainWindow *parent ) {

    /**
     * TOMAR LA LISTA DE DOCKEDWINDOWS Y HACER LO SIGUIENTE
     *
     * dock1->setFixedHeight ( 150 );
     * dock2->setFixedHeight ( 150 );
     *
     * VER COMO HACER USO DEL 150 PERO CON UNA VARIABLE O CON EL MINIMUNSIZE DE LOS DOCKWINDOWS
     */
    QList<QDockWidget *> dockWidgets = parent->findChildren<QDockWidget *> ();
    QListIterator<QDockWidget *> dockWidgetIterator ( dockWidgets );

    while ( dockWidgetIterator.hasNext () ) {

        QDockWidget *dockWidget = dockWidgetIterator.next ();
        //dockWidget->setFixedHeight ( 250 );
        dockWidget->setFixedHeight ( 220 );
    }
}

void MainWindowEvents::changeEvent ( QEvent *event ) {

  if ( event->type () == QEvent::WindowStateChange ) {

    if ( this->parent->isMaximized () ) {

      adjustMaximizedSize ( this->parent );

    } else if ( this->parent->isMinimized () ) {

      //QMessageBox::information(this, tr("Información"), tr("Esta ventana ha sido minimizada." ) );

    } else if ( this->parent->isHidden () ) {

      //MessageBox::information(this, tr("Información"), tr("Esta ventana ha sido ocultada." ) );

    } else if ( this->parent->isFullScreen () ) {

      //QMessageBox::information(this, tr("Información"), tr("Esta ventana ha sido ocultada." ) );

    } else if ( this->parent->isVisible () ) {

      adjustMinimizedSize ( this->parent );
    }
  }
}

void MainWindowEvents::closeEvent ( QCloseEvent *event ) {
  /*
   * Aquí código para hacer lo que se vaya a hacer al cerrar la ventana
   * principal de la aplicación.
   */
  /*if ( this->sysTrayIcon->isVisible () ) {

      QMessageBox::information ( this, tr ( "Rockola" ),
                               tr ( "Usted ha solicitado cerrar el programa "
                                    "pero seguirá en ejecución oculta."
                                    "Usted puede terminar la ejecución de este"
                                    "programa en la opción <b>Salir</b> del"
                                    "menú contextual del icono en la bandeja"
                                    "del sistema, o bien desactivar el icon tray." ) );
      this->hide ();
      event->ignore ();
      return;
  }*/
  event->accept ();
}

void MainWindowEvents::resizeEvent ( QResizeEvent *event ) {

  /**
   * Para probar si se puede evitar que el centralWidget no se expanda :)
   * http://stackoverflow.com/questions/2722939/c-resize-a-docked-qt-qdockwidget-programmatically?rq=1
   * http://qt-project.org/doc/qt-4.8/widgets-scribble.html
   * http://stackoverflow.com/questions/25505041/resize-qmainwindow-to-fit-qdockwidget-size
   * http://stackoverflow.com/questions/26286646/create-a-qdockwidget-that-resizes-to-its-contents
   */
  //QMessageBox::information ( this, "Información", "La ventana a cambiado de tamaño" );
  //QDockWidget::resizeEvent ( event );
  //emit sizeChanged ( event->size () );
  /**
   * Borrar esto cuando se tenga definido el código de este método.
   */
  event->accept ();
}
