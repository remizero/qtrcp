#include "App.h"


using namespace NAMESPACE_LIBRARY_APP;


App::App ( int &argc, char **argv ) : QApplication ( argc, argv ) {

  for ( int i = 1; i < argc; ++i ) {

    if ( qstrcmp ( argv [ i ], "-no-gui" ) ) {

      this->application = new QCoreApplication ( argc, argv );
      break;
    }
  }
  if ( this->application == nullptr ) {

    this->application = new QApplication ( argc, argv );
  }
}

App::~App () {}

QCoreApplication *App::getApplication () {

  return this->application;
}

bool App::notify ( QObject *receiver, QEvent *event ) {

  /*
   * TODO Que hacer aquí?
   * El propósito principal de QApplication::notify es permitir la personalización
   * y control de cómo se manejan los eventos en tu aplicación. En lugar de enviar
   * directamente el evento al receptor a través del sistema de manejo de eventos
   * estándar de Qt, este método proporciona una oportunidad para interceptar el
   * evento antes de que llegue al receptor y para realizar ciertas operaciones
   * personalizadas.
   *
   * Personalización de Eventos: Puedes usar este método para personalizar el
   * manejo de eventos para objetos específicos. Por ejemplo, podrías interceptar
   * ciertos eventos y realizar acciones adicionales antes de que el receptor los
   * maneje.
   *
   * Registro y Depuración: Al interceptar los eventos antes de que se manejen,
   * puedes registrar o depurar información sobre los eventos que ocurren en tu
   * aplicación. Esto puede ser útil para el análisis de problemas y el seguimiento
   * de eventos en tiempo de ejecución.
   *
   * Filtrado de Eventos: Puedes implementar reglas de filtrado para decidir si
   * un evento debe ser entregado al receptor o no. Esto puede ser útil para manejar
   * casos específicos o bloquear eventos no deseados.
   *
   * Implementación de Comportamiento Global: Puedes usar este método para implementar
   * comportamientos generales que deben aplicarse a múltiples objetos receptores.
   * Por ejemplo, podrías establecer una política de manejo de eventos coherente
   * en toda la aplicación.
   */
  try {

    return QApplication::notify ( receiver, event );

  } catch ( std::exception &e ) {

    qCritical () << "Exception thrown:" << e.what ();
  }
  return false;
}
