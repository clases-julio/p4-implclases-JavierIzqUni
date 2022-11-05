/* ---------------------------
File: sensor.cpp
Author: Javier Izquierdo
Date: 03/11/2022
Goal: contains the sensor class
---------------------------- */

#include "User.h"
#include <iostream>
#include <vector>

User::User(std::string employeeNumber, std::string NIF){
  User::setEmployeeNumber(employeeNumber);
  User::setNIF(NIF);
  this->lastLogTime = NIF;
}

bool User::isSameNIF(std::string NIF){
  return this->NIF.compare(NIF) == 0;
};

bool User::isSameEmployeeNumber(std::string employeeNumber){
  return this->employeeNumber.compare(employeeNumber) == 0;
};

void User::addTimestamp(std::string logTime){
  this->lastLogTime = logTime;
};
std::string User::getTimestamp(){
  return this->lastLogTime;
};

void User::setNIF(std::string NIF){
  if (NIF.size() == 8){
    this->NIF =NIF;
  } else {
    this->NIF = "00000000";
  }
};

void User::setEmployeeNumber(std::string employeeNumber){
  if (employeeNumber.size() == 5){
    this->employeeNumber = employeeNumber;
  } else {
    this->employeeNumber = "00000";
  }
};

User::~User(){};