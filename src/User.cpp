#include "User.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

User::User(std::string employeeNumber, std::string NIF, std::string name){
  this->name = name;
  User::setEmployeeNumber(employeeNumber);
  User::setNIF(NIF);
  this->lastLogTime = "";
  this->addTimestamp();
  this->adminPermission = false;
}

bool User::isSameNIF(std::string NIF){
  return this->NIF.compare(NIF) == 0;
};

bool User::isSameEmployeeNumber(std::string employeeNumber){
  return this->employeeNumber.compare(employeeNumber) == 0;
};

std::string User::getName(){
  return this->name;
};

void User::addTimestamp(){
  auto date = std::chrono::system_clock::now();
  time_t t = std::chrono::system_clock::to_time_t(date);

  this->lastLogTime = std::ctime(&t);
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

bool User::hasAdminPermission(){
  return this->adminPermission;
}

User::~User(){};