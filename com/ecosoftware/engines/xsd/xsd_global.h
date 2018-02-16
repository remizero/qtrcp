#ifndef XSD_GLOBAL_H
#define XSD_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(XSD_LIBRARY)
#  define XSDSHARED_EXPORT Q_DECL_EXPORT
#else
#  define XSDSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // XSD_GLOBAL_H
