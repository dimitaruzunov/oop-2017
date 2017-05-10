//
// Created by Dimitar Uzunov on 5/10/17.
//

#ifndef BUILDING_HOUSE_H
#define BUILDING_HOUSE_H

#include "building.h"

class House : public Building {
  int floors;
  char* host;

  void copy(const House& other);
  void erase();

public:

  House();
  House(double height, double area, const char* address, int floors, const char* host);
  House(const House& other);
  ~House();

  House& operator=(const House& other);

  double averageFloorHeight() const;

  friend ostream& operator<<(ostream& os, const House& house);
};


#endif //BUILDING_HOUSE_H
