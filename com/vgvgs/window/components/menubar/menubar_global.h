#ifndef MENUBAR_GLOBAL_H
#define MENUBAR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MENUBAR_LIBRARY)
#  define MENUBARSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MENUBARSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MENUBAR_GLOBAL_H
