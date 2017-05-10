#include <cstring>
#include "building.h"

Building::Building() {
  height = 0;
  area = 0;
  address = new char[1];
  address[0] = '\0';
}

Building::Building(double height, double area, const char* address) {
  this->height = height;
  this->area = area;

  this->address = new char[strlen(address) + 1];
  strcpy(this->address, address);
}

Building::Building(const Building& other) {
  copy(other);
}

Building::~Building() {
  erase();
}

Building& Building::operator=(const Building& other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

ostream& operator<<(ostream& os, const Building& building) {
  return os << building.area << ", " << building.address << '\n';
}

void Building::copy(const Building& other) {
  height = other.height;
  area = other.area;

  address = new char[strlen(other.address) + 1];
  strcpy(address, other.address);
}

void Building::erase() {
  delete[] address;
}
