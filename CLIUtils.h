#include <iostream>
#include <vector>

void setTerminalSize();
std::string join(std::vector<std::string>, char);
void printCenterFromFile(std::string, std::string = "none");
void printCenter(std::string, int = 0, std::string = "none");
void printColor(std::string, std::string = "none");
void printMenu(std::string, std::string, std::string);
void startCustomTerminal();
std::string setColor(std::string);