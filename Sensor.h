#include <string>
#include <vector>

#ifndef SENSOR_H 
#define	SENSOR_H
class Sensor{
public:
  Sensor(); /* basic constructor */
  Sensor( std::string = "0000",std::string = "none", bool = true ); /* default constructor */
  ~Sensor();
  std::string getId();
  void setActive(bool);
  bool isActive();
  std::string getType();
  void setArea(std::string);
  std::string getArea();
  std::vector<int> requestData();
  void setMagnitude(int);
  int getMagnitude();

private:
  std::string id;
  bool active;
  std::string type;
  std::string area;
  std::vector <int> data;
  int magnitude;

  void addNewData(int);
  void removeOldData(int);
};

#endif