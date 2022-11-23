/**
 * @file CLMenu.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of CLMenu.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Menu.h"
#include "CLIUtils.h"

#ifndef CLMENU_H
#define	CLMENU_H

class CLMenu : public Menu{
  public:
    CLMenu(); /* basic constructor */
    void show(std::vector <Sensor *> );
    void show(Sensor *sensor);

  protected:
    void clearMenu();
};

#endif