#include "MenuBar.h"
#include "CLMenuBar.h"

#include <iostream>

MenuBar::MenuBar(){}

MenuBar * MenuBar::Create(const std::string type){
  if (type == "CLI"){
    return new CLMenuBar;
  }
  else {
    throw std::runtime_error(type + " is not a defined MenuBar type");
    std::exit(1);
  }
}

void MenuBar::setUserName(std::string userName){
  this->userName = userName;
}

void MenuBar::setCurrentMenu(std::string currentMenu){
  this->currentMenu = currentMenu;
}

MenuBar::~MenuBar(){}