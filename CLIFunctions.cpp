#include "CLIFunctions.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream>

int getTerminalWidth(){
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
  return columns;
};

void printCenterFromFile(int terminalWidth, std::string fileName){
  std::ifstream configFile;
  configFile.open(fileName);
  std::string line;
  if ( configFile.is_open() ) {
    while ( configFile ) { // equivalent to myfile.good()
    std::getline (configFile, line);
    std::cout << std::setw((terminalWidth-line.size())/2) <<""<< line << '\n';
    }
  }
  else {
  std::cout << "Couldn't open file\n";
  }
};

void printCenter(int terminalWidth, std::string toPrint, int reservedCharacters){
  std::cout << std::setw((terminalWidth-toPrint.size()-reservedCharacters)/2) <<""<< toPrint;
}