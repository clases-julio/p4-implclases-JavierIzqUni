/* ---------------------------
File: sensor.cpp
Author: Javier Izquierdo
Date: 03/11/2022
Goal: contains the sensor class
---------------------------- */

#include "Dashboard.h"
#include "CLDashboard.h"
#include <iostream>
#include <vector>

Dashboard::Dashboard(){
  this->allowedToExit = true;
  this->currentSensor = nullptr;
}

Dashboard *Dashboard::Create(const std::string type){
  if (type == "CLI"){
    return new CLDashboard();
  }
  else {
    throw std::runtime_error(type + " is not a defined Dashboard type");
    std::exit(1);
  }
};

void Dashboard::changeInterface(std::string newInterface){
  
  if (newInterface.compare("..") == 0){
    if (this->mainMenuIndex + 1 > this->mainMenu.size()) moveWindowMainMenu(-1) ;
    this->currentSensor = nullptr;
    this->menu->show(this->mainMenu[this->mainMenuIndex]);
    std::string menuName = std::to_string(this->mainMenuIndex + 1)  + "/" + std::to_string(this->mainMenu.size());
    this->menuBar->setCurrentMenu(menuName);
  }
  else if (this->currentInterface.compare(newInterface) == 0){
        this->menu->show(this->currentSensor);
        this->menuBar->setCurrentMenu(this->currentInterface);
        return;
  }
  else {
    for (Sensor *sensor: this->sensor){
      if (newInterface.compare(sensor->getId())== 0){
        this->currentSensor = sensor;
        this->menu->show(this->currentSensor);
        this->menuBar->setCurrentMenu(newInterface);
      }
    }
  }
  this->menuBar->show();
  this->lastInterface = this->currentInterface;
  this->currentInterface = newInterface;
}

void Dashboard::addToMainMenu(Sensor *sensor){
  std::vector<Sensor *> tmp;
  if (this->mainMenu.back().size() < 6) {
    tmp = this->mainMenu.back();
    this->mainMenu.pop_back();
  }
  tmp.push_back(sensor);

  //Readding the new sensor
  this->sensor.push_back(sensor);
  this->mainMenu.push_back(tmp);
}

void Dashboard::addToMainMenu(){
  std::vector<Sensor *> tmp;
  int nSensorWindow = 6;
  int sensorsToAdd = this->sensor.size();
  for (int windows = 0; windows < ((sensorsToAdd - 1)/ 6) + 1; windows++){
    tmp.clear();
    if ( sensorsToAdd / (6*(windows+1)) == 0) nSensorWindow = sensorsToAdd - (6 * windows) ;
    for (int nSensor = 0; nSensor < nSensorWindow; nSensor++) {
      tmp.push_back(this->sensor[nSensor + (windows * 6)]);
    }
    this->mainMenu.push_back(tmp);
  }
}

void Dashboard::setUser(User user){
  this->user = user;
}

void Dashboard::addNewSensor(std::string id){
  Sensor *sensor = new Sensor(id,"sensor","c",true,1);
  addToMainMenu(sensor);
}

void Dashboard::deleteSensor(std::string id){
  // Check if we are going to delete the last sensor
  if (this->sensor.size() == 1) return;
  // Check if we are going to delete the currentSensor
  if (this->currentSensor != nullptr){
    if (id.compare(this->currentSensor->getId())== 0){
      return;
    }
  }
  // Clear main menu
  this->mainMenu.clear();
  // Remove from sensor vector
  for (int index = 0; index < this->sensor.size(); index++){
    if (id.compare(this->sensor[index]->getId())== 0){
      Sensor *sensor = this->sensor[index];
      this->sensor.erase(this->sensor.begin() + index);
      delete sensor;
    }
  }
  // Reset main menu
  addToMainMenu();
}

void Dashboard::moveWindowMainMenu(int n){
  if (this->mainMenuIndex + n < 0) return;
  if (this->mainMenuIndex + n >= this->mainMenu.size()) return;
  this->mainMenuIndex += n;
}

void Dashboard::changeCurrentSensorInfo(std::string toChange, std::string newValue){

  if (this->currentInterface.compare("..") == 0) return;

  if (toChange.compare("area") == 0) this->currentSensor->setArea(newValue);
  else if (toChange.compare("magnitude") == 0){
    if (newValue.size() != 1) return; // Placeholder
    this->currentSensor->setMagnitude("C"); // Placeholder
  }
  else if (toChange.compare("val") == 0){
    try {
      std::stoi(newValue);
      this->currentSensor->setValPerMin(std::stoi(newValue)); // Placeholder
    }
    catch(const std::exception & e)
    {
      return;
    }
    
  }
  else if (toChange.compare("state") == 0){

    if (newValue.compare("on") == 0) this->currentSensor->setActive(true);
    else if (newValue.compare("off") == 0) this->currentSensor->setActive(false);
    else return;
  }
  this->changeInterface(this->currentInterface);
}

void Dashboard::cleanSensor(){
  for (Sensor * sensor : this->sensor){
    delete sensor;
  }
}

void Dashboard::exit(){
  cleanSensor();
  this->allowedToExit = true;
}

void Dashboard::logout(){
  cleanSensor();
  this->allowedToExit = false;
}

bool Dashboard::canExit(){
  return this->allowedToExit;
}

Dashboard::~Dashboard(){}