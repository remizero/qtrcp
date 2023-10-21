#ifndef PLUGIN_1_GLOBAL_H
#define PLUGIN_1_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PLUGIN_1_LIBRARY)
#  define PLUGIN_1_EXPORT Q_DECL_EXPORT
#else
#  define PLUGIN_1_EXPORT Q_DECL_IMPORT
#endif

#define NAMESPACE_PLUGIN_1 Plugin_1
#define NAMESPACE_LIBRARY_PLUGIN_1 Com::Vgvgs::Plugin_1

#endif // PLUGIN_1_GLOBAL_H
