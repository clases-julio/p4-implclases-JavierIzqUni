/**
 * @file CLInterface.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "CLInterface.h"

/**
 * @brief Create a new Interface for the command line
 * @note Also gets the terminal size 
 */
CLInterface::CLInterface(){
  setTerminalSize();
};

/**
 * @brief Controls the login interface for the command line
 * 
 * @param tries Number of tries to login
 * @note If exceeded the number of tries, then the program will exit
 */
void CLInterface::login(int tries){
  if (tries == 0){
    loginInterface = LoginInterface::Create();
    this->loginInterface = loginInterface;
  }
  if (tries == 5) std::exit(0);

  this->loginInterface->showWelcomeMessage();
  this->loginInterface->askEmployeeNumber();
  this->loginInterface->askNIF();
  usleep(2 * 1000000);
  if (this->loginInterface->checkUser()){
    printCenter("Login successful" );
    std::cout << "\n";
    usleep(1 * 1000000);
    system("clear");
    tries = 0;
    delete this->loginInterface;
  } else {
    printCenter("Failed login\n", "red");
    usleep(1 * 1000000);
    tries++;
    login(tries);
  }
}