/* ---------------------------
File: sensor.cpp
Author: Javier Izquierdo
Date: 03/11/2022
Goal: contains the sensor class
---------------------------- */

#include "LoginInterface.h"
#include "CLLoginInterface.h"
#include "CLIFunctions.h"
#include <iostream>
#include <stdio.h>

CLLoginInterface::CLLoginInterface(){
}

void CLLoginInterface::showWelcomeMessage(int terminalWidth){
  system("clear");
  CLLoginInterface::setTerminalWidth(terminalWidth);
  printCenterFromFile(terminalWidth, "CLLoginInterface.config");
}

void CLLoginInterface::askEmployeeNumber(){
  printCenter(terminalWidth,"Enter your employee number: ",5);
  std::cin >> this->inputEmployeeNumber;
}

void CLLoginInterface::askNIF(){
  std::cout << "\n\n\n";
  printCenter(terminalWidth,"Enter your NIF: ",8);
  std::cin >> this->inputNIF;

}

void CLLoginInterface::setTerminalWidth(int terminalWidth){
  this->terminalWidth = terminalWidth;
}