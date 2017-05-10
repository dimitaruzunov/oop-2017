#include <iostream>
#include "house.h"

using std::cout;

const House& findMostSpaciousHouse(House houses[], int housesCount) {
  House& mostSpaciousHouse = houses[0];

  for (int i = 1; i < housesCount; ++i) {
    if (houses[i].averageFloorHeight() > mostSpaciousHouse.averageFloorHeight()) {
      mostSpaciousHouse = houses[i];
    }
  }

  return mostSpaciousHouse;
}

int main() {
  House houses[] = {
    House(50, 300, "James Baucher 5", 5, "FMI"),
    House(70, 800, "James Baucher 10", 9, "House"),
  };

  cout << findMostSpaciousHouse(houses, 2) << '\n';

  return 0;
}