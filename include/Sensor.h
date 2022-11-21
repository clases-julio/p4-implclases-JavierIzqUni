#include <string>
#include <vector>

#ifndef SENSOR_H 
#define	SENSOR_H
class Sensor{

public:
  static Sensor *Create(const std::string type);
  Sensor( std::string id = "0000", std::string type = "none", std::string magnitude = "-", bool active = true, int valPerMin = 1); /* default constructor */
  std::string getId();
  std::string getType();
  void setActive(bool);
  bool isActive();
  void setArea(std::string);
  std::string getArea();
  void setMagnitude(std::string magnitude);
  std::string getMagnitude();
  void setValPerMin(int valPerMin);
  int getValPerMin();
  virtual std::vector<int> requestData() = 0;
  virtual ~Sensor();

protected:
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