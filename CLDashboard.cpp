#include "CLDashboard.h"
#include "CLIUtils.h"
#include "Dashboard.h"
#include <stdio.h>
#include <iostream>

CLDashboard::CLDashboard(){
  Sensor sensor1("1","test",false);
  this->sensor.push_back(sensor1);
  this->sensor.push_back(sensor1);
  this->sensor.push_back(sensor1);
  this->sensor.push_back(sensor1);
  this->menuBar = MenuBar::Create();
}

void CLDashboard::showMainMenu(){
  system("clear");
  this->menuBar->show();
  startCustomTerminal(10);
  readCommand();
}

void CLDashboard::readCommand(){
  std::vector<std::string> command;
  int lineNumber = 0;
  while (true){
    lineNumber++;
    if (lineNumber > 10){ lineNumber%=10; clearCustomTerminal(10);} 
    command = newCommand(this->user,this->currentInterface);
    if (command.size() == 0) continue;
    if (command[0].compare("exit") == 0){system("clear"); exit();}
    if (command[0].compare("cs") == 0){
      if (command.size() != 2) continue;
      changeInterface(command[1]);
    }
    if (command[0].compare("ls") == 0){ lineNumber++; listSensor();}
    if (command[0].compare("logout") == 0) break;
    if (command[0].compare("clear") == 0) clearCustomTerminal(10);
  }
  
}

void CLDashboard::listSensor(){
  for ( Sensor s: this->sensor){
    std::cout << s.getId() << "\t";
  }
  std::cout << "\n";
}

void CLDashboard::changeInterface(std::string newInterface){
  if (newInterface.compare("..") == 0) newInterface = "";
  this->currentInterface = newInterface;
}