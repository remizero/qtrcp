#ifndef COLORBOX_GLOBAL_H
#define COLORBOX_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(COLORBOX_LIBRARY)
#  define COLORBOX_EXPORT Q_DECL_EXPORT
#else
#  define COLORBOX_EXPORT Q_DECL_IMPORT
#endif

#endif // COLORBOX_GLOBAL_H
