/* ---------------------------
File: sensor.cpp
Author: Javier Izquierdo
Date: 03/11/2022
Goal: contains the sensor class
---------------------------- */

#include "QtInterface.h"
#include <iostream>

QtInterface::QtInterface(){
  std::cout << "Init QtInterface" << "\n";
};

void QtInterface::login(){
  std::cout << "Login qt" << "\n";
};

void QtInterface::loadMenu(){
  std::cout << "load Menu qt" << "\n";
};