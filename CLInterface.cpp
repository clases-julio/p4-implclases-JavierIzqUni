/* ---------------------------
File: sensor.cpp
Author: Javier Izquierdo
Date: 03/11/2022
Goal: contains the sensor class
---------------------------- */

#include "CLInterface.h"
#include "User.h"
#include "LoginInterface.h"
#include "CLIFunctions.h"
#include <iostream>

CLInterface::CLInterface(){
  this->terminalWidth = getTerminalWidth();
  loginInterface = LoginInterface::Create();
  this->loginInterface = loginInterface;
};

void CLInterface::login(){
  this->loginInterface->showWelcomeMessage(terminalWidth);
  this->loginInterface->askEmployeeNumber();
  this->loginInterface->askNIF();
  if (this->loginInterface->checkUser()){
    std::cout << "Login successful" << "\n";
    std::cout << this->loginInterface->getUser().getTimestamp() << "\n";
  } else {
    login();
  }
};

void CLInterface::loadMenu(){
  std::cout << "load Menu cli" << "\n";
};