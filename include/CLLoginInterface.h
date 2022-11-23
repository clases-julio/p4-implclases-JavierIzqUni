/**
 * @file CLLoginInterface.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of CLLoginInterface.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "LoginInterface.h"
#include "CLIUtils.h"

#ifndef CLLOGININTERFACE_H
#define	CLLOGININTERFACE_H

class CLLoginInterface : public LoginInterface{
  public:
    CLLoginInterface(); /* basic constructor */
    void showWelcomeMessage();
    void askEmployeeNumber();
    void askEmployeeNumber(const std::string  & userNumber);
    void askNIF();
    void askNIF(const std::string & nif);
    ~CLLoginInterface();
};

#endif