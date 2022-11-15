#include "Menu.h"
#include <string>
#include "CLMenu.h"

Menu::Menu(){}

Menu * Menu::Create(const std::string type){
  if (type == "CLI"){
    return new CLMenu;
  }
  else {
    throw std::runtime_error(type + " is not a defined Menu type");
    std::exit(1);
  }
}

Menu::~Menu(){}