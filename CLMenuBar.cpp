#include "CLMenuBar.h"
#include "CLIUtils.h"
#include "MenuBar.h"
#include <stdio.h>
#include <iostream>

CLMenuBar::CLMenuBar(){
}

void CLMenuBar::show(){
  std::cout << "\u001b[0;0H";
  printLeft("User: " + this->userName);
  printCenter(this->currentMenu);
  printRight("Exit (exit) ");
  std::cout << "\n";
}

