#include "MainWindowActions.h"

using namespace NAMESPACE_LIBRARY_MAINWINDOW;

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
