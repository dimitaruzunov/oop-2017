//
// Created by Dimitar Uzunov on 5/10/17.
//

#include <cstring>
#include "house.h"

House::House() {
  floors = 0;
  host = new char[1];
  host[0] = '\0';
}

House::House(double height, double area, const char* address, int floors,
             const char* host) : Building(height, area, address) {
  this->floors = floors;

  this->host = new char[strlen(host) + 1];
  strcpy(this->host, host);
}

House::House(const House& other) : Building(other) {
  copy(other);
}

House::~House() {
  erase();
}

House& House::operator=(const House& other) {
  Building::operator=(other);

  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

double House::averageFloorHeight() const {
  return height / floors;
}

void House::copy(const House& other) {
  floors = other.floors;

  host = new char[strlen(other.host) + 1];
  strcpy(host, other.host);
}

void House::erase() {
  delete[] host;
}

ostream& operator<<(ostream& os, const House& house) {
  return os << (const Building&) house
            << house.floors << ", " << house.host << '\n';
}
