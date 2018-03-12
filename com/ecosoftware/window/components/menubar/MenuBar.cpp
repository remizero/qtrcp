#include "MenuBar.h"

using namespace Com::Ecosoftware::Window::Components::Menubar;

MenuBar::MenuBar ( QWidget *parent ) : QMenuBar ( parent ) {

  QMenu *fileMenu = this->addMenu ( tr ( "&File" ) );
  /*fileMenu->addAction ( tr ( "New Project or File." ) );
  fileMenu->addAction ( tr ( "Open Project or File." ) );
  QMenu *recentsProjects = fileMenu->addMenu ( tr ( "Recents Projects." ) );
  recentsProjects->addAction ( tr ( "proyecto 1" ) );
  QMenu *recentsFiles = fileMenu->addMenu ( tr ( "Recents Files." ) );
  recentsFiles->addAction ( tr ( "archivo 1" ) );
  fileMenu->addSeparator ();
  fileMenu->addAction ( tr ( "Save." ) );
  fileMenu->addAction ( tr ( "Save All." ) );
  fileMenu->addAction ( tr ( "Save Project." ) );
  fileMenu->addSeparator ();
  fileMenu->addAction ( tr ( "Close." ) );
  fileMenu->addAction ( tr ( "Close As." ) );
  fileMenu->addAction ( tr ( "Close All." ) );
  fileMenu->addAction ( tr ( "Close All Except Active." ) );
  fileMenu->addSeparator ();
  fileMenu->addAction ( tr ( "Import." ) );
  fileMenu->addAction ( tr ( "Export." ) );
  fileMenu->addSeparator ();
  fileMenu->addAction ( tr ( "Publicar." ) );
  fileMenu->addAction ( tr ( "Producción" ) );
  fileMenu->addSeparator ();
  fileMenu->addAction ( tr ( "Version Control" ) );
  fileMenu->addSeparator ();*/

  Actions::RestartAct *restartAct = new Actions::RestartAct ( "Reiniciar Aplicación", parent );
  fileMenu->addAction ( restartAct );
  fileMenu->addSeparator ();
  Actions::ExitAct *exitAct = new Actions::ExitAct ( "Exit", parent );
  fileMenu->addAction ( exitAct );

  /*QMenu *editMenu = this->addMenu ( tr ( "&Edit" ) );
  editMenu->addAction ( tr ( "Undo." ) );
  editMenu->addAction ( tr ( "Redo." ) );
  editMenu->addAction ( tr ( "Cut." ) );
  editMenu->addAction ( tr ( "Copy." ) );
  editMenu->addAction ( tr ( "Paste." ) );
  editMenu->addSeparator ();
  editMenu->addAction ( tr ( "Select All." ) );
  editMenu->addSeparator ();
  editMenu->addAction ( tr ( "Find And Search." ) );
  editMenu->addAction ( tr ( "Go To Line." ) );*/

  /*QMenu *refactoringMenu = this->addMenu ( tr ( "&Refactoring" ) );
  refactoringMenu->addAction ( tr ( "Rename." ) );
  refactoringMenu->addAction ( tr ( "Move." ) );*/

  /*QMenu *formattingMenu = this->addMenu ( tr ( "&Formatting" ) );
  formattingMenu->addAction ( tr ( "Organize Use." ) );
  formattingMenu->addAction ( tr ( "Organize Código." ) );
  formattingMenu->addAction ( tr ( "Organize Attributes." ) );
  formattingMenu->addAction ( tr ( "Organize Methods." ) );
  formattingMenu->addAction ( tr ( "Organize Functions." ) );
  formattingMenu->addAction ( tr ( "Corrent Identation." ) );*/

  /*QMenu *codeMenu = this->addMenu ( tr ( "&Code" ) );
  codeMenu->addAction ( tr ( "New Class." ) );
  codeMenu->addAction ( tr ( "New Interface." ) );
  codeMenu->addAction ( tr ( "New Trait." ) );
  codeMenu->addAction ( tr ( "New Attribute." ) );
  codeMenu->addAction ( tr ( "New Method." ) );
  codeMenu->addAction ( tr ( "Create Getters and Setters." ) );
  codeMenu->addAction ( tr ( "Generate Comments." ) );
  codeMenu->addAction ( tr ( "Generate Constructor From SuperClass." ) );
  codeMenu->addSeparator ();
  QMenu *patternMenu = codeMenu->addMenu ( tr ( "Design Pattern." ) );
  QMenu *creationalMenu = patternMenu->addMenu ( tr ( "Creational Patterns." ) );
  creationalMenu->addAction ( tr ( "Abstract Factory." ) );
  creationalMenu->addAction ( tr ( "Builder." ) );
  creationalMenu->addAction ( tr ( "Factory Method." ) );
  creationalMenu->addAction ( tr ( "Lazy Initialization." ) );
  creationalMenu->addAction ( tr ( "Multiton." ) );
  creationalMenu->addAction ( tr ( "Object Pool." ) );
  creationalMenu->addAction ( tr ( "Prototype." ) );
  creationalMenu->addAction ( tr ( "Resource Acquisition is Initialization." ) );
  creationalMenu->addAction ( tr ( "Singleton." ) );
  QMenu *structuralMenu = patternMenu->addMenu ( tr ( "Structural Patterns." ) );
  structuralMenu->addAction ( tr ( "Adapter/Wrapper/Translator." ) );
  structuralMenu->addAction ( tr ( "Bridge." ) );
  structuralMenu->addAction ( tr ( "Composite." ) );
  structuralMenu->addAction ( tr ( "Decorator." ) );
  structuralMenu->addAction ( tr ( "Extension Object." ) );
  structuralMenu->addAction ( tr ( "Facade." ) );
  structuralMenu->addAction ( tr ( "Flyweight." ) );
  structuralMenu->addAction ( tr ( "Front Controller." ) );
  structuralMenu->addAction ( tr ( "Marker." ) );
  structuralMenu->addAction ( tr ( "Module." ) );
  structuralMenu->addAction ( tr ( "Proxy." ) );
  structuralMenu->addAction ( tr ( "Twin." ) );
  QMenu *behavioralMenu = patternMenu->addMenu ( tr ( "Behavioral Patterns." ) );
  behavioralMenu->addAction ( tr ( "Blackboard." ) );
  behavioralMenu->addAction ( tr ( "Chain of Responsibility." ) );
  behavioralMenu->addAction ( tr ( "Command." ) );
  behavioralMenu->addAction ( tr ( "Interpreter." ) );
  behavioralMenu->addAction ( tr ( "Iterator." ) );
  behavioralMenu->addAction ( tr ( "Mediator." ) );
  behavioralMenu->addAction ( tr ( "Memento." ) );
  behavioralMenu->addAction ( tr ( "Null Object." ) );
  behavioralMenu->addAction ( tr ( "Observer/Publish/Suscribe." ) );
  behavioralMenu->addAction ( tr ( "Servant." ) );
  behavioralMenu->addAction ( tr ( "Specification." ) );
  behavioralMenu->addAction ( tr ( "State." ) );
  behavioralMenu->addAction ( tr ( "Strategy." ) );
  behavioralMenu->addAction ( tr ( "Template Method." ) );
  behavioralMenu->addAction ( tr ( "Visitor." ) );
  QMenu *concurrencyMenu = patternMenu->addMenu ( tr ( "Concurrency Patterns." ) );
  concurrencyMenu->addAction ( tr ( "Active Object." ) );
  concurrencyMenu->addAction ( tr ( "Balking." ) );
  concurrencyMenu->addAction ( tr ( "Binding Properties." ) );
  concurrencyMenu->addAction ( tr ( "Block Chain." ) );
  concurrencyMenu->addAction ( tr ( "Double-Check Locking." ) );
  concurrencyMenu->addAction ( tr ( "Event-Base Asynchronous." ) );
  concurrencyMenu->addAction ( tr ( "Guarded Suspension." ) );
  concurrencyMenu->addAction ( tr ( "Join." ) );
  concurrencyMenu->addAction ( tr ( "Lock." ) );
  concurrencyMenu->addAction ( tr ( "Messaging Desing Pattern (MDP)." ) );
  concurrencyMenu->addAction ( tr ( "Monitor Object." ) );
  concurrencyMenu->addAction ( tr ( "Reactor." ) );
  concurrencyMenu->addAction ( tr ( "Read-Write Lock." ) );
  concurrencyMenu->addAction ( tr ( "Scheduler." ) );
  concurrencyMenu->addAction ( tr ( "Thread Pool." ) );
  concurrencyMenu->addAction ( tr ( "Thread-Specific Storage." ) );*/

  /*QMenu *codeComunity = this->addMenu ( tr ( "&Comunity" ) );
  codeComunity->addAction ( tr ( "Share." ) );*/

  /*QMenu *scrumMenu = this->addMenu ( tr ( "&Scrum" ) );
  scrumMenu->addAction ( tr ( "Iteración." ) );*/

  QMenu *windowMenu = this->addMenu ( tr ( "&Window" ) );
  Actions::ToolBarShowHideAct *toolBarShowHideAct = new Actions::ToolBarShowHideAct ( "Show/Hide Tool Bar", parent );
  windowMenu->addAction ( toolBarShowHideAct );
  Actions::StatusBarShowHideAct *statusBarShowHideAct = new Actions::StatusBarShowHideAct ( "Show/Hide Status Bar", parent );
  windowMenu->addAction ( statusBarShowHideAct );
  windowMenu->addSeparator ();
  Actions::FullScreenAct *fullScreenAct = new Actions::FullScreenAct ( "Activate/Deactivate Fullsreen", parent );
  windowMenu->addAction ( fullScreenAct );
  windowMenu->addAction ( tr ( "Maximizada." ) );
  /*
  QMenu *menuViews = windowMenu->addMenu ( tr ( "Views." ) );
  menuViews->addAction ( tr ( "Explorador de Proyectos." ) );
  menuViews->addAction ( tr ( "Explorador de Clases." ) );
  menuViews->addAction ( tr ( "Explorador de Funciones." ) );
  menuViews->addAction ( tr ( "Explorador de Errores y Advertencias." ) );
  menuViews->addAction ( tr ( "Explorador de Salidas." ) );
  menuViews->addAction ( tr ( "Explorador de Consola." ) );
  QMenu *menuPerspectivas = windowMenu->addMenu ( tr ( "Perspectivas." ) );
  menuPerspectivas->addAction ( tr ( "Ecomod." ) );
  menuPerspectivas->addAction ( tr ( "Php." ) );
  menuPerspectivas->addAction ( tr ( "Qt/C++." ) );
  menuPerspectivas->addAction ( tr ( "C/C++." ) );
  menuPerspectivas->addAction ( tr ( "Javascript." ) );
  menuPerspectivas->addAction ( tr ( "Html." ) );
  menuPerspectivas->addAction ( tr ( "Java." ) );
  QMenu *menuViewTabs = windowMenu->addMenu ( tr ( "View Tabs." ) );
  menuViewTabs->addAction ( tr ( "Close Active." ) );
  menuViewTabs->addAction ( tr ( "Close All." ) );
  menuViewTabs->addAction ( tr ( "Close All Except Active." ) );
  menuViewTabs->addSeparator ();
  windowMenu->addSeparator ();
  QMenu *menuOpens = menuViewTabs->addMenu ( tr ( "Opens." ) );
  menuOpens->addAction ( tr ( "Pestaña 1." ) );
  menuOpens->addAction ( tr ( "Pestaña 2." ) );
  menuOpens->addAction ( tr ( "Pestaña 3." ) );
  QMenu *menuClosed = menuViewTabs->addMenu ( tr ( "Closed." ) );
  menuClosed->addAction ( tr ( "Pestaña 4." ) );
  menuClosed->addAction ( tr ( "Pestaña 5." ) );
  menuClosed->addAction ( tr ( "Pestaña 6." ) );
  windowMenu->addSeparator ();
  windowMenu->addAction ( tr ( "Pantalla Completa." ) );
  windowMenu->addAction ( tr ( "Maximizada." ) );*/

  QMenu *preferencesMenu = this->addMenu ( tr ( "&Preferences" ) );
  preferencesMenu->addAction ( tr ( "Mostrar Menú" ) );
  preferencesMenu->addAction ( tr ( "Mostrar Barra de Herramientas" ) );
  preferencesMenu->addAction ( tr ( "Mostrar Barra de Estado" ) );
  preferencesMenu->addSeparator ();
  preferencesMenu->addAction ( new Actions::SettingsAct ( "Configuración del Sistema", parent ) );

  QMenu *helpMenu = this->addMenu ( tr ( "&Help" ) );
  helpMenu->addAction ( new Actions::HelpTopicsAct ( "Temas de Ayuda", parent ) );
  helpMenu->addAction ( new Actions::OnlineHelpAct ( "Ayuda en Línea", parent ) );
  helpMenu->addAction ( tr ( "Tutorial" ) );
  helpMenu->addAction ( tr ( "Examples" ) );
  helpMenu->addAction ( tr ( "Comunity" ) );
  helpMenu->addSeparator ();
  helpMenu->addAction ( tr ( "Code Shop" ) );
  helpMenu->addSeparator ();
  helpMenu->addAction ( tr ( "About Ecomod Editor" ) );
}

MenuBar::~MenuBar () {}
