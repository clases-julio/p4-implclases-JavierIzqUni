/**
 * @file CLDashboard.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of CLDashboard.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Dashboard.h"
#include "CLIUtils.h"

#ifndef CLDASHBOARD_H
#define	CLDASHBOARD_H

class CLDashboard : public Dashboard{
  public:
    CLDashboard(); /* basic constructor */
    void showMainMenu();
    ~CLDashboard();
  protected:
    void changeMainMenu(int n);
    void readCommand();
    void listSensor();
    void helpCommand(std::string command = "");
    void errorCommand(std::string command = "");
    void permissionError();
};

#endif