#include "Humidity.h"
#include "Sensor.h"
#include <iostream>

int Humidity::idNumber = 0;

Humidity::Humidity (bool active, int valPerMin):Sensor("hum" + std::to_string(Humidity::idNumber ++),"humidity sensor","g/m³",active,valPerMin){}

std::vector<int> Humidity::requestData(){
  int valueRange = 20;
  this->data.clear();
  int newVal = rand() % valueRange;
  if (newVal < 0) newVal *= -1 ;
  int med = newVal;
  this->data.push_back(med);
  for (int i = 0; i < 60 * this->valPerMin - 1; i++){
    newVal = rand() % valueRange;
    med = ( med + newVal ) / 2;
    this->data.push_back(med);
  }
  
  return this->data;
}

Humidity::~Humidity(){}
