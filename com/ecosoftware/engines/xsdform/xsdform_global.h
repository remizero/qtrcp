#ifndef XSDFORM_GLOBAL_H
#define XSDFORM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(XSDFORM_LIBRARY)
#  define XSDFORMSHARED_EXPORT Q_DECL_EXPORT
#else
#  define XSDFORMSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // XSDFORM_GLOBAL_H
