#include <string>
#include <vector>
#include "Sensor.h"
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
    void addNewSensor(std::string id);
    void deleteSensor(std::string id);
    void cleanSensor();
    void exit();
    void logout();
    bool canExit();

  protected:
    std::vector <Sensor *> sensor;
    std::vector <std::vector <Sensor *>> mainMenu;
    int mainMenuIndex;
    MenuBar * menuBar;
    Menu * menu;
    User user;
    std::string currentInterface;
    std::string lastInterface;
    Sensor * currentSensor;
    bool allowedToExit;
};

#endif