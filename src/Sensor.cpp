/**
 * @file Sensor.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Sensor.h"
#include "Thermometer.h"
#include "Humidity.h"
#include "Moisture.h"
#include "AirQuality.h"
#include "CameraBW.h"
#include "CameraRGB.h"

/**
 * @brief Creates an instance of the sensor type
 * 
 * @param type 
 * @return Sensor* 
 */
Sensor *Sensor::Create(std::string type){
  if (type == "thermometer"){
    return new Thermometer;
  }
  else if (type == "humidity"){
    return new Humidity;
  }
  else if (type == "moisture"){
    return new Moisture;
  }
  else if (type == "airquality"){
    return new AirQuality;
  }
  else if (type == "bwcamera"){
    return new CameraBW;
  }
  else if (type == "rgbcamera"){
    return new CameraRGB;
  }
  else {
    throw std::runtime_error(type + " is not a defined sensor type");
    std::exit(1);
  }
};

/**
 * @brief Construct a new Sensor:: Sensor object
 * 
 * @param id Identification of type and number
 * @param type Type of sensor
 * @param magnitude Data values magnitude
 * @param active Sensor is On/Off
 * @param valPerMin Number of values per min
 */
Sensor::Sensor(std::string id, std::string type, std::string magnitude, bool active, int valPerMin){
  this->id = id;
  this->type = type;
  this->active = active;
  this->magnitude = magnitude;
  this->valPerMin = valPerMin;
  this->area = "none";
}

/**
 * @brief Returns the sensor id
 * 
 * @return std::string ID
 */
std::string Sensor::getId(){
  return this->id;
};

/**
 * @brief Turns the sensor On/Off
 * 
 * @param active 
 */
void Sensor::setActive(bool active){
  this->active = active;
};

/**
 * @brief Returns if the sensor is On/Off
 * 
 * @return true = ON
 * @return false = OFF
 */
bool Sensor::isActive(){
  return this->active;
}

/**
 * @brief Returns the sensor type
 * 
 * @return std::string Sensor type 
 */
std::string Sensor::getType(){
  return this->type;
}

/**
 * @brief Set the area of the sensor
 * 
 * @param area 
 */
void Sensor::setArea(std::string area){
  this->area = area;
}

/**
 * @brief Returns the area of the sensor
 * 
 * @return std::string Area
 */
std::string Sensor::getArea(){
  return this->area;
}

/**
 * @brief Set the sensor data values magnitude
 * 
 * @param magnitude 
 */
void Sensor::setMagnitude(std::string magnitude){
  this->magnitude = magnitude;
}

/**
 * @brief Returns the sensor magnitude
 * 
 * @return std::string Magnitude
 */
std::string Sensor::getMagnitude(){
  return this->magnitude;
}

/**
 * @brief Set the number of values per min
 * 
 * @param valPerMin 
 */
void Sensor::setValPerMin(int valPerMin){
  if (valPerMin <= 0) return;
  this->valPerMin = valPerMin;
}

/**
 * @brief Return the number of values per min
 * 
 * @return int Values per minute
 */
int Sensor::getValPerMin(){
  return this->valPerMin;;
}

Sensor::~Sensor(){};