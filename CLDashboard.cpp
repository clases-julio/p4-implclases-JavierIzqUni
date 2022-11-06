#include "CLDashboard.h"
#include "CLIUtils.h"
#include "Dashboard.h"
#include <stdio.h>
#include <iostream>

CLDashboard::CLDashboard(){
  this->menuBar = MenuBar::Create();
}

void CLDashboard::showMainMenu(){
  system("clear");
  this->menuBar->show();
  startCustomTerminal();
}

void CLDashboard::changeInterface(){

}