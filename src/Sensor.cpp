/* ---------------------------
File: sensor.cpp
Author: Javier Izquierdo
Date: 03/11/2022
Goal: contains the sensor class
---------------------------- */

#include "Sensor.h"
#include "Thermometer.h"
#include "Humidity.h"
#include "Moisture.h"
#include "AirQuality.h"
#include "CameraBW.h"
#include "CameraRGB.h"
#include <iostream>
#include <vector>

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

Sensor::Sensor(std::string id, std::string type, std::string magnitude, bool active, int valPerMin){
  this->id = id;
  this->type = type;
  this->active = active;
  this->magnitude = magnitude;
  this->valPerMin = valPerMin;
  this->area = "none";
}

std::string Sensor::getId(){
  return this->id;
};

void Sensor::setActive(bool active){
  this->active = active;
};

bool Sensor::isActive(){
  return this->active;
}

std::string Sensor::getType(){
  return this->type;
}

void Sensor::setArea(std::string area){
  this->area = area;
}

std::string Sensor::getArea(){
  return this->area;
}

std::vector<int> Sensor::requestData(){
  this->data.clear();
  int newVal = rand() % 50 - 10;
  int med = newVal;
  this->data.push_back(med);
  for (int i = 0; i < 60 * this->valPerMin - 1; i++){
    newVal = rand() % 50 - 10;
    med = ( med + newVal ) / 2;
    this->data.push_back(med);
  }
  
  return this->data;
}

void Sensor::setMagnitude(std::string magnitude){
  this->magnitude = magnitude;
}

std::string Sensor::getMagnitude(){
  return this->magnitude;
}

void Sensor::setValPerMin(int valPerMin){
  if (valPerMin <= 0) return;
  this->valPerMin = valPerMin;
}

int Sensor::getValPerMin(){
  return this->valPerMin;;
}

Sensor::~Sensor(){};