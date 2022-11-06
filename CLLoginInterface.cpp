/* ---------------------------
File: sensor.cpp
Author: Javier Izquierdo
Date: 03/11/2022
Goal: contains the sensor class
---------------------------- */

#include "LoginInterface.h"
#include "CLLoginInterface.h"
#include "CLIUtils.h"
#include <iostream>
#include <stdio.h>

CLLoginInterface::CLLoginInterface(){
}

void CLLoginInterface::showWelcomeMessage(){
  system("clear");
  printCenterFromFile("CLLoginInterface.config", "green");
  std::cout << "\n\n\n";
  printCenter("Enter your employee number: ",5);
  std::cout << "\n\n\n";
  printCenter("Enter your NIF: ",8);
  std::cout << "\u001b[s";
}

void CLLoginInterface::askEmployeeNumber(){
  std::cout << "\u001b[7C";
  std::cout << "\u001b[3A";
  std::cin >> this->inputEmployeeNumber;
}

void CLLoginInterface::askNIF(){
  std::cout << "\u001b[u";
  std::cin >> this->inputNIF;
  std::cout << "\n\n\n";

}