#include "Menu.h"

using namespace Com::Ecosoftware::Window::Components::Menubar;

Menu::Menu ( QWidget *parent ) : QMenu ( parent ) {

  this->setStyleSheet ( "QMenu { background-color: #404244; color: #FF8000; font-weight: bold; }"
                        "QMenu::item:selected { background-color: #4DAC06; }");
}

void Menu::createStyle () {

  this->setStyleSheet ( "QMenu { background-color: #404244; color: #FF8000; font-weight: bold; }"
                        "QMenu::item:selected { background-color: #4DAC06; }");
}
