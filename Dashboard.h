#include <string>
#include <vector>

#ifndef DASHBOARD_H
#define	DASHBOARD_H

class Dashboard{
public:
  Dashboard(); /* basic constructor */
  ~Dashboard();
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
  bool active;
  std::string type;
  std::string area;
  std::vector <int> data;
  int magnitude;
};

#endif