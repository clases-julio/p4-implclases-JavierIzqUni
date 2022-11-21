#include "Dashboard.h"
#include "CLDashboard.h"
#include <string>
#include <vector>

Dashboard::Dashboard(){
  this->allowedToExit = true;
  this->currentSensor = nullptr;
}

/**
 * @brief Create a new instance of the desired Dashboard interface
 * 
 * @param type Type of Dashboard interface
 * @return Dashboard*  
 */
Dashboard *Dashboard::Create(const std::string type){
  if (type == "CLI"){
    return new CLDashboard();
  }
  else {
    throw std::runtime_error(type + " is not a defined Dashboard type");
    std::exit(1);
  }
};

/**
 * @brief Changes the current interface to the input one
 * 
 * @param newInterface Desired interface to change ( .. = main Menu)
 */
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

/**
 * @brief Adds a sensor to the dashboard
 * 
 * @param sensor Sensor to add
 */
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

/**
 * @brief Adds all the current sensors to the dashboard
 * @note Only called at the start of the program
 */
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

/**
 * @brief Adds the user to the dashboard
 * 
 * @param user Current user
 */
void Dashboard::setUser(User user){
  this->user = user;
}

/**
 * @brief Creates the new sensor and calls addToMainMenu
 * 
 * @param id New sensor type
 * @see addToMainMenu
 */
void Dashboard::addNewSensor(std::string type){
  Sensor *sensor = Sensor::Create(type);;
  addToMainMenu(sensor);
}

/**
 * @brief Deletes the desired sensor from the dashboard
 * 
 * @param id ID of the sensor to delete
 * @see addToMainMenu
 */
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

/**
 * @brief Shifts the main menu n pages
 * 
 * @param n Number of pages to shift ( positive to the right )
 */
void Dashboard::moveWindowMainMenu(int n){
  if (this->mainMenuIndex + n < 0) return;
  if (this->mainMenuIndex + n >= this->mainMenu.size()) return;
  this->mainMenuIndex += n;
}

/**
 * @brief Changes the current sensor values
 * 
 * @param toChange Desired value to change
 * @param newValue New value to add
 */
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

/**
 * @brief Deletes all the sensors from the dashboard
 * @note Only called when exiting the dashboard
 * 
 */
void Dashboard::cleanSensor(){
  for (Sensor * sensor : this->sensor){
    delete sensor;
  }
}

/**
 * @brief Exits the dashboard and finishes the program
 * @see cleanSensor
 */
void Dashboard::exit(){
  cleanSensor();
  this->allowedToExit = true;
}

/**
 * @brief Exits the dashboard and goes back to the login screen
 * @see cleanSensor
 */
void Dashboard::logout(){
  cleanSensor();
  this->allowedToExit = false;
}

/**
 * @brief Called from main, checks if the program is allowed to exit
 * 
 * @return true End the program
 * @return false Cannot exit, goes to login screen 
 */
bool Dashboard::canExit(){
  return this->allowedToExit;
}

Dashboard::~Dashboard(){}