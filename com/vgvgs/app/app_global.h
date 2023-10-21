#ifndef APP_GLOBAL_H
#define APP_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(APP_LIBRARY)
  #define APPSHARED_EXPORT Q_DECL_EXPORT
#else
  #define APPSHARED_EXPORT Q_DECL_IMPORT
#endif

////#ifdef __cplusplus
//#ifndef VERSION_FUNCTION_DECLARED
//#define VERSION_FUNCTION_DECLARED
//extern "C" static QString version () {

//  return "0.0.2";
//}
//#endif

////#ifdef __cplusplus
////extern "C" {
////#endif

////#ifndef VERSION_FUNCTION_DECLARED
////#define VERSION_FUNCTION_DECLARED
////static QString version () {
////  return "0.0.2";
////}
////#endif

////#ifdef __cplusplus
////}
////#endif

#endif // APP_GLOBAL_H
