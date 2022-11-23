/**
 * @file Dashboard.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of Dashboard.cpp
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "User.h"
#include "MenuBar.h"
#include "Menu.h"


#ifndef DASHBOARD_H
#define	DASHBOARD_H

class Dashboard{
  public:
    static Dashboard *Create(const std::string type = "CLI");
    Dashboard(); /* basic constructor */
    virtual ~Dashboard();
    virtual void showMainMenu() = 0;
    void changeInterface(std::string newInterface = "");
    void addToMainMenu();
    void addToMainMenu(Sensor *sensor);
    void moveWindowMainMenu(int n = 1);
    void changeCurrentSensorInfo(std::string toChange, std::string newValue);
    void setUser(User user);
    void addNewSensor(std::string type);
    void deleteSensor(std::string id);
    void cleanSensor();
    void exit();
    void logout();
    bool canExit();

  protected:
    /**
     * @brief Vector of all the vectors in the dashboard
     */
    std::vector <Sensor *> sensor;
    /**
     * @brief Vetor that contains the pages of the main Menu
     */
    std::vector <std::vector <Sensor *>> mainMenu;
    /**
     * @brief Current page of the main Menu 
     */
    int mainMenuIndex;
    MenuBar * menuBar;
    Menu * menu;
    User user;
    /**
     * @brief Current interface, can be a sensor ID or the main menu (..)
     */
    std::string currentInterface;
    /**
     * @brief Last interface, can be a sensor ID or the main menu (..)
     */
    std::string lastInterface;
    /**
     * @brief If the currentInterface is a sensor then the value would be that sensor, if not the value is nullptr
     */
    Sensor * currentSensor;
    bool allowedToExit;
};

#endif