/**
 * @file CLLoginInterface.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "CLLoginInterface.h"

CLLoginInterface::CLLoginInterface(){}

/**
 * @brief Show the login screen messages in the command line
 * 
 */
void CLLoginInterface::showWelcomeMessage(){
  std::cout << "\u001b[2J\u001b[0;0H";
  printCenterFromFile("config/CLIWelcomeMessage.ascii", "green");
  std::cout << "\n\n\n";
  printCenter("Enter your employee number: ",5);
  std::cout << "\n\n\n";
  printCenter("Enter your NIF: ",8);
  std::cout << "\u001b[s";
}

/**
 * @brief Ask the user to input the employee number from the command line
 * 
 */
void CLLoginInterface::askEmployeeNumber(){
  std::cout << "\u001b[7C\u001b[3A";
  char * inputBuffer = new char[100];
  std::cin.getline(inputBuffer ,100);
  this->inputEmployeeNumber = inputBuffer;
  delete inputBuffer;
}

/**
 * @brief Default setter of employee number
 * @note This method is used when the user executes the main with the NIF and employee number
 * @param userNumber 
 */
void CLLoginInterface::askEmployeeNumber(const std::string & userNumber){
  this->inputEmployeeNumber = userNumber;
}

/**
 * @brief Ask the user to input the employee nif from the command line
 * 
 */
void CLLoginInterface::askNIF(){
  std::cout << "\u001b[u";
  char * inputBuffer = new char[100];
  std::cin.getline(inputBuffer ,100);
  this->inputNIF = inputBuffer;
  delete inputBuffer;
  std::cout << "\n\n\n";
}

/**
 * @brief Default setter of employee nif
 * @note This method is used when the user executes the main with the NIF and employee number
 * @param nif 
 */
void CLLoginInterface::askNIF(const std::string & nif){
  this->inputNIF = nif;
}

CLLoginInterface::~CLLoginInterface(){}