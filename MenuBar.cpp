#include "MenuBar.h"
#include "CLMenuBar.h"

MenuBar::MenuBar(){}

MenuBar * MenuBar::Create(std::string type){
  if (type == "CLI"){
    return new CLMenuBar;
  }
  else {
    return new CLMenuBar;
  }
}

MenuBar::~MenuBar(){}