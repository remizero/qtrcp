#ifndef MACROS_GLOBAL_H
#define MACROS_GLOBAL_H

#include <QtCore/qglobal.h>


#if defined(MACROS_LIBRARY)
#  define MACROS_EXPORT Q_DECL_EXPORT
#else
#  define MACROS_EXPORT Q_DECL_IMPORT
#endif

#define BASIC_STR(x) #x
#define STR(x) BASIC_STR(x)

#define DEFAULT_QT_MESSAGE_PATTERN \033[0;34m[ %{time yyyy-MM-ddThh:mm:ss t} ] \033[1;31m[ %{if-critical}CRITICAL%{endif}%{if-debug}DEBUG%{endif}%{if-fatal}FATAL%{endif}%{if-info}INFO%{endif}%{if-warning}WARNING%{endif} ] \033[1;36m[ PID - %{pid} ] [ THREAD_ID - %{threadid} ] [ QT_THREAD_PTR - %{qthreadptr} ] \033[1;33m[ APPNAME - %{appname} ] [ FILE - %{file} ] [ FUNCTION - %{function} ] [ LINE - %{line} ] [ MESSAGE_ERROR - %{message} ] \033[1;37m[ BACKTRACE - %{backtrace depth=10} ] \033[0m
#define FILE_OUTPUT_QT_MESSAGE_PATTERN [ %{time yyyy-MM-ddThh:mm:ss t} ] [ %{if-critical}CRITICAL%{endif}%{if-debug}DEBUG%{endif}%{if-fatal}FATAL%{endif}%{if-info}INFO%{endif}%{if-warning}WARNING%{endif} ] [ PID - %{pid} ] [ THREAD_ID - %{threadid} ] [ QT_THREAD_PTR - %{qthreadptr} ] [ APPNAME - %{appname} ] [ FILE - %{file} ] [ FUNCTION - %{function} ] [ LINE - %{line} ] [ MESSAGE_ERROR - %{message} ] [ BACKTRACE - %{backtrace depth=10} ]


// Se definen las macros comunes para todos los espacios de nombre de las librerías.
// Common macros are defined for all library namespaces.
#define TOKEN_SEPARATOR   ::
#define NAMESPACE_LEVEL_1 Com
#define NAMESPACE_LEVEL_2 Vgvgs


// Se definen las macros particulares para todos los espacios de nombre de las librerías.
// Particular macros are defined for all library namespaces.
#define NAMESPACE_APP            App
#define NAMESPACE_CONSOLE        Console
#define NAMESPACE_CORE           Core
#define NAMESPACE_ENGINES        Engines
#define NAMESPACE_XSD            Xsd
#define NAMESPACE_XSDFORM        XsdForm
#define NAMESPACE_LOGGER         Logger
#define NAMESPACE_MACROS         Macros
#define NAMESPACE_PATTERNIFY     Patternify
#define NAMESPACE_RESOURCES      Resources
#define NAMESPACE_SINGLEINSTANCE SingleInstance
#define NAMESPACE_SPLASHSCREEN   SplashScreen
#define NAMESPACE_UTILS          Utils
#define NAMESPACE_WINDOW         Window
#define NAMESPACE_COMPONENTS     Components
#define NAMESPACE_ACTIONS        Actions
#define NAMESPACE_COLORBOX       ColorBox
#define NAMESPACE_COLORPICKER    ColorPicker
#define NAMESPACE_MENUBAR        MenuBar
#define NAMESPACE_STATUSBAR      StatusBar
#define NAMESPACE_SYSTEMTRAYICON SystemTrayIcon
#define NAMESPACE_MAINWINDOW     MainWindow


// Se definen las macros con los nombres completos para todos los espacios de nombre de las librerías.
// Macros with fully qualified names are defined for all library namespaces.
#define NAMESPACE_LIBRARY_APP            Com::Vgvgs::App
#define NAMESPACE_LIBRARY_CONSOLE        Com::Vgvgs::Console
#define NAMESPACE_LIBRARY_CORE           Com::Vgvgs::Core
#define NAMESPACE_LIBRARY_XSD            Com::Vgvgs::Engines::Xsd
#define NAMESPACE_LIBRARY_LOGGER         Com::Vgvgs::Logger
#define NAMESPACE_LIBRARY_MACROS         Com::Vgvgs::Macros
#define NAMESPACE_LIBRARY_PATTERNIFY     Com::Vgvgs::Patternify
#define NAMESPACE_LIBRARY_RESOURCES      Com::Vgvgs::Resources
#define NAMESPACE_LIBRARY_SINGLEINSTANCE Com::Vgvgs::SingleInstance
#define NAMESPACE_LIBRARY_SPLASHSCREEN   Com::Vgvgs::SplashScreen
#define NAMESPACE_LIBRARY_UTILS          Com::Vgvgs::Utils
#define NAMESPACE_LIBRARY_ACTONS         Com::Vgvgs::Window::Components::Actions
#define NAMESPACE_LIBRARY_COLORBOX       Com::Vgvgs::Window::Components::ColorBox
#define NAMESPACE_LIBRARY_COLORPICKER    Com::Vgvgs::Window::Components::ColorPicker
#define NAMESPACE_LIBRARY_MENUBAR        Com::Vgvgs::Window::Components::MenuBar
#define NAMESPACE_LIBRARY_STATUSBAR      Com::Vgvgs::Window::Components::StatusBar
#define NAMESPACE_LIBRARY_SYSTEMTRAYICON Com::Vgvgs::Window::Components::SystemTrayIcon
#define NAMESPACE_LIBRARY_XSDFORM        Com::Vgvgs::Window::Components::XsdForm
#define NAMESPACE_LIBRARY_MAINWINDOW     Com::Vgvgs::Window::MainWindow


#endif // MACROS_GLOBAL_H
