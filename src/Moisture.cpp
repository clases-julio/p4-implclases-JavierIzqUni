#include "Moisture.h"
#include "Sensor.h"
#include <iostream>

int Moisture::idNumber = 0;

Moisture::Moisture (bool active, int valPerMin):Sensor("moist" + std::to_string(Moisture::idNumber ++),"moisture sensor","% MC",active,valPerMin){}

std::vector<int> Moisture::requestData(){
  int valueRange = 100;
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

Moisture::~Moisture(){}
