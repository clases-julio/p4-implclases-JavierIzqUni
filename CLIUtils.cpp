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

void printCenter(std::string toPrint, int reservedCharacters, std::string color){
  std::cout << std::setw((terminalWidth-toPrint.size()-reservedCharacters)/2);
  printColor(toPrint,color);
}

void printColor(std::string toPrint, std::string color){
  std::string colorCode = setColor(color);
  std::string noColor = "\u001b[0m";
  std::cout << colorCode << toPrint << noColor;
}

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

void startCustomTerminal(){
  std::cout << "\u001b[" << terminalHeight - 11 - 2 << "B";
  std::cout << std::setfill('-')<<std::setw(terminalWidth) << "\n";
  std::cout << "> ";
  std::string i;
  std::cin >> i;
}