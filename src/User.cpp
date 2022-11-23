/**
 * @file User.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "User.h"

/**
 * @brief Create a new User
 * 
 * @param employeeNumber 
 * @param NIF 
 * @param name 
 */
User::User(std::string employeeNumber, std::string NIF, std::string name){
  this->name = name;
  User::setEmployeeNumber(employeeNumber);
  User::setNIF(NIF);
  this->lastLogTime = "";
  this->addTimestamp();
  this->adminPermission = false;
}

/**
 * @brief Check if the user has the input NIF
 * 
 * @param NIF 
 * @return true = is the same NIF
 * @return false = is not the same NIF
 */
bool User::isSameNIF(std::string NIF){
  return this->NIF.compare(NIF) == 0;
};

/**
 * @brief Set the user NIF
 * 
 * @param NIF 
 */
void User::setNIF(std::string NIF){
  if (NIF.size() == 8){
    this->NIF =NIF;
  } else {
    this->NIF = "00000000";
  }
};

/**
 * @brief Check if the user has the input employee number
 * 
 * @param employeeNumber 
 * @return true = is the same employee number
 * @return false = is not the same employee number
 */
bool User::isSameEmployeeNumber(std::string employeeNumber){
  return this->employeeNumber.compare(employeeNumber) == 0;
};

/**
 * @brief Set the user employee number
 * 
 * @param employeeNumber 
 */
void User::setEmployeeNumber(std::string employeeNumber){
  if (employeeNumber.size() == 5){
    this->employeeNumber = employeeNumber;
  } else {
    this->employeeNumber = "00000";
  }
};

/**
 * @brief Returns the user name
 * 
 * @return std::string User name
 */
std::string User::getName(){
  return this->name;
};

/**
 * @brief Set the timestamp 
 * 
 */
void User::addTimestamp(){
  auto date = std::chrono::system_clock::now();
  time_t t = std::chrono::system_clock::to_time_t(date);

  this->lastLogTime = std::ctime(&t);
};

/**
 * @brief Returns the timestamp
 * 
 * @return std::string Timestamp
 */
std::string User::getTimestamp(){
  return this->lastLogTime;
};

/**
 * @brief Returns the user permissions
 * 
 * @return true = has admin pemissions 
 * @return false = does not have admin permissions
 */
bool User::hasAdminPermission(){
  return this->adminPermission;
}

User::~User(){};