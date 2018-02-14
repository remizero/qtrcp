#ifndef ACTIONS_GLOBAL_H
#define ACTIONS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ACTIONS_LIBRARY)
#  define ACTIONSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ACTIONSSHARED_EXPORT Q_DECL_IMPORT
#endif

// TODO: Definir un enumerado para indicar la prioridad de las acciones del menú.
// Esto es, que las acciones definidas predeterminadas para el sistema deben
// mostrarse en la posición y sección indicada y las acciones de plugins serán
// mostradas en las mismas secciones indicadas pero posterior a las acciones
// predeterminadas para el sistema.

// TODO: Darle nombre a los objetos de las acciones con el nombre de las acciones
// colocando siempre el sufijo Act.

// TODO: esto puede ser en este archivo o en la clase ActionAbs.h

#endif // ACTIONS_GLOBAL_H
