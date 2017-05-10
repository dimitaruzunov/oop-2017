//
// Created by Dimitar Uzunov on 5/10/17.
//

#ifndef BUILDING_BUILDING_H
#define BUILDING_BUILDING_H

#include <iostream>

using std::ostream;


class Building {
  double area;
  char* address;

  void copy(const Building& other);
  void erase();

protected:
  double height;

public:

  Building();
  Building(double height, double area, const char* address);
  Building(const Building& other);
  ~Building();

  Building& operator=(const Building& other);

  friend ostream& operator<<(ostream& os, const Building& building);
};


#endif //BUILDING_BUILDING_H
