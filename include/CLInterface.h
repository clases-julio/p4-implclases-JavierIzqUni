/**
 * @file CLInterface.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of CLInterface.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Interface.h"
#include "CLIUtils.h"
#include <unistd.h>

#ifndef CLINTERFACE_H 
#define	CLINTERFACE_H 

class CLInterface : public Interface{
  public:
    CLInterface(); /* basic constructor */
    void login(int tries);
    void loadMenu();
};

#endif