/* ---------------------------
File: sensor.cpp
Author: Javier Izquierdo
Date: 03/11/2022
Goal: contains the sensor class
---------------------------- */

#include "CLInterface.h"
#include "User.h"
#include "LoginInterface.h"
#include "Dashboard.h"
#include "CLIUtils.h"
#include <unistd.h>
#include <iostream>

CLInterface::CLInterface(){
  setTerminalSize();
  loginInterface = LoginInterface::Create();
  this->loginInterface = loginInterface;
  dashboard = Dashboard::Create();
  this->dashboard = dashboard;
};

void CLInterface::login(){
  this->loginInterface->showWelcomeMessage();
  this->loginInterface->askEmployeeNumber();
  this->loginInterface->askNIF();
  usleep(2 * 1000000);
  if (this->loginInterface->checkUser()){
    printCenter("Login successful" );
    std::cout << "\n";
  } else {
    printCenter("Failed login\n", 0 ,"red");
    usleep(1 * 1000000);
    login();
  }
};

void CLInterface::loadMenu(){
  this->dashboard->showMainMenu();
};