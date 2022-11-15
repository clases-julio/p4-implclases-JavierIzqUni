#include "User.h"
#include <iostream>
#include <vector>

void setTerminalSize();
int getTerminalWidth();
int getTerminalHeight();

void printCenterFromFile(const std::string fileName, const std::string color = "none");
void printCenter(const std::string toPrint, const int padding = 0);
void printCenter(const std::string toPrint, const std::string color, const int padding = 0 );
void printRight(const std::string toPrint, const int padding = 0);
void printRight(const std::string toPrint, const std::string color, const int padding = 0 );
void printLeft(const std::string toPrint, const int padding = 0);
void printLeft(const std::string toPrint, const std::string color ,const int padding = 0);

void printColor(std::string, std::string = "none");
std::string setColor(std::string);

void startCustomTerminal(int);
std::vector<std::string> newCommand(User & user,std::string = "");
void clearCustomTerminal(int);

void moveCursor(int posX, int posY);
void printGraphic(const std::vector <int> &data, int valPerY = 1, int posX = 10, int posY = 10, int scale = 1);