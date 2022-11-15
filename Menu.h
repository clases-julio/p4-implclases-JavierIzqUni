#include <iostream>
#include <vector>
#include "Sensor.h"

#ifndef MENU_H
#define	MENU_H

class Menu{
  public:
    static Menu *Create(const std::string type = "CLI");
    Menu(); /* basic constructor */
    virtual void show(std::vector <Sensor *> ) = 0;
    virtual void show(Sensor *) = 0;
    virtual ~Menu();
};

#endif