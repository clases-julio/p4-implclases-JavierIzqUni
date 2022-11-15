/* ---------------------------
File: sensor.cpp
Author: Javier Izquierdo
Date: 03/11/2022
Goal: contains the sensor class
---------------------------- */

#include "Sensor.h"
#include <iostream>
#include <vector>

Sensor::Sensor(std::string id, std::string type, std::string magnitude, bool active, int valPerMin){
  this->id = id;
  this->type = type;
  this->active = active;
  this->magnitude = magnitude;
  this->valPerMin = valPerMin;
  this->area = "none";
  this->data = {40,41,42,43,44,45,44,43,42,41,40,39,37,34,30,25,18,-19,0,13,20,21,18,15,10,5,0,3,6,9,10,11,12};
  system("echo addSensor >> log.txt");
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

Sensor::~Sensor(){
  system("echo removeSensor >> log.txt");
};