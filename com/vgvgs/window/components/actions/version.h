#ifndef VERSION_H
#define VERSION_H

// Librerías Internas
// Internal Libraries
#include "actions_global.h"

// Librerías Qt
// Qt Libraries
#include <QString>

extern "C" ACTIONSSHARED_EXPORT QString version () {

  return "0.0.2";
}

#endif // VERSION_H
