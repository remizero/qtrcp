#ifndef SHADOW_GLOBAL_H
#define SHADOW_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SHADOW_LIBRARY)
#  define SHADOW_EXPORT Q_DECL_EXPORT
#else
#  define SHADOW_EXPORT Q_DECL_IMPORT
#endif

#endif // SHADOW_GLOBAL_H
