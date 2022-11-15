#include <string>
#include <vector>

#ifndef SENSOR_H 
#define	SENSOR_H
class Sensor{
public:
  Sensor( std::string id = "0000", std::string type = "none", std::string magnitude = "-", bool active = true, int valPerMin = 1); /* default constructor */
  ~Sensor();
  std::string getId();
  void setActive(bool);
  bool isActive();
  std::string getType();
  void setArea(std::string);
  std::string getArea();
  std::vector<int> requestData();
  void setMagnitude(std::string magnitude);
  std::string getMagnitude();
  void setValPerMin(int valPerMin);
  int getValPerMin();

private:
  std::string id;
  bool active;
  std::string type;
  std::string area;
  std::vector <int> data;
  std::string magnitude;
  int valPerMin;

  void addNewData(int);
  void removeOldData(int);
};

#endif