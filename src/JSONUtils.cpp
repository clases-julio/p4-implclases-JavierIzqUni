# include "JSONUtils.h"
#include <fstream>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>

std::string loadFrom(std::string filename, std::string dataName){
  std::ifstream file;
  file.open(filename);
  std::string line;
  int columns = 0;

  std::string tmp;
  std::vector<std::string> separatedInput;
  
  if ( file.is_open() ) {
    while ( file ) { // equivalent to myfile.good()
      tmp.clear();
      separatedInput.clear();
      std::getline (file, line);
      std::stringstream ss(line);
      while(getline(ss, tmp, ' ')){
        separatedInput.push_back(tmp);
      }
      if (separatedInput[0].compare(dataName) == 0) break;
    }
  }
  else {
    std::cout << "Couldn't open file\n";
  }

  // Reconstruct the dataValue
  std::string dataValue;
  for (int index = 2; index < separatedInput.size(); index++) {
    dataValue += separatedInput[index];
    if (index != separatedInput.size() -1) dataValue += " "; 
  }
  
  return dataValue;
}

std::string loadFrom(std::string filename){
  std::ifstream file;
  file.open(filename);
  std::string line;
  int columns = 0;

  std::string tmp;
  
  if ( file.is_open() ) {
    while ( file ) { // equivalent to myfile.good()
      std::getline (file, line);
      tmp += line + "\n";
    }
  }
  else {
    std::cout << "Couldn't open file\n";
  }
  
  return tmp;
}