#include "CLIUtils.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream>

int terminalWidth;
int terminalHeight;

void setTerminalSize(){
  system("tput cols > terminalSize.txt"); /* For height it is tput lines*/
  std::ifstream terminalSize;
  terminalSize.open("terminalSize.txt");
  std::string line;
  int columns = 0;
  
  if ( terminalSize.is_open() ) {
    while ( terminalSize ) { // equivalent to myfile.good()
      std::getline (terminalSize, line);
      columns = stoi(line);
      break;
    }
  }
  else {
    std::cout << "Couldn't open file\n";
  }
  terminalSize.close();
  terminalWidth = columns;

  system("tput lines > terminalSize.txt");
  terminalSize.open("terminalSize.txt");
  int lines = 0;
  
  if ( terminalSize.is_open() ) {
    while ( terminalSize ) { // equivalent to myfile.good()
      std::getline (terminalSize, line);
      lines = stoi(line);
      break;
    }
  }
  else {
    std::cout << "Couldn't open file\n";
  }
  terminalHeight = lines;
};

std::string join(std::vector<std::string> v, char c) {
  std::string s;
  s.clear();
  for (std::vector<std::string>::const_iterator p = v.begin();
        p != v.end(); ++p) {
      s += *p;
      if (p != v.end() - 1)
        s += c;
  }
  return s;
}

/**
 * @brief Print the contents of the file in the center
 * 
 * @param fileName 
 * @param color 
 */
void printCenterFromFile(std::string fileName, std::string color){
  std::ifstream configFile;
  configFile.open(fileName);
  std::string line;
  if ( configFile.is_open() ) {
    while ( configFile ) { // equivalent to myfile.good()
    std::getline (configFile, line);
    std::cout << std::setw((terminalWidth-line.size())/2);
    printColor(line,color);
    std::cout << "\n";
    }
  }
  else {
  std::cout << "Couldn't open file\n";
  }
};

/**
 * @brief Print the string in the center
 * 
 * @param toPrint 
 * @param reservedCharacters 
 * @param color 
 */
void printCenter(std::string toPrint, int reservedCharacters, std::string color){
  std::cout << std::setw((terminalWidth-toPrint.size()-reservedCharacters)/2);
  printColor(toPrint,color);
}

/**
 * @brief Print the string to the terminal in the given color
 * 
 * @param toPrint 
 * @param color 
 */
void printColor(std::string toPrint, std::string color){
  std::string colorCode = setColor(color);
  std::string noColor = "\u001b[0m";
  std::cout << colorCode << toPrint << noColor;
}

/**
 * @brief Set the Color to print
 * 
 * @param color 
 * @return std::string 
 */
std::string setColor(std::string color){
  if (color.compare("grey") == 0) return "\u001b[1;30m";
  if (color.compare("red") == 0) return "\u001b[1;31m";
  if (color.compare("green") == 0) return "\u001b[1;32m";
  if (color.compare("yellow") == 0) return "\u001b[1;33m";
  if (color.compare("blue") == 0) return "\u001b[1;34m";
  if (color.compare("purple") == 0) return "\u001b[1;35m";
  if (color.compare("cyan") == 0) return "\u001b[1;36m";
  if (color.compare("white") == 0) return "\u001b[1;37m";
  return "\u001b[0m";
}

void startCustomTerminal(int terminalSize){
  std::cout << "\u001b[" << terminalHeight - 1 - terminalSize << ";0H";
  std::cout << std::setfill('-')<<std::setw(terminalWidth) << "\n";
}

void clearCustomTerminal(int terminalSize){
  std::cout << "\u001b[" << terminalHeight - terminalSize << ";0H" << "\u001b[0J";
}

std::vector<std::string> newCommand(User user, std::string currentSensor){
  std::cout << user.getName() << "@jveh"<< ":~";
  if (currentSensor.compare("") != 0) std::cout << "/";
  std::cout << currentSensor << "> ";

  char input[100] = {0};
  std::cin.getline(input,100);
  std::string inputString = input;

  std::string tmp;
  std::stringstream ss(inputString);
  std::vector<std::string> separatedInput;

  while(getline(ss, tmp, ' ')){
      separatedInput.push_back(tmp);
  }

  return separatedInput;
}