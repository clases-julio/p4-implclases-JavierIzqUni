/* ---------------------------
File: sensor.cpp
Author: Javier Izquierdo
Date: 03/11/2022
Goal: contains the sensor class
---------------------------- */

#include "Sensor.h"
#include <iostream>
#include <vector>

Sensor::Sensor(std::string id,std::string type ,bool active){
  this->id = id;
  this->type = type;
  this->active = active;
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
  return this->data;
}

void Sensor::setMagnitude(int magnitude){
  this->magnitude = magnitude;
}

int Sensor::getMagnitude(){
  return this->magnitude;
}

Sensor::~Sensor(){};