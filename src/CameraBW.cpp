#include "CameraBW.h"
#include "Sensor.h"
#include <iostream>


int CameraBW::idNumber = 0;

CameraBW::CameraBW (bool active, int valPerMin):Sensor("bwcam" + std::to_string(CameraBW::idNumber ++),"camera","-",active,valPerMin){}

std::vector<int> CameraBW::requestData(){
  int valueRange = 1;
  this->data.clear();
  int newVal = rand() % valueRange;;
  int med = newVal;
  this->data.push_back(med);
  for (int i = 0; i < 60 * this->valPerMin - 1; i++){
    newVal = rand() % valueRange;
    med = ( med + newVal ) / 2;
    this->data.push_back(med);
  }
  
  return this->data;
}

CameraBW::~CameraBW(){}
