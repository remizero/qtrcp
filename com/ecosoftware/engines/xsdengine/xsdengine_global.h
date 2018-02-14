#ifndef XSDENGINE_GLOBAL_H
#define XSDENGINE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(XSDENGINE_LIBRARY)
#  define XSDENGINESHARED_EXPORT Q_DECL_EXPORT
#else
#  define XSDENGINESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // XSDENGINE_GLOBAL_H
