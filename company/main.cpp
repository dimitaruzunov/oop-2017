#include <iostream>
#include "employee.h"

using std::cout;

int main() {
  Company company("HP", 42);
  Employee ivan("Ivan", 9604010001, &company, "Programmer");

  cout << ivan;

  return 0;
}