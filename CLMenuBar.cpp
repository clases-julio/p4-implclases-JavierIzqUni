#include "CLMenuBar.h"
#include "CLIUtils.h"
#include "MenuBar.h"
#include <stdio.h>
#include <iostream>

CLMenuBar::CLMenuBar(){
  this->buttons.push_back("Hola");
  this->buttons.push_back("Adios");
  this->buttons.push_back("Hla");
  this->buttons.push_back("Adi");
  this->buttons.push_back("Exit");
  this->bar = join(buttons,'/');
}

void CLMenuBar::show(){
  printCenter(this->bar);
  std::cout << "\n";
}
