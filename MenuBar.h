#include <string>
#include <vector>

#ifndef MENUBAR_H
#define	MENUBAR_H

class MenuBar{
  public:
    static MenuBar *Create(const std::string type = "CLI");
    MenuBar(); /* basic constructor */
    virtual ~MenuBar();
    virtual void show() = 0;
    void setUserName(std::string userName);
    void setCurrentMenu(std::string currentMenu);
  protected:
    std::string userName;
    std::string currentMenu;
};

#endif