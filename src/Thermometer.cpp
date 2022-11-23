/**
 * @file Thermometer.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Thermometer.h"

/**
 * @brief Id of all the thermometer so there is not a duplicate id
 * 
 */
int Thermometer::idNumber = 0;

/**
 * @brief Create a new Thermometer object
 * 
 * @param active By default off
 * @param valPerMin By default 1 val/min
 */
Thermometer::Thermometer (bool active, int valPerMin):Sensor("therm" + std::to_string(Thermometer::idNumber ++),"thermometer","C",active,valPerMin){}

/**
 * @brief Request data from the thermometer
 * 
 * @return std::vector<int>  Data values
 * @note This function is a placeholder, returns random values 
 */
std::vector<int> Thermometer::requestData(){
  int valueRange = 40;
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

Thermometer::~Thermometer(){}
