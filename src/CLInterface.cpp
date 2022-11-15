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
};

void CLInterface::login(int tries){
  if (tries == 0){
    loginInterface = LoginInterface::Create();
    this->loginInterface = loginInterface;
  }
  if (tries == 5) std::exit(0);

  this->loginInterface->showWelcomeMessage();
  this->loginInterface->askEmployeeNumber();
  this->loginInterface->askNIF();
  usleep(2 * 1000000);
  if (this->loginInterface->checkUser()){
    printCenter("Login successful" );
    std::cout << "\n";
    usleep(1 * 1000000);
    system("clear");
    tries = 0;
    delete this->loginInterface;
  } else {
    printCenter("Failed login\n", "red");
    usleep(1 * 1000000);
    tries++;
    login(tries);
  }
}