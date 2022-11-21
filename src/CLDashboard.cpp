#include "CLDashboard.h"
#include "CLIUtils.h"
#include "Dashboard.h"
#include <stdio.h>
#include <iostream>

CLDashboard::CLDashboard(){
  Sensor *sensor1 = Sensor::Create("thermometer");
  Sensor *sensor2 = Sensor::Create("humidity");
  Sensor *sensor3 = Sensor::Create("humidity");
  Sensor *sensor4 = Sensor::Create("airquality");
  Sensor *sensor5 = Sensor::Create("moisture");
  Sensor *sensor6 = Sensor::Create("rgbcamera");
  Sensor *sensor7 = Sensor::Create("bwcamera");
  this->sensor.push_back(sensor1);
  this->sensor.push_back(sensor2);
  this->sensor.push_back(sensor3);
  this->sensor.push_back(sensor4);
  this->sensor.push_back(sensor5);
  this->sensor.push_back(sensor6);
  this->sensor.push_back(sensor7);
  addToMainMenu(); 
  this->mainMenuIndex = 0;
  this->menuBar = MenuBar::Create();
  this->menu = Menu::Create();
}

/**
 * @brief Shows the default menu and starts the custom terminal
 * 
 */
void CLDashboard::showMainMenu(){
  this->menuBar->setUserName(this->user.getName());
  this->currentInterface = "..";
  changeInterface(this->currentInterface);
  startCustomTerminal(10);
  readCommand();
}

/**
 * @brief Reads and executes a command from the terminal 
 * 
 */
void CLDashboard::readCommand(){
  std::vector<std::string> command;
  int lineNumber = 0;
  while (true){
    lineNumber++;
    if (lineNumber >= 9){ lineNumber=0; clearCustomTerminal(10);}
    command = newCommand(this->user,this->currentInterface);
    /* Check if the command is empty */
    if (command.size() == 0);

    /* Command with only one word */
    else if (command.size() == 1){
      if (command[0].compare("ls") == 0){ lineNumber++; listSensor();}
      else if (command[0].compare("left") == 0) changeMainMenu(-1);
      else if (command[0].compare("right") == 0) changeMainMenu(1);
      else if (command[0].compare("log") == 0) std::cout << this->user.getTimestamp();
      else if (command[0].compare("clear") == 0) clearCustomTerminal(10);
      else if (command[0].compare("logout") == 0){ logout(); break;}
      else if (command[0].compare("exit") == 0){system("clear"); exit(); break;}
      else if (command[0].compare("update") == 0) {
        changeInterface(this->currentInterface);
        std::cout << "\u001b[u"; // Reload cursor pos
      }
      else if (command[0].compare("back") == 0) {
        changeInterface(this->lastInterface);
        std::cout << "\u001b[u"; // Reload cursor pos
      }
      else errorCommand(command[0]);
    }

    /* Command with two words */
    /* Check if the command has two words */
    else if (command.size() == 2){
      if (command[0].compare("man") == 0) {lineNumber++; helpCommand(command[1]);}
      else if (command[0].compare("set") == 0) changeCurrentSensorInfo("state", command[1]);
      else if (command[0].compare("cs") == 0) {
        changeInterface(command[1]);
        std::cout << "\u001b[u"; // Reload cursor pos
      }
      else if (command[0].compare("add") == 0){
        if (! this->user.hasAdminPermission()){permissionError();continue;}
        addNewSensor(command[1]);
        changeInterface(this->currentInterface);
        std::cout << "\u001b[u"; // Reload cursor pos
        lineNumber++;
      }
      else if (command[0].compare("rm") == 0){
        if (! this->user.hasAdminPermission()){permissionError();continue;}
        deleteSensor(command[1]);
        changeInterface(this->currentInterface);
        std::cout << "\u001b[u"; // Reload cursor pos
      }
      else errorCommand(command[0]);
    }

    /* Command with three words */
    /* Check if the command has three words */
    else if (command.size() == 3){
      if (command[0].compare("set") == 0) changeCurrentSensorInfo(command[1], command[2]);
      else errorCommand(command[0]);
    }
    
    else {lineNumber++;errorCommand(command[0]);}

    command.clear();
  }
}

/**
 * @brief Command that lists the sensors in the current menu page
 * 
 */
void CLDashboard::listSensor(){
if (this->currentInterface.compare("..") != 0) return;

  for ( Sensor *s: this->mainMenu[this->mainMenuIndex]){
    std::cout << s->getId() << "\t";
  }
  std::cout << "\n";
}

/**
 * @brief Change the page of the menu
 * 
 * @param n Number of pages to shift ( positive to the right )
 */
void CLDashboard::changeMainMenu(int n){
  if (this->currentInterface.compare("..") == 0){ 
    moveWindowMainMenu(n);
    changeInterface("..");
    std::cout << "\u001b[u"; // Reload cursor pos
  }
}

/**
 * @brief Displays the use of the command 
 * 
 * @param command Command to display info about
 */
void CLDashboard::helpCommand(std::string command){
  std::cout << "Help " << command << "\n";
}

/**
 * @brief Shows error message because the command not being found
 * 
 * @param command Command input
 */
void CLDashboard::errorCommand(std::string command){
  std::cout << command << ": command not found\n";
}

/**
 * @brief Shows error message because the permission being denied to execute it
 * 
 */
void CLDashboard::permissionError(){
  std::cout << this->user.getName() << " does not have the permissions required. Make sure to contact an administrator.\n";
}

CLDashboard::~CLDashboard(){}
