/**
 * @file Moisture.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Moisture.h"

/**
 * @brief Id of all the moisture sensor so there is not a duplicate id
 * 
 */
int Moisture::idNumber = 0;

/**
 * @brief Create a new Moisture object
 * 
 * @param active By default off
 * @param valPerMin By default 1 val/min
 */
Moisture::Moisture (bool active, int valPerMin):Sensor("moist" + std::to_string(Moisture::idNumber ++),"moisture sensor","% MC",active,valPerMin){}

/**
 * @brief Request data from the moisture sensor
 * 
 * @return std::vector<int>  Data values
 * @note This function is a placeholder, returns random values 
 */
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
