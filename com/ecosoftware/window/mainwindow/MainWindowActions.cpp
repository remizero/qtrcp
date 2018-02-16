#include "MainWindowActions.h"

using namespace Com::Ecosoftware::Window::MainWindow;

MainWindowActions::MainWindowActions () {}

MainWindowActions::~MainWindowActions () {}

QMainWindow *MainWindowActions::getParent () const {

  return this->parent;
}

void MainWindowActions::setParent ( QMainWindow *value ) {

  this->parent = value;
}

void MainWindowActions::loadBasicActions () {}

void MainWindowActions::loadPluginActions () {}

void MainWindowActions::setPluginAction () {}
