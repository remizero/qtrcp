#ifndef MACROS_GLOBAL_H
#define MACROS_GLOBAL_H

#include <QtCore/qglobal.h>


#if defined(MACROS_LIBRARY)
#  define MACROS_EXPORT Q_DECL_EXPORT
#else
#  define MACROS_EXPORT Q_DECL_IMPORT
#endif


// Se definen las macros comunes para todos los espacios de nombre de las librerías.
#define TOKEN_SEPARATOR   ::
#define NAMESPACE_LEVEL_1 Com
#define NAMESPACE_LEVEL_2 Vgvgs


// Se definen las macros particulares para todos los espacios de nombre de las
// librerías.
#define NAMESPACE_APP            App
#define NAMESPACE_CONSOLE        Console
#define NAMESPACE_ENGINES        Engines
#define NAMESPACE_XSD            Xsd
#define NAMESPACE_XSDFORM        XsdForm
#define NAMESPACE_LOGGER         Logger
#define NAMESPACE_MACROS         Macros
#define NAMESPACE_RESOURCES      Resources
#define NAMESPACE_SINGLEINSTANCE SingleInstance
#define NAMESPACE_SPLASHSCREEN   SplashScreen
#define NAMESPACE_UTILS          Utils
#define NAMESPACE_WINDOW         Window
#define NAMESPACE_COMPONENTS     Components
#define NAMESPACE_ACTIONS        Actions
#define NAMESPACE_MENUBAR        MenuBar
#define NAMESPACE_STATUSBAR      StatusBar
#define NAMESPACE_SYSTEMTRAYICON SystemTrayIcon
#define NAMESPACE_MAINWINDOW     MainWindow


// Se definen las macros con los nombres completos para todos los espacios de
// nombre de las librerías.
#define NAMESPACE_LIBRARY_APP            Com::Vgvgs::App
#define NAMESPACE_LIBRARY_CONSOLE        Com::Vgvgs::Console
#define NAMESPACE_LIBRARY_XSD            Com::Vgvgs::Engines::Xsd
#define NAMESPACE_LIBRARY_XSDFORM        Com::Vgvgs::Engines::XsdForm
#define NAMESPACE_LIBRARY_LOGGER         Com::Vgvgs::Logger
#define NAMESPACE_LIBRARY_MACROS         Com::Vgvgs::Macros
#define NAMESPACE_LIBRARY_RESOURCES      Com::Vgvgs::Resources
#define NAMESPACE_LIBRARY_SINGLEINSTANCE Com::Vgvgs::SingleInstance
#define NAMESPACE_LIBRARY_SPLASHSCREEN   Com::Vgvgs::SplashScreen
#define NAMESPACE_LIBRARY_UTILS          Com::Vgvgs::Utils
#define NAMESPACE_LIBRARY_ACTONS         Com::Vgvgs::Window::Components::Actions
#define NAMESPACE_LIBRARY_MENUBAR        Com::Vgvgs::Window::Components::MenuBar
#define NAMESPACE_LIBRARY_STATUSBAR      Com::Vgvgs::Window::Components::StatusBar
#define NAMESPACE_LIBRARY_SYSTEMTRAYICON Com::Vgvgs::Window::Components::SystemTrayIcon
#define NAMESPACE_LIBRARY_MAINWINDOW     Com::Vgvgs::Window::MainWindow


#endif // MACROS_GLOBAL_H
